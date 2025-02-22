#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(): name_("anonymous"), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "ShrubberyCreationForm " << this->name_ << ": " << "default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << this->name_ << ": " << "default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): name_(name), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "ShrubberyCreationForm " << this->name_ << ": " << "constructor with name called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(int signGrade, int execGrade): name_("anonymous"), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "ShrubberyCreationForm " << this->name_ << ": " << "constructor with sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(ShrubberyCreationForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(ShrubberyCreationForm::GradeTooHighException());
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int signGrade, int execGrade): name_(name), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "ShrubberyCreationForm " << this->name_ << ": " << "constructor with name, sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(ShrubberyCreationForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(ShrubberyCreationForm::GradeTooHighException());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): name_(copy.getName()), isAssigned_(false), signGrade_(copy.getSignGrade()), execGrade_(copy.getExecGrade()) {
	std::cout << "ShrubberyCreationForm " << this->name_ << ": " << "copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	std::cout << "ShrubberyCreationForm " << this->name_ << ": " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// getter
const std::string ShrubberyCreationForm::getName( void ) const {
	return (this->name_);
}

int ShrubberyCreationForm::getSignGrade( void ) const {
	return (this->signGrade_);
}

int ShrubberyCreationForm::getExecGrade( void ) const {
	return (this->execGrade_);
}

bool ShrubberyCreationForm::getIsAssigned( void ) const {
	return (this->isAssigned_);
}

const char *ShrubberyCreationForm::GradeTooLowException::what(void) const throw(){
	return ("grade is too low");
}

const char *ShrubberyCreationForm::GradeTooHighException::what(void) const throw(){
	return ("grade is too high");
}

void ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsAssigned() == false)
	{
		this->isAssigned_ = true;
		std::cout << this->getName() << " ShrubberyCreationForm was signed by " << bureaucrat.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " ShrubberyCreationForm is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm* ShrubberyCreationForm) {
	std::string isAssigned_s = ShrubberyCreationForm->getIsAssigned() == true ? "true" : "false";
    os << "ShrubberyCreationForm's inShrubberyCreationFormation\n" 
		<< "name:        "  << ShrubberyCreationForm->getName() << "\n" 
		<< "sign grade:  "  << ShrubberyCreationForm->getSignGrade() << "\n" 
		<< "exec grade:  "  << ShrubberyCreationForm->getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}
