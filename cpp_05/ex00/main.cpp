#include <iostream>
#include "./includes/Bureaucrat.hpp"

int main() {
	{
		std::cout << "----normal test----" << std::endl;
		Bureaucrat *s1 = new Bureaucrat();
		std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
		delete s1;
	}
	{
		std::cout << "----copy constructor ----" << std::endl;
		Bureaucrat s1;
		Bureaucrat s2(s1);
		std::cout << "name: " << s2.getName() << ", grade: " << s2.getGrade() << std::endl;
	}
	{
		std::cout << "----copy assignment ----" << std::endl;
		Bureaucrat s1;
		Bureaucrat s2;
		s2 = s1;
		std::cout << "name: " << s2.getName() << ", grade: " << s2.getGrade() << std::endl;
	}
	{
		std::cout << "----constructor with name ----" << std::endl;
		Bureaucrat *s1 = new Bureaucrat("tennis");
		std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
		delete s1;
	}
	{
		std::cout << "----constructor with grade ----" << std::endl;
		Bureaucrat *s1 = new Bureaucrat("tennis");
		std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
		delete s1;
	}
	{
		std::cout << "----too high grade(constructor) ----" << std::endl;
		Bureaucrat *s1 = 0;
		try {
			s1 = new Bureaucrat("tennis", 151);
			s1->getName();
		} catch (Bureaucrat::GradeTooHighException) {
			std::cout << "GradeTooHighException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (Bureaucrat::GradeTooLowException) {
			std::cout << "GradeTooLowException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		}
		if (s1) {
			delete s1;
		}
	}
	{
		std::cout << "----too low grade(constructor) ----" << std::endl;
		Bureaucrat *s1 = 0;
		try {
			s1 = new Bureaucrat("tennis", 0);
			s1->getName();
		} catch (Bureaucrat::GradeTooHighException) {
			std::cout << "GradeTooHighException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (Bureaucrat::GradeTooLowException) {
			std::cout << "GradeTooLowException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		}
		if (s1) {
			delete s1;
		}
	}
	{
		std::cout << "----too high grade(constructor) ----" << std::endl;
		Bureaucrat *s1 = 0;
		try {
			s1 = new Bureaucrat(151);
			s1->getName();
		} catch (Bureaucrat::GradeTooHighException) {
			std::cout << "GradeTooHighException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (Bureaucrat::GradeTooLowException) {
			std::cout << "GradeTooLowException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		}
		if (s1) {
			delete s1;
		}
	}
	{
		std::cout << "----too low grade(constructor) ----" << std::endl;
		Bureaucrat *s1 = 0;
		try {
			s1 = new Bureaucrat(0);
			s1->getName();
		} catch (Bureaucrat::GradeTooHighException) {
			std::cout << "GradeTooHighException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (Bureaucrat::GradeTooLowException) {
			std::cout << "GradeTooLowException catched" << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		}
		if (s1) {
			delete s1;
		}
	}
	{
		std::cout << "----print test ----" << std::endl;
		Bureaucrat s1(150);
		std::cout << s1 << std::endl;
	}
	// TODO create increment decrement
	return (0);
}