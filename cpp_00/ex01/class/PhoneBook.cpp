#include "PhoneBook.hpp"

bool isNum(const std::string &str)
{
    if (str.empty())
    {
        return (false);
    }
    if (str[0] == '0' && str.length() > 1)
    {
        return (false);
    }
    for (int i = 0; (char)str[i] != '\0'; i++)
    {
        if (i == 0 && (char)str[i] == '-')
        {
            continue;
        }
        if (!std::isdigit((char)str[i]))
        {
            return (false);
        }
    }
    return (true);
}

PhoneBook::PhoneBook()
{
    this->m_registerNum = 0;
}
PhoneBook::~PhoneBook() {}

bool PhoneBook::_showContacts()
{
    int i;
    std::string firstName;
    std::string lastName;
    std::string nickName;

    i = 0;
    if (this->m_registerNum == 0)
    {
        std::cout << "No entry" << std::endl;
        return (false);
    }
    std::cout << std::right << std::setw(10) << "Index"
              << "|";
    std::cout << std::right << std::setw(10) << "Firstname"
              << "|";
    std::cout << std::right << std::setw(10) << "Lastname"
              << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
    while (i < this->m_registerNum)
    {
        firstName = this->contact[i].getFirstName();
        lastName = this->contact[i].getLastName();
        nickName = this->contact[i].getNickName();
        if (firstName.length() > 9)
        {
            firstName = firstName.substr(0, 9) + ".";
        }
        if (lastName.length() > 9)
        {
            lastName = lastName.substr(0, 9) + ".";
        }
        if (nickName.length() > 9)
        {
            nickName = nickName.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << firstName << "|";
        std::cout << std::right << std::setw(10) << lastName << "|";
        std::cout << std::right << std::setw(10) << nickName << std::endl;
        i++;
    }
    return (true);
}

void PhoneBook::_shiftLeft()
{
    for (int i = 1; i < this->m_registerNum; i++)
    {
        this->contact[i - 1] = this->contact[i];
    }
    this->m_registerNum -= 1;
}

void PhoneBook::addContact()
{
    if (m_registerNum >= MAX_ELEMENT)
    {
        this->_shiftLeft();
    }
    this->contact[this->m_registerNum] = Contact();
    this->contact[this->m_registerNum].registerContact();
    this->m_registerNum += 1;
}

void PhoneBook::searchContact()
{
    std::string tmp;
    int searchIndex;
    bool finishFlag;

    finishFlag = false;
    if (!this->_showContacts())
    {
        return;
    }
    while (!finishFlag)
    {
        std::cout << "Enter index: ";
        try
        {
            if (!std::getline(std::cin, tmp))
            {
                break;
            }
            if (!isNum(tmp))
            {
                throw std::invalid_argument("");
            }
            searchIndex = std::atoi(tmp.c_str());
            if (searchIndex > this->m_registerNum - 1 || searchIndex < 0)
            {
                throw std::out_of_range("");
            }
            finishFlag = true;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Error: Input is not a valid number." << std::endl;
        }
        catch (const std::out_of_range &e)
        {
            std::cout << "Error: Number is out of range." << std::endl;
        }
    }
    if (!finishFlag)
    {
        return;
    }
    this->contact[searchIndex].showInfo();
}
