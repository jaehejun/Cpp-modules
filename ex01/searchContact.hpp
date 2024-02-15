#ifndef SEARCHCONTACT_HPP
#define SEARCHCONTACT_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

std::string formatContactField(std::string field);
void searchContact(PhoneBook &phoneBook);

#endif