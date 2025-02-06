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
	return (0);
}