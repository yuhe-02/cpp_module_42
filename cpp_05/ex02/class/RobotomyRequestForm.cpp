#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm("anonymous_RobotomyRequest", 72, 45), target_("anonymous") {
	std::cout << "RobotomyRequestForm " << this->target_ << ": " << "default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << this->target_ << ": " << "default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("anonymous_RobotomyRequest", 72, 45), target_(target)  {
	std::cout << "RobotomyRequestForm " << this->target_ << ": " << "constructor with name called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm("anonymous_RobotomyRequest", 72, 45), target_(copy.getTarget()) {
	std::cout << "RobotomyRequestForm " << this->target_ << ": " << "copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	std::cout << "RobotomyRequestForm " << this->target_ << ": " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// getter
std::string RobotomyRequestForm::getTarget( void ) const {
	return (this->target_);
}

// TODO create function
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::cout << "RobotomyRequestForm " << this->target_ << ": " << "execute called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& rrForm) {
	std::string isAssigned_s = rrForm.getIsAssigned() == true ? "true" : "false";
    os << "RobotomyRequestForm's inAFormation\n" 
		<< "name:        "  << rrForm.getName() << "\n" 
		<< "sign grade:  "  << rrForm.getSignGrade() << "\n" 
		<< "exec grade:  "  << rrForm.getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& rrForm) {
	std::string isAssigned_s = rrForm.getIsAssigned() == true ? "true" : "false";
    os << "RobotomyRequestForm's inAFormation\n" 
		<< "name:        "  << rrForm.getName() << "\n" 
		<< "sign grade:  "  << rrForm.getSignGrade() << "\n" 
		<< "exec grade:  "  << rrForm.getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}
