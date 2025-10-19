#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o)
    : AForm(o), target(o.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (getSignGrade())
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade())
    {
        throw GradeTooLowException();
    }
    if (rand() % 2)
    {
        std::cout << target << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}