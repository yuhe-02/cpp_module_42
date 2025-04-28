#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Contact.hpp"
#define MAX_ELEMENT 8
class PhoneBook
{
  private:
    int m_registerNum;
    Contact contact[MAX_ELEMENT];
    void _shiftLeft();
    bool _showContacts();

  public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact();
};

bool isNum(const std::string &str);
#endif