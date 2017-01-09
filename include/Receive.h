#pragma once
#include <Common.h>

namespace EtherPi
{
	class Receive
	{
	public:

		void Init();
		
		void Run();

	private:
		void ReadBytes(uint8_t* buffer, size_t numBytes);
	
		void WaitForData();
		void AcknowledgeSender();
		
		void TurnOffAcknowldge();
		
	};
}
