#include "Intern.hpp"

const FormType Intern::fpFunc_[FORM_COUNT] = {
    {"robotomy request", &Intern::createRobotomyRequest},
    {"presidential pardon", &Intern::createPresidentialPardon},
    {"shrubbery creation", &Intern::createShrubberyCreation}};

Intern::Intern() {
  std::cout << "Intern: default constructor called" << std::endl;
}
Intern::Intern(const Intern &src) {
  std::cout << "Intern: copy constructor called" << std::endl;
  *this = src;
}
Intern::~Intern() { std::cout << "Intern: destructor called" << std::endl; }
Intern &Intern::operator=(const Intern &src) {
  std::cout << "Intern: copy assignment operator called" << std::endl;
  if (this == &src)
    return *this;
  return *this;
}

AForm *Intern::createRobotomyRequest(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardon(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyCreation(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  std::cout << "Intern: makeForm called" << std::endl;
  AForm *form = NULL;
  std::string message = "Intern creates ";

  for (int i = 0; i < FORM_COUNT; i++) {
    if (formName == fpFunc_[i].name) {
      form = (this->*fpFunc_[i].func)(target);
      message += formName;
      break;
    }
  }
  if (form == NULL) {
    message = "Intern creates nothing";
  }
  std::cout << message << std::endl;
  return form;
}