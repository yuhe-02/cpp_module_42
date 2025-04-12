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
		AForm *a = 0;
		AForm *b = 0;
		AForm *c = 0;
		AForm *f = 0;
		Bureaucrat *d = 0;
		try {
			a = intern.makeForm("robotomy request", "Bender");
			b = intern.makeForm("shrubbery creation", "home");
			c = intern.makeForm("presidential pardon", "Bender");
			f = intern.makeForm("nothing", "Bender");
			d = new Bureaucrat(1);
			d->signForm(*a);
			d->signForm(*b);
			d->signForm(*c);
			std::cout << f << std::endl;
		} catch (AForm::Exception &e) {
			std::cout << "failed to exec : " << e.what() << std::endl;
		}
		if (a)
			delete a;
		if (b)
			delete b;
		if (c)
			delete c;
		if (f)
			delete f;
		if (d)
			delete d;
	}
	
	return (0);
}