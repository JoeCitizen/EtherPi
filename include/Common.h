#pragma once 
#include <stdint.h>
#include <iostream>
#include <string>
#include <wiringPi.h>

namespace EtherPi
{
	namespace GPIO
	{
		static const uint32_t Data_0 = 17;
		static const uint32_t Data_1 = 27;
		
		static const uint32_t Data_Ready = 22;
		static const uint32_t Data_Acknowledge = 23;
	}
	
	struct PacketHeader
	{
		uint32_t m_PacketLength;
	};
}
