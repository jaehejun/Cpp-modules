#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "addContact.hpp"
#include "searchContact.hpp"

int main(void)
{
    PhoneBook phoneBook;

    while (true)
    {
    	std::string command;
        std::cout << "Enter command(ADD, SEARCH, EXIT): " << std::endl;
        std::getline(std::cin, command);

        //if (std::cin.fail() == true)
        //{
        //    if (std::cin.eof() == true)
        //    {
        //        std::cout << "EOF detected. Program exiting..." << std::endl;
        //        break;
        //    }
        //    else
        //    {
        //        std::cerr << "Input error. Try again..." << std::endl;
        //        std::cin.clear();
        //        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //    	continue ;
        //    }
        //}

        if (command == "EXIT")
        {
            break;
        }
        else if (command == "ADD")
        {
			addContact(phoneBook);
        }
        else if (command == "SEARCH")
        {
            searchContact(phoneBook);
        }
        else
        {
            continue ;
        }
    }
    return 0;
}