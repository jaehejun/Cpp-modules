#include "searchContact.hpp"

std::string formatContactField(std::string field)
{
    if (field.length() > 10)
    {
        return field.substr(0, 9) + ".";
    }
    else
    {
        return field;
    }
}

void	searchContact(PhoneBook &phoneBook)
{
	for (int index = 0; index < phoneBook.getCapacity(); index++)
    {
        Contact *contact = phoneBook.getContact(index);
        std::cout << std::setw(10) << index << "|";
        std::cout << std::setw(10) << formatContactField(contact->getFirstName()) << "|";
        std::cout << std::setw(10) << formatContactField(contact->getLastName()) << "|";
        std::cout << std::setw(10) << formatContactField(contact->getNickname()) << "|" << std::endl;
	}

    int index;
    std::cout << "Enter index" << std::endl;
    std::cin >> index;
    
    while (std::cin.fail() == true)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, Enter a number" << std::endl;
        std::cin >> index;
    }

    if (index < 0 || index >= phoneBook.getCapacity())
    {
        std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
    else
    {
        Contact *contact = phoneBook.getContact(index);
        std::cout << "First Name: " << contact->getFirstName() << std::endl;
        std::cout << "Last Name: " << contact->getLastName() << std::endl;
        std::cout << "Nickname: " << contact->getNickname() << std::endl;
        std::cout << "Phone Number: " << contact->getPhoneNubmer() << std::endl;
        std::cout << "Darkest Secret: " << contact->getDarkestSecret() << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}