#include "addContact.hpp"

void addContact(PhoneBook &phoneBook)
{
	Contact newContact;
	std::string info;

	std::cout << "Enter first name" << std::endl;
    std::getline(std::cin, info);
    newContact.setFirstName(info);

    std::cout << "Enter last name" << std::endl;
    std::getline(std::cin, info);
    newContact.setLastName(info);

    std::cout << "Enter nickname" << std::endl;
    std::getline(std::cin, info);
    newContact.setNickname(info);

    std::cout << "Enter phone number" << std::endl;
    std::getline(std::cin, info);
    newContact.setPhoneNumber(info);

    std::cout << "Enter darkest secret" << std::endl;
    std::getline(std::cin, info);
    newContact.setDarkestSecret(info);

    phoneBook.addContact(newContact);
}