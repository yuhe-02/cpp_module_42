#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
class Bureaucrat;

class AForm {
private:
  const std::string name_;
  bool isAssigned_;
  const int signGrade_;
  const int execGrade_;

public:
  AForm();
  AForm(const AForm &copy);
  AForm(std::string name, int signGrade, int execGrade);
  AForm(int signGrade, int execGrade);
  AForm(std::string name);
  AForm &operator=(const AForm &copy);
  virtual ~AForm();
  class Exception : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooHighException : public AForm::Exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public AForm::Exception {
  public:
    virtual const char *what() const throw();
  };
  class AlreadySignedException : public AForm::Exception {
  public:
    virtual const char *what() const throw();
  };
  class NotSignedException : public AForm::Exception {
  public:
    virtual const char *what() const throw();
  };
  void beSigned(Bureaucrat &bureaucrat);
  int getSignGrade(void) const;
  int getExecGrade(void) const;
  bool getIsAssigned(void) const;
  const std::string getName(void) const;
  virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);
std::ostream &operator<<(std::ostream &os, AForm &AForm);
#endif