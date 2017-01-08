#include <wiringPi.h>
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

		pinMode(GPIO::Data_0, OUTPUT);

		while (true)
		{
			digitalWrite(GPIO::Data_0, HIGH);  // On
			delay(500); // ms
			digitalWrite(GPIO::Data_0, LOW);  // Off
			delay(500);
		}
		return 0;
	}
}
