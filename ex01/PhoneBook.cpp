#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _capacity(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

Contact PhoneBook::getContact(int index)
{
    return _contacts[index];
}

int PhoneBook::getCapacity()
{
    return _capacity;
}

void PhoneBook::saveNewContact()
{
    Contact newContact;
    std::string info;

    std::cout << "Enter first name" << std::endl;
    if (getInfo(info) == false)
        return;
    newContact.setFirstName(info);

    std::cout << "Enter last name" << std::endl;
    if (getInfo(info) == false)
        return;
    newContact.setLastName(info);

    std::cout << "Enter nickname" << std::endl;
    if (getInfo(info) == false)
        return;
    newContact.setNickname(info);

    std::cout << "Enter phone number" << std::endl;
    if (getInfo(info) == false)
        return;
    newContact.setPhoneNumber(info);

    std::cout << "Enter darkest secret" << std::endl;
    if (getInfo(info) == false)
        return;
    newContact.setDarkestSecret(info);

    if (_capacity < 8)
    {
        _contacts[_capacity] = newContact;
        _capacity++;
    }
    else
    {
        _contacts[_oldestIndex] = newContact;
        _oldestIndex++;
        if (_oldestIndex == 8)
            _oldestIndex = 0;
    }
}

bool PhoneBook::isAllSpace(std::string info)
{
    for (size_t index = 0; index < info.length(); index++)
    {
        if (!std::isspace(info[index]))
            return false;
    }
    return true;
}

bool PhoneBook::getInfo(std::string &info)
{
    std::getline(std::cin, info);
    if (std::cin.fail())
    {
        std::cin.clear();
        std::clearerr(stdin);
        return false;
    }
    if (info.empty() || isAllSpace(info))
    {
        std::cout << "Field is empty!" << std::endl;
        return false;
    }
    return true;
}

void PhoneBook::displayContact()
{
    std::cout << std::setw(10) << "Index"
              << "|";
    std::cout << std::setw(10) << "First name"
              << "|";
    std::cout << std::setw(10) << "Last name"
              << "|";
    std::cout << std::setw(10) << "Nickname"
              << "|" << std::endl;
    for (int index = 0; index < _capacity; index++)
    {
        std::cout << std::setw(10) << index << "|";
        std::cout << std::setw(10) << displayFormat(_contacts[index].getFirstName()) << "|";
        std::cout << std::setw(10) << displayFormat(_contacts[index].getLastName()) << "|";
        std::cout << std::setw(10) << displayFormat(_contacts[index].getNickname()) << "|" << std::endl;
    }

    std::cout << "Enter index" << std::endl;
    int searchIndex;

    if (getIndex(searchIndex) == false)
        return;

    std::cout << "First Name: " << _contacts[searchIndex].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[searchIndex].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[searchIndex].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[searchIndex].getPhoneNubmer() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[searchIndex].getDarkestSecret() << std::endl;
}

std::string PhoneBook::displayFormat(std::string field)
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

bool PhoneBook::getIndex(int &searchIndex)
{
    std::cin >> searchIndex;
    std::cin.ignore(1000, '\n');

    if (std::cin.fail())
    {
        if (!std::cin.eof())
        {
            std::cout << "Not a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        std::cin.clear();
        std::clearerr(stdin);
        return false;
    }

    if (searchIndex >= _capacity)
    {
        std::cout << "Invalid index!" << std::endl;
        //std::cin.ignore(1000, '\n'); // 버퍼 비워서 개행문자 지움(invalid index + '\n' 입력했기 때문에)
        return false;
    }
    return true;
}
