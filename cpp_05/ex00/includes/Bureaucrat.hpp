#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name_;
	int grade_;
	void setGrade(int grade);

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(std::string name);
	Bureaucrat(int grade);
	Bureaucrat &operator=(const Bureaucrat & copy);
	~Bureaucrat();
	const std::string getName(void) const;
	int getGrade(void) const;
};
std::ostream &operator<<(std::ostream &o, Bureaucrat *a);
#endif
