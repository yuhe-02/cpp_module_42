#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {

	private :
		const std::string name_;
		bool  isAssigned_;
		const int signGrade_;
		const int execGrade_;
	public :
		class GradeTooHighException: std::exception {
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException: std::exception {
			public :
				virtual const char *what() const throw();
		};
		void beSigned(const Bureaucrat &bureaucrat);
		const int getSignGrade( void ) const;
		const int getExecGrade( void ) const;
		bool getIsAssigned( void ) const;
		const std::string getName( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);
#endif