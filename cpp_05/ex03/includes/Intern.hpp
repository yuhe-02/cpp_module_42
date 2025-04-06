#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


class Intern;
typedef AForm *(Intern::*FormCreationFunc)(std::string target);
struct FormType {
	std::string name;
	FormCreationFunc func;
};

#define FORM_COUNT 3

class Intern
{
private:

	static const FormType fpFunc_[FORM_COUNT];
	AForm *createRobotomyRequest(std::string target);
	AForm *createPresidentialPardon(std::string target);
	AForm *createShrubberyCreation(std::string target);
public:
	Intern();
	Intern(const Intern &src);
	~Intern();
	Intern &operator=(const Intern &src);

	AForm *makeForm(std::string formName, std::string target);
};