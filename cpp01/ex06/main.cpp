#include "Harl.hpp"

int main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 0;
	}

	Harl harl;
	std::string command = argv[1];
	harl.complain(command);
	return 0;
}