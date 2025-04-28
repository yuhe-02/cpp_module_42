#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("anonymous_presidential", 25, 5), target_("anonymous")
{
    std::cout << "PresidentialPardonForm " << this->target_ << ": "
              << "default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm " << this->target_ << ": "
              << "default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("anonymous_presidential", 25, 5), target_(target)
{
    std::cout << "PresidentialPardonForm " << this->target_ << ": "
              << "constructor with name called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm("anonymous_presidential", 25, 5), target_(copy.getTarget())
{
    std::cout << "PresidentialPardonForm " << this->target_ << ": "
              << "copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "PresidentialPardonForm " << this->target_ << ": "
              << "copy assignment called" << std::endl;
    AForm::operator=(copy);
    if (this == &copy)
        return *this;
    return *this;
}

// getter
std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->target_);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->AForm::execute(executor);
    std::cout << "PresidentialPardonForm " << this->target_ << ": "
              << "execute called" << std::endl;
    std::cout << "PresidentialPardonForm " << this->target_ << ": "
              << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &ppForm)
{
    std::string isAssigned_s = ppForm.getIsAssigned() == true ? "true" : "false";
    os << "PresidentialPardonForm's inAFormation\n"
       << "name:        " << ppForm.getName() << "\n"
       << "sign grade:  " << ppForm.getSignGrade() << "\n"
       << "exec grade:  " << ppForm.getExecGrade() << "\n"
       << "is assigned: " << isAssigned_s << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm &ppForm)
{
    std::string isAssigned_s = ppForm.getIsAssigned() == true ? "true" : "false";
    os << "PresidentialPardonForm's inAFormation\n"
       << "name:        " << ppForm.getName() << "\n"
       << "sign grade:  " << ppForm.getSignGrade() << "\n"
       << "exec grade:  " << ppForm.getExecGrade() << "\n"
       << "is assigned: " << isAssigned_s << "\n";
    return os;
}
