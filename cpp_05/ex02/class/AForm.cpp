#include "AForm.hpp"
#include <iostream>

AForm::AForm(): name_("anonymous"), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "AForm " << this->name_ << ": " << "default constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm " << this->name_ << ": " << "default destructor called" << std::endl;
}

AForm::AForm(std::string name): name_(name), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "AForm " << this->name_ << ": " << "constructor with name called" << std::endl;
}

AForm::AForm(int signGrade, int execGrade): name_("anonymous"), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "AForm " << this->name_ << ": " << "constructor with sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(AForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(std::string name, int signGrade, int execGrade): name_(name), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "AForm " << this->name_ << ": " << "constructor with name, sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(AForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const AForm &copy): name_(copy.getName()), isAssigned_(false), signGrade_(copy.getSignGrade()), execGrade_(copy.getExecGrade()) {
	std::cout << "AForm " << this->name_ << ": " << "copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
	std::cout << "AForm " << this->name_ << ": " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// getter
const std::string AForm::getName( void ) const {
	return (this->name_);
}

int AForm::getSignGrade( void ) const {
	return (this->signGrade_);
}

int AForm::getExecGrade( void ) const {
	return (this->execGrade_);
}

bool AForm::getIsAssigned( void ) const {
	return (this->isAssigned_);
}

const char *AForm::GradeTooLowException::what(void) const throw(){
	return ("grade is too low");
}

const char *AForm::GradeTooHighException::what(void) const throw(){
	return ("grade is too high");
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsAssigned() == false)
	{
		this->isAssigned_ = true;
		std::cout << this->getName() << " AForm was signed by " << bureaucrat.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm* AForm) {
	std::string isAssigned_s = AForm->getIsAssigned() == true ? "true" : "false";
    os << "AForm's inAFormation\n" 
		<< "name:        "  << AForm->getName() << "\n" 
		<< "sign grade:  "  << AForm->getSignGrade() << "\n" 
		<< "exec grade:  "  << AForm->getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, AForm* AForm) {
	std::string isAssigned_s = AForm->getIsAssigned() == true ? "true" : "false";
    os << "AForm's inAFormation\n" 
		<< "name:        "  << AForm->getName() << "\n" 
		<< "sign grade:  "  << AForm->getSignGrade() << "\n" 
		<< "exec grade:  "  << AForm->getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}
