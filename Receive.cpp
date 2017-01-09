#include <Common.h>
#include <Receive.h>

namespace EtherPi
{
	void Receive::Init()
	{
		wiringPiSetupGpio();

		pinMode(GPIO::Data_0, INPUT);
		pinMode(GPIO::Data_1, INPUT);
		pinMode(GPIO::Data_Ready, INPUT);
		pinMode(GPIO::Data_Acknowledge, OUTPUT);
		
		pullUpDnControl(GPIO::Data_0, PUD_DOWN);
		pullUpDnControl(GPIO::Data_1, PUD_DOWN);
		pullUpDnControl(GPIO::Data_Ready, PUD_DOWN);
		
		TurnOffAcknowldge();
	}
	
	void Receive::Run()
	{
		PacketHeader header = {};
		ReadBytes((uint8_t*)&header, sizeof(header));
		
		
		std::cout << header.m_PacketLength << std::endl;
	}
	
	void Receive::WaitForData()
	{
		int dataReady = 0;
		do
		{
			dataReady = digitalRead(GPIO::Data_Ready);
		} while(!dataReady);
	}
	
	void Receive::ReadBytes(uint8_t* buffer, size_t numBytes)
	{	
		for (size_t byte = 0; byte < numBytes; byte++)
		{
			uint8_t value = 0;
			uint8_t bitIndex = 0;
					
			for (size_t nibble = 0; nibble < 4; nibble++)
			{
				std::cout << "read" << std::endl;
				
				WaitForData();
				{
					int bit0 = digitalRead(GPIO::Data_0);
					int bit1 = digitalRead(GPIO::Data_1);
					
					bit0 <<= bitIndex;
					value |= bit0;
					bitIndex++;
					
					bit1 <<= bitIndex;
					value |= bit1;
					bitIndex++;
				}
				AcknowledgeSender();			
				delay(500);
				TurnOffAcknowldge();
			}
			
			buffer[byte] = value;		
		}
	}
	
	void Receive::AcknowledgeSender()
	{
		digitalWrite(GPIO::Data_Acknowledge, HIGH);
	}
	
	void Receive::TurnOffAcknowldge()
	{
		digitalWrite(GPIO::Data_Acknowledge, LOW);
	}
}
