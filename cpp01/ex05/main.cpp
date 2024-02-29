#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string command;

	while (1)
	{
		std::getline(std::cin, command);
		harl.complain(command);
	}
	return 0;
}