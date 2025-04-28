#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
  private:
    std::string target_;

  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    std::string getTarget(void) const;
    virtual ~RobotomyRequestForm();

    void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &rrForm);
std::ostream &operator<<(std::ostream &os, RobotomyRequestForm &rrForm);

#endif
