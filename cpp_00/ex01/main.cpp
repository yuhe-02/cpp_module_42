#include "Utils.hpp"

int main() {
  std::string reader;
  PhoneBook phoneBook;

  while (1) {
    std::cout << "Input value: ";
    if (!std::getline(std::cin, reader)) {
      std::cout << std::endl;
      break;
    }
    if (reader.compare("ADD") == 0) {
      phoneBook.addContact();
    } else if (reader.compare("SEARCH") == 0) {
      phoneBook.searchContact();
    } else if (reader.compare("EXIT") == 0) {
      exit(0);
    }
  }
  return (0);
}