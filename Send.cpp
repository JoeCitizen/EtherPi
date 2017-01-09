#include <Common.h>
#include <Send.h>

namespace EtherPi
{
	void Send::Init()
	{
		wiringPiSetupGpio();

		pinMode(GPIO::Data_0, OUTPUT);
		pinMode(GPIO::Data_1, OUTPUT);
		pinMode(GPIO::Data_Ready, OUTPUT);
		
		pinMode(GPIO::Data_Acknowledge, INPUT);
		pullUpDnControl(GPIO::Data_Acknowledge, PUD_DOWN);
		
		TurnOffDataReady();
	}
	
	void Send::Run()
	{
		PacketHeader header = {};
		header.m_PacketLength = 0xDEADBEEF;
		
		SendBytes((uint8_t*)&header, sizeof(header));
	}
	
	void Send::SendBytes(uint8_t* data, size_t length)
	{
		for (size_t byte = 0; byte < length; byte++)
		{
			uint8_t value = data[byte];
			uint8_t mask = 1;
			
			for (size_t nibble = 0; nibble < 4; nibble++)
			{
				std::cout << "write" << std::endl;
				
				digitalWrite(GPIO::Data_0, (value & mask) ? HIGH : LOW);
				mask <<= 1;
				digitalWrite(GPIO::Data_1, (value & mask) ? HIGH : LOW);
				mask <<= 1;
				
				IndicateDataReady();
				delay(500);
				WaitForAcknowldgement();
				TurnOffDataReady();			
				delay(500);
			}
		}	
	}
	
	void Send::WaitForAcknowldgement()
	{
		int ack = 0;
		do
		{
			ack = digitalRead(GPIO::Data_Acknowledge);
		} while(!ack);
	}
	
	void Send::IndicateDataReady()
	{
		digitalWrite(GPIO::Data_Ready, HIGH);
	}
	
	void Send::TurnOffDataReady()
	{
		digitalWrite(GPIO::Data_Ready, LOW);
	}
}
