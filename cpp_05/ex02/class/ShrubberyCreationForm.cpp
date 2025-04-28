#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("anonymous_RobotomyRequest", 145, 137), target_("anonymous") {
  std::cout << "ShrubberyCreationForm " << this->target_ << ": "
            << "default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm " << this->target_ << ": "
            << "default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("anonymous_RobotomyRequest", 145, 137), target_(target) {
  std::cout << "ShrubberyCreationForm " << this->target_ << ": "
            << "constructor with name called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm("anonymous_RobotomyRequest", 145, 137), target_(copy.getTarget()) {
  std::cout << "ShrubberyCreationForm " << this->target_ << ": "
            << "copy constructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  std::cout << "ShrubberyCreationForm " << this->target_ << ": "
            << "copy assignment called" << std::endl;
  AForm::operator=(copy);
  if (this == &copy)
    return *this;
  return *this;
}

// getter
std::string ShrubberyCreationForm::getTarget(void) const {
  return (this->target_);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  this->AForm::execute(executor);

  std::fstream file;
  std::string fileName = this->target_ + "_shrubbery";
  file.open(fileName.c_str(), std::ios::out);
  if (!file.is_open()) {
    std::cout << "ShrubberyCreationForm " << this->target_ << ": "
              << "failed to execute" << std::endl;
    return;
  }
  file << "      /\\      \n"
       << "     /\\*\\     \n"
       << "    /\\O\\*\\    \n"
       << "   /*/\\/\\/\\   \n"
       << "  /\\O\\/\\*\\/\\  \n"
       << " /\\*\\/\\*\\/\\/\\ \n"
       << "/\\O\\/\\/*/\\/O/\\\n"
       << "      ||      \n"
       << "      ||      \n"
       << "      ||      \n";

  file.close();
  std::cout << "ShrubberyCreationForm " << this->target_ << ": "
            << "execute called" << std::endl;
}

std::ostream &operator<<(std::ostream &os,
                         const ShrubberyCreationForm &scForm) {
  std::string isAssigned_s = scForm.getIsAssigned() == true ? "true" : "false";
  os << "ShrubberyCreationForm's inAFormation\n"
     << "name:        " << scForm.getName() << "\n"
     << "sign grade:  " << scForm.getSignGrade() << "\n"
     << "exec grade:  " << scForm.getExecGrade() << "\n"
     << "is assigned: " << isAssigned_s << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &scForm) {
  std::string isAssigned_s = scForm.getIsAssigned() == true ? "true" : "false";
  os << "ShrubberyCreationForm's inAFormation\n"
     << "name:        " << scForm.getName() << "\n"
     << "sign grade:  " << scForm.getSignGrade() << "\n"
     << "exec grade:  " << scForm.getExecGrade() << "\n"
     << "is assigned: " << isAssigned_s << "\n";
  return os;
}
