#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		_capacity;
		int		_oldestIndex;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void addContact(Contact newContact);
		Contact *getContact(int index);
		int getCapacity(void);
};

#endif