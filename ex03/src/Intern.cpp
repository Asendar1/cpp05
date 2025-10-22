#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
Intern::~Intern(){}

AForm* createTree(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createPres(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* createRobo(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string forms[3] = {
        "ShrubberyCreationForm",
        "PresidentialPardonForm",
        "RobotomyRequestForm"
    };

    AForm* (*FormFunctions[3])(const std::string &type) = {createPres, createRobo, createTree};

    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == formName)
        {
            std::cout << "Intern creates " << forms[i] << std::endl;
            return FormFunctions[i](target);
        }
    }
    std::cout << "Invalid type of form" << std::endl;
    return NULL;

}