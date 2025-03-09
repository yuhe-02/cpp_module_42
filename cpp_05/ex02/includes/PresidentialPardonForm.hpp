#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string target_;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();
	std::string getTarget(void) const;
	void execute(const Bureaucrat &executor) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm* ppForm);
std::ostream& operator<<(std::ostream& os, PresidentialPardonForm* ppForm);

#endif