#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _capacity(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::setContacts(Contact newContact)
{
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

Contact PhoneBook::getContact(int index)
{
    return _contacts[index];
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

    setContacts(newContact);
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
    if (std::cin.eof())
    {
        if (!std::cin.fail())
        {
            std::cout << std::endl;
        }
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
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;


    for (int index = 0; index < _capacity; index++)
    {
        std::cout << std::setw(10) << index << "|";
        std::cout << std::setw(10) << displayFormat(getContact(index).getFirstName()) << "|";
        std::cout << std::setw(10) << displayFormat(getContact(index).getLastName()) << "|";
        std::cout << std::setw(10) << displayFormat(getContact(index).getNickname()) << "|" << std::endl;
    }

    std::cout << "Enter index" << std::endl;
    int searchIndex;

    if (getIndex(searchIndex) == false)
        return;

    std::cout << "First Name: " << getContact(searchIndex).getFirstName() << std::endl;
    std::cout << "Last Name: " << getContact(searchIndex).getLastName() << std::endl;
    std::cout << "Nickname: " << getContact(searchIndex).getNickname() << std::endl;
    std::cout << "Phone Number: " << getContact(searchIndex).getPhoneNubmer() << std::endl;
    std::cout << "Darkest Secret: " << getContact(searchIndex).getDarkestSecret() << std::endl;
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
// cin.eof()
// eof
// a + eof    //cin.fail()
// val + eof
// inval + eof

// a         // cin.fail()
// val
// inval

    if (std::cin.eof()) // int + eof, eof -> int값은 searchindex에 담기고, eof만 남아있어 True반환
    {
        std::cin.clear();
        std::clearerr(stdin);
        std::cout << std::endl;
        return false;
    }

    else if (std::cin.fail()) // !int + eof, !int -> !int값이 버퍼에 남아있음
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');   // !int를 비우고 eof가 있다면 ignore로 읽어오다가 eof를 만남
        if (std::cin.eof())
        {
            std::cin.clear();
            std::clearerr(stdin);
            std::cout << std::endl;
            return false;
        }
        std::cout << "Not a number!" << std::endl; // eof가 없는 경우 : 버퍼는 비어있음
        return false;
    }

    else if (searchIndex >= _capacity) // int값인데 index 범위 벗어남
    {
        std::cout << "Invalid index!" << std::endl;
        std::cin.ignore(1000, '\n'); // 개행문자 전까지 비우고 개행문자 이후부터 다시 읽도록(버퍼가 모두 비워짐)
        return false;
    }

    else // 유효 index
    {
        std::cin.ignore(1000, '\n'); // 개행문자 무시
        return true;
    }
}
