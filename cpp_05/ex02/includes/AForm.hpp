#ifndef __AForm_HPP__
#define __AForm_HPP__

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
	private :
		const std::string name_;
		bool  isAssigned_;
		const int signGrade_;
		const int execGrade_;
	public :
		AForm();
		AForm(const AForm &copy);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(int signGrade, int execGrade);
		AForm(std::string name);
		AForm &operator=(const AForm & copy);
		~AForm();
		class GradeTooHighException: std::exception {
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException: std::exception {
			public :
				virtual const char *what() const throw();
		};
		void beSigned(Bureaucrat &bureaucrat);
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;
		bool getIsAssigned( void ) const;
		const std::string getName( void ) const;
};

std::ostream& operator<<(std::ostream& os, const AForm* AForm);
std::ostream& operator<<(std::ostream& os, AForm* AForm);
#endif