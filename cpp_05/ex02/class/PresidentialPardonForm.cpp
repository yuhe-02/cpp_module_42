#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): name_("anonymous"), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "PresidentialPardonForm " << this->name_ << ": " << "default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm " << this->name_ << ": " << "default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name): name_(name), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "PresidentialPardonForm " << this->name_ << ": " << "constructor with name called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(int signGrade, int execGrade): name_("anonymous"), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "PresidentialPardonForm " << this->name_ << ": " << "constructor with sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(PresidentialPardonForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(PresidentialPardonForm::GradeTooHighException());
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int signGrade, int execGrade): name_(name), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "PresidentialPardonForm " << this->name_ << ": " << "constructor with name, sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(PresidentialPardonForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(PresidentialPardonForm::GradeTooHighException());
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): name_(copy.getName()), isAssigned_(false), signGrade_(copy.getSignGrade()), execGrade_(copy.getExecGrade()) {
	std::cout << "PresidentialPardonForm " << this->name_ << ": " << "copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	std::cout << "PresidentialPardonForm " << this->name_ << ": " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// getter
const std::string PresidentialPardonForm::getName( void ) const {
	return (this->name_);
}

int PresidentialPardonForm::getSignGrade( void ) const {
	return (this->signGrade_);
}

int PresidentialPardonForm::getExecGrade( void ) const {
	return (this->execGrade_);
}

bool PresidentialPardonForm::getIsAssigned( void ) const {
	return (this->isAssigned_);
}

const char *PresidentialPardonForm::GradeTooLowException::what(void) const throw(){
	return ("grade is too low");
}

const char *PresidentialPardonForm::GradeTooHighException::what(void) const throw(){
	return ("grade is too high");
}

void PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsAssigned() == false)
	{
		this->isAssigned_ = true;
		std::cout << this->getName() << " PresidentialPardonForm was signed by " << bureaucrat.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " PresidentialPardonForm is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm* PresidentialPardonForm) {
	std::string isAssigned_s = PresidentialPardonForm->getIsAssigned() == true ? "true" : "false";
    os << "PresidentialPardonForm's inPresidentialPardonFormation\n" 
		<< "name:        "  << PresidentialPardonForm->getName() << "\n" 
		<< "sign grade:  "  << PresidentialPardonForm->getSignGrade() << "\n" 
		<< "exec grade:  "  << PresidentialPardonForm->getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}
