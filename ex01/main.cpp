#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command(ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command);

		if (std::cin.fail() == true)
		{
			 if (std::cin.eof() == true)
			 {
				std::cout << "EOF detected. Program exiting..." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				//std::cin.eof() = false;
			 }
			 else
			 {
				std::cerr << "Input error. Try again..." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			 }
			 continue;
		}


		
	}

	return 0;
}