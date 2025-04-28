#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>

class Bureaucrat
{
  private:
    const std::string name_;
    int grade_;
    void setGrade(int grade);

  public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(std::string name);
    Bureaucrat(int grade);
    Bureaucrat &operator=(const Bureaucrat &copy);
    ~Bureaucrat();
    const std::string getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
    class GradeTooHighException : std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
std::ostream &operator<<(std::ostream &os, const Bureaucrat *bureaucrat);
#endif
