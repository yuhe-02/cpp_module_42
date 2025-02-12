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
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
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
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
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
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
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
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
			if (s1) {
				std::cout << "name: " << s1->getName() << ", grade: " << s1->getGrade() << std::endl;
			}
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
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
	{
		std::cout << "----print test ----" << std::endl;
		Bureaucrat *s1 = new Bureaucrat();
		std::cout << s1 << std::endl;
		delete s1;
	}
	{
		std::cout << "----increment test ----" << std::endl;
		Bureaucrat s1(5);
		s1.incrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;
		s1.incrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;
		s1.incrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;
		s1.incrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;

		try {
			s1.incrementGrade();
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "----decrement test ----" << std::endl;
		Bureaucrat s1(146);
		s1.decrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;
		s1.decrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;
		s1.decrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;
		s1.decrementGrade();
		std::cout << "name: " << s1.getName() << ", grade: " << s1.getGrade() << std::endl;
		try {
			s1.decrementGrade();
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}