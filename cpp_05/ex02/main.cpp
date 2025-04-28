#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    {
        AForm *a = 0;
        Bureaucrat *b = 0;
        a = new PresidentialPardonForm();
        b = new Bureaucrat(1);
        b->signForm(*a);

        try
        {
            a->execute(*b);
        }
        catch (AForm::Exception &e)
        {
            std::cout << "failed to exec : " << e.what() << std::endl;
        }
        if (a)
            delete a;
        if (b)
            delete b;
    }
    {
        AForm *a = 0;
        Bureaucrat *b = 0;
        a = new RobotomyRequestForm();
        b = new Bureaucrat(1);
        b->signForm(*a);
        try
        {
            a->execute(*b);
            a->execute(*b);
            a->execute(*b);
        }
        catch (AForm::Exception &e)
        {
            std::cout << "failed to exec : " << e.what() << std::endl;
        }
        if (a)
            delete a;
        if (b)
            delete b;
    }
    {
        AForm *a = 0;
        Bureaucrat *b = 0;
        a = new ShrubberyCreationForm("home");
        b = new Bureaucrat(1);
        b->signForm(*a);
        try
        {
            a->execute(*b);
        }
        catch (AForm::Exception &e)
        {
            std::cout << "failed to exec : " << e.what() << std::endl;
        }
        if (a)
            delete a;
        if (b)
            delete b;
    }
    {
        ShrubberyCreationForm a("home");
        ShrubberyCreationForm b("home");
        Bureaucrat c("c", 1);
        a.beSigned(c);
        b = a;
        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b << std::endl;
    }

    return (0);
}