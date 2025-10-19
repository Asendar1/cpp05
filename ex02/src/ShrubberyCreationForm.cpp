#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm ("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o) : AForm(o), target(o.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (getSignGrade())
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade())
    {
        throw GradeTooLowException();
    }
    std::cout << "Creating shrubbery at " << target << std::endl;
}