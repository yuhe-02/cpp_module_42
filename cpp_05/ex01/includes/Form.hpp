#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
	private :
		const std::string name_;
		bool  isAssigned_;
		const int signGrade_;
		const int execGrade_;
	public :
		Form();
		Form(const Form &copy);
		Form(std::string name, int signGrade, int execGrade);
		Form(int signGrade, int execGrade);
		Form(std::string name);
		Form &operator=(const Form & copy);
		~Form();
		class Exception: public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public Form::Exception {
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public Form::Exception {
			public :
				virtual const char *what() const throw();
		};
		class AlreadySignedException: public Form::Exception {
			public :
				virtual const char *what() const throw();
		};
		void beSigned(Bureaucrat &bureaucrat);
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;
		bool getIsAssigned( void ) const;
		const std::string getName( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);
std::ostream& operator<<(std::ostream& os, Form& form);
#endif