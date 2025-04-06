#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	// {
	// 	AForm *a = new PresidentialPardonForm();
	// 	Bureaucrat *b = new Bureaucrat(1);
	// 	b->signForm(*a);

	// 	try {
	// 		a->execute(*b);
	// 	} catch (AForm::Exception &e) {
	// 		std::cout << "failed to exec : " << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	AForm *a = new RobotomyRequestForm();
	// 	Bureaucrat *b = new Bureaucrat(1);
	// 	b->signForm(*a);
	// 	try {
	// 		a->execute(*b);
	// 		a->execute(*b);
	// 		a->execute(*b);
	// 	} catch (AForm::Exception &e) {
	// 		std::cout << "failed to exec : " << e.what() << std::endl;
	// 	}
	// }
	{
		Intern intern;
		try {
			AForm *a = intern.makeForm("robotomy request", "Bender");
			AForm *b = intern.makeForm("shrubbery creation", "home");
			AForm *c = intern.makeForm("presidential pardon", "Bender");
			AForm *f = intern.makeForm("nothing", "Bender");
			Bureaucrat *d = new Bureaucrat(1);
			d->signForm(*a);
			d->signForm(*b);
			d->signForm(*c);
			std::cout << f << std::endl;
		} catch (AForm::Exception &e) {
			std::cout << "failed to exec : " << e.what() << std::endl;
		}
	}
	
	return (0);
}