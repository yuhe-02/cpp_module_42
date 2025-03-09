#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void)
{
	AForm *a = new PresidentialPardonForm();
	Bureaucrat *b = new Bureaucrat(1);
	b->signForm(*a);

	try {
		a->execute(*b);
	} catch (AForm::Exception &e) {
		std::cout << "failed to exec : " << e.what() << std::endl;
	}
	
	return (0);
}