#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): name_("anonymous"), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "RobotomyRequestForm " << this->name_ << ": " << "default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << this->name_ << ": " << "default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): name_(name), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "RobotomyRequestForm " << this->name_ << ": " << "constructor with name called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(int signGrade, int execGrade): name_("anonymous"), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "RobotomyRequestForm " << this->name_ << ": " << "constructor with sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(RobotomyRequestForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(RobotomyRequestForm::GradeTooHighException());
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int signGrade, int execGrade): name_(name), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "RobotomyRequestForm " << this->name_ << ": " << "constructor with name, sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(RobotomyRequestForm::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(RobotomyRequestForm::GradeTooHighException());
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): name_(copy.getName()), isAssigned_(false), signGrade_(copy.getSignGrade()), execGrade_(copy.getExecGrade()) {
	std::cout << "RobotomyRequestForm " << this->name_ << ": " << "copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	std::cout << "RobotomyRequestForm " << this->name_ << ": " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// getter
const std::string RobotomyRequestForm::getName( void ) const {
	return (this->name_);
}

int RobotomyRequestForm::getSignGrade( void ) const {
	return (this->signGrade_);
}

int RobotomyRequestForm::getExecGrade( void ) const {
	return (this->execGrade_);
}

bool RobotomyRequestForm::getIsAssigned( void ) const {
	return (this->isAssigned_);
}

const char *RobotomyRequestForm::GradeTooLowException::what(void) const throw(){
	return ("grade is too low");
}

const char *RobotomyRequestForm::GradeTooHighException::what(void) const throw(){
	return ("grade is too high");
}

void RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsAssigned() == false)
	{
		this->isAssigned_ = true;
		std::cout << this->getName() << " RobotomyRequestForm was signed by " << bureaucrat.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " RobotomyRequestForm is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm* RobotomyRequestForm) {
	std::string isAssigned_s = RobotomyRequestForm->getIsAssigned() == true ? "true" : "false";
    os << "RobotomyRequestForm's inRobotomyRequestFormation\n" 
		<< "name:        "  << RobotomyRequestForm->getName() << "\n" 
		<< "sign grade:  "  << RobotomyRequestForm->getSignGrade() << "\n" 
		<< "exec grade:  "  << RobotomyRequestForm->getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}
