#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string firstName)
{
    _firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    _lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    _darkestSecret = darkestSecret;
}

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
