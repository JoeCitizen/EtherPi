#include <Common.h>
#include <Send.h>
#include <Receive.h>

int SendFile(char* filename)
{
	EtherPi::Send sender;
	sender.Init();
	sender.Run();
	
	return 0;
}

int ReceiveFile(char* filename)
{
	EtherPi::Receive receiver;
	receiver.Init();
	receiver.Run();
	
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc != (2 + 1))
	{
		std::cout << "Need a command line" << std::endl;
		return -1;
	}
	
	int status = 0;
	
	std::string modeCommandLine(argv[1]);
	
	if(modeCommandLine.compare("in") == 0)
	{		
		status = ReceiveFile(argv[2]);
	}
	else if (modeCommandLine.compare("out") == 0)
	{		
		status = SendFile(argv[2]);
	}
	else
	{
		std::cout << "Invalid Mode! use: in Or out" << std::endl;
		status = -1;
	}
	
	return status;
}
