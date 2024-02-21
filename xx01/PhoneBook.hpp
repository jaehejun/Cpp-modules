#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_capacity;
		int		_oldestIndex;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void addContact(Contact newContact);
		void searchContact(PhoneBook phonebook);
		Contact *getContact(int index);
		int getCapacity(void);
};

#endif