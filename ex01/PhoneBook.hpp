#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdio>
#include <iomanip>
#include <iostream>

class PhoneBook
{
  private:
    Contact _contacts[8];
    int _capacity;
    int _oldestIndex;

  public:
    PhoneBook(void);
    ~PhoneBook(void);

    Contact getContact(int index);
    int getCapacity();

    void saveNewContact();
    bool getInfo(std::string &info);
    bool isAllSpace(std::string info);

    void displayContact();
    std::string displayFormat(std::string field);
    bool getIndex(int &searchIndex);
};

#endif