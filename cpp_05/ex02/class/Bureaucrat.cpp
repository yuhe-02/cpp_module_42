#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name_("anonymous"), grade_(150)
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name_(name), grade_(150)
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "constructor with name called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "constructor with name and grade called" << std::endl;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(int grade) : name_("anonymous")
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "constructor with grade called" << std::endl;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name_(copy.getName())
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "copy constructor called" << std::endl;
    this->setGrade(copy.getGrade());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "copy assignment called" << std::endl;
    if (this == &copy)
        return *this;
    this->setGrade(copy.getGrade());
    return *this;
}

// getter, setter
void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade_ = grade;
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade_);
}

const std::string Bureaucrat::getName(void) const
{
    return (this->name_);
}

void Bureaucrat::incrementGrade(void)
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "incrementGrade called" << std::endl;
    this->setGrade(this->grade_ - 1);
}

void Bureaucrat::decrementGrade(void)
{
    std::cout << "Bureucrat " << this->name_ << ": "
              << "decrementGrade called" << std::endl;
    this->setGrade(this->grade_ + 1);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("grade is too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("grade is too high");
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name_ << " signed " << form.getName() << std::endl;
    }
    catch (AForm::Exception &e)
    {
        std::cout << this->name_ << " could't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
