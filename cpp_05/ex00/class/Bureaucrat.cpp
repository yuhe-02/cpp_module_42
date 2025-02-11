#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): name_("anonymous"), grade_(150) {
	std::cout << "Bureucrat " << this->name_ << ": " << "default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureucrat " << this->name_ << ": " << "default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): name_(name), grade_(150) {
	std::cout << "Bureucrat " << this->name_ << ": " << "constructor with name called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name_(name) {
	std::cout << "Bureucrat " << this->name_ << ": " << "constructor with name and grade called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(int grade): name_("anonymous") {
	std::cout << "Bureucrat " << this->name_ << ": " << "constructor with grade called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name_(copy.getName()) {
	std::cout << "Bureucrat " << this->name_ << ": " << "copy constructor called" << std::endl;
	this->setGrade(copy.getGrade());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	std::cout << "Bureucrat " << this->name_ << ": " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	this->setGrade(copy.getGrade());
	return *this;
}

// getter, setter
void Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ = grade;
}

int Bureaucrat::getGrade( void ) const {
	return (this->grade_);
}

const std::string Bureaucrat::getName( void ) const {
	return (this->name_);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("grade is too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("grade is too high");
}

// TODO create increment decrement

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
