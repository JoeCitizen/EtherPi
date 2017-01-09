#pragma once
#include <Common.h>

namespace EtherPi
{
	class Send
	{
	public:

		void Init();
		void Run();

	private:
	
		void SendBytes(uint8_t* data, size_t length);
		void WaitForAcknowldgement();
		void IndicateDataReady();
		void TurnOffDataReady();	
	};
}
