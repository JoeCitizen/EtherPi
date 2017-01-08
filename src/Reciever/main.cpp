#include <wiringPi.h>
#include <iostream>
#include "..\Common\Common.h"

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// we have to use BCM numbering when initializing with wiringPiSetupSys
// when choosing a different pin number please use the BCM numbering, also
// update the Property Pages - Build Events - Remote Post-Build Event command 
// which uses gpio export for setup for wiringPiSetupSys

namespace EtherPi
{
	int main(void)
	{
		wiringPiSetupSys();

		pinMode(GPIO::Data_0, INPUT);

		while (true)
		{
			int value = digitalRead(GPIO::Data_0);

			std::cout << value;
		}
		return 0;
	}
}