#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string target_;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	std::string getTarget( void ) const;
	virtual ~ShrubberyCreationForm();

	void execute(const Bureaucrat &executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& scForm);
std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& scForm);

#endif

