#include "Contact.hpp"

Contact::Contact(void) : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
}

Contact::~Contact(void)
{
}

//void Contact::setFirstName(std::string firstName)
//{
//    _firstName = firstName;
//}

//void Contact::setLastName(std::string lastName)
//{
//    _lastName = lastName;
//}

//void Contact::setNickname(std::string nickname)
//{
//    _nickname = nickname;
//}

//void Contact::setPhoneNumber(std::string phoneNumber)
//{
//    _phoneNumber = phoneNumber;
//}

//void Contact::setDarkestSecret(std::string darkestSecret)
//{
//    _darkestSecret = darkestSecret;
//}

std::string Contact::getFirstName(void)
{
    return _firstName;
}

std::string Contact::getLastName(void)
{
    return _lastName;
}

std::string Contact::getNickname(void)
{
    return _nickname;
}

std::string Contact::getPhoneNubmer(void)
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret(void)
{
    return _darkestSecret;
}

void    Contact::completeFields(void)
{
    std::string info;

    std::cout << "Enter first name" << std::endl;
    std::getline(std::cin, info);
    _firstName = info;

    std::cout << "Enter last name" << std::endl;
    std::getline(std::cin, info);
    _lastName = info;

    std::cout << "Enter nickname" << std::endl;
    std::getline(std::cin, info);
    _nickname = info;

    std::cout << "Enter phone number" << std::endl;
    std::getline(std::cin, info);
    _phoneNumber = info;

    std::cout << "Enter darkest secret" << std::endl;
    std::getline(std::cin, info);
    _darkestSecret = info;
}