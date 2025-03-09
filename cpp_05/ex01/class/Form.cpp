#include "Form.hpp"
#include <iostream>

Form::Form(): name_("anonymous"), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "Form " << this->name_ << ": " << "default constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << this->name_ << ": " << "default destructor called" << std::endl;
}

Form::Form(std::string name): name_(name), isAssigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "Form " << this->name_ << ": " << "constructor with name called" << std::endl;
}

Form::Form(int signGrade, int execGrade): name_("anonymous"), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "Form " << this->name_ << ": " << "constructor with sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(Form::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(std::string name, int signGrade, int execGrade): name_(name), isAssigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	std::cout << "Form " << this->name_ << ": " << "constructor with name, sign grade and exec grade called" << std::endl;
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw(Form::GradeTooLowException());
	else if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const Form &copy): name_(copy.getName()), isAssigned_(false), signGrade_(copy.getSignGrade()), execGrade_(copy.getExecGrade()) {
	std::cout << "Form " << this->name_ << ": " << "copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy) {
	std::cout << "Form " << this->name_ << ": " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// getter
const std::string Form::getName( void ) const {
	return (this->name_);
}

int Form::getSignGrade( void ) const {
	return (this->signGrade_);
}

int Form::getExecGrade( void ) const {
	return (this->execGrade_);
}

bool Form::getIsAssigned( void ) const {
	return (this->isAssigned_);
}

const char *Form::Exception::what(void) const throw(){
	return ("Form Exception");
}

const char *Form::GradeTooLowException::what(void) const throw(){
	return ("grade is too low");
}

const char *Form::GradeTooHighException::what(void) const throw(){
	return ("grade is too high");
}

const char *Form::AlreadySignedException::what(void) const throw(){
	return ("Form is already signed");
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade()) {
		throw(Form::GradeTooLowException());
	}
	if (this->getIsAssigned() == true) {
		throw(Form::AlreadySignedException());
	}
	this->isAssigned_ = true;
	std::cout << this->getName() << " Form was signed by " << bureaucrat.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	std::string isAssigned_s = form.getIsAssigned() == true ? "true" : "false";
    os << "Form's information\n" 
		<< "name:        "  << form.getName() << "\n" 
		<< "sign grade:  "  << form.getSignGrade() << "\n" 
		<< "exec grade:  "  << form.getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, Form& form) {
	std::string isAssigned_s = form.getIsAssigned() == true ? "true" : "false";
    os << "Form's information\n" 
		<< "name:        "  << form.getName() << "\n" 
		<< "sign grade:  "  << form.getSignGrade() << "\n" 
		<< "exec grade:  "  << form.getExecGrade() << "\n"
		<< "is assigned: "  << isAssigned_s << "\n";
    return os;
}
