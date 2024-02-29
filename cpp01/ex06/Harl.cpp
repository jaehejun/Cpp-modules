#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "Debug blah blah" << std::endl;
}

void Harl::info()
{
   std::cout << "Info blah blah" << std::endl;
}

void Harl::warning()
{
	std::cout << "Warning blah blah" << std::endl;
}

void Harl::error()
{
	std::cout << "Error blah blah" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string commands[4];
	void (Harl::*functions[4])();

	commands[0] = "DEBUG";
	commands[1] = "INFO";
	commands[2] = "WARNING";
	commands[3] = "ERROR";

	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	
	for (int i = 0; i < 4; i++)
	{
		if (level == commands[i])
		{
			switch (4 - i)
			{
				case 4:
					(this->*functions[0])();
				case 3:
					(this->*functions[1])();
				case 2:
					(this->*functions[2])();
				case 1:
					(this->*functions[3])();
			}
			return ;
		}
	}
}