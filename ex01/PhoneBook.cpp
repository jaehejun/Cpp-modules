#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _capacity(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(Contact newContact)
{
    if (_capacity < 8)
    {
        contacts[_capacity] = newContact;
        _capacity++;
    }
    else
    {
        contacts[_oldestIndex] = newContact;
        _oldestIndex++;
        if (_oldestIndex == 8)
            _oldestIndex = 0;
    }
}

Contact *PhoneBook::getContact(int index)
{
    if (index < 0 || index >= _capacity)
    {
        return NULL;
    }
    else
    {
        return &contacts[index];
    }
}

int	PhoneBook::getCapacity(void)
{
	return _capacity;
}