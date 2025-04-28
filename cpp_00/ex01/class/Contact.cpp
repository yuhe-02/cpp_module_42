#include "Contact.hpp"

static const char *memberNames[MEMBER_NUM] = {
    "first name", "last name", "nick name", "phone number", "darkest secret"};

Contact::Contact() { m_isRegisterd = false; }

Contact::~Contact() {}

void Contact::showInfo() {
  if (!m_isRegisterd) {
    std::cout << "No register" << std::endl;
    return;
  }
  std::cout << std::left << std::setw(15) << memberNames[0] << ": ";
  std::cout << m_firstName << std::endl;
  std::cout << std::left << std::setw(15) << memberNames[1] << ": ";
  std::cout << m_lastName << std::endl;
  std::cout << std::left << std::setw(15) << memberNames[2] << ": ";
  std::cout << m_nickName << std::endl;
  std::cout << std::left << std::setw(15) << memberNames[3] << ": ";
  std::cout << m_phoneNumber << std::endl;
  std::cout << std::left << std::setw(15) << memberNames[4] << ": ";
  std::cout << m_darkestSecret << std::endl;
}

bool Contact::_registerValue(int msgIndex, std::string &buf) {
  bool isFinished;

  isFinished = false;
  while (!isFinished) {
    std::cout << "Please input " << memberNames[msgIndex] << ": ";
    if (!std::getline(std::cin, buf)) {
      std::cout << std::endl;
      break;
    }
    if (buf.length() == 0) {
      std::cout << "Empty not allowed" << std::endl;
      continue;
    }
    isFinished = true;
  }
  return (isFinished);
}

void Contact::registerContact() {
  if (m_isRegisterd) {
    std::cout << "Already registered" << std::endl;
    return;
  }
  if (!this->_registerValue(0, m_firstName)) {
    return;
  }
  if (!this->_registerValue(1, m_lastName)) {
    return;
  }
  if (!this->_registerValue(2, m_nickName)) {
    return;
  }
  if (!this->_registerValue(3, m_phoneNumber)) {
    return;
  }
  if (!this->_registerValue(4, m_darkestSecret)) {
    return;
  }
  m_isRegisterd = true;
}

std::string Contact::getFirstName() { return (this->m_firstName); }

std::string Contact::getLastName() { return (this->m_lastName); }

std::string Contact::getNickName() { return (this->m_nickName); }

std::string Contact::getPhoneNumber() { return (this->m_phoneNumber); }

std::string Contact::getDarkestSecret() { return (this->m_darkestSecret); }

bool Contact::getIsRegistered() { return (this->m_isRegisterd); }
