#ifndef ADDCONTACT_HPP
# define ADDCONTACT_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

std::string formatContactField(std::string field);
void addContact(PhoneBook &phoneBook);

#endif