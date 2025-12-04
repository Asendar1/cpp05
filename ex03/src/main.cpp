#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    srand(time(0));

    Bureaucrat boss("Boss", 1);
    RobotomyRequestForm robo("abo alshabab");
    robo.beSigned(boss);
    robo.execute(boss);

    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;

    Bureaucrat intern("intern", 145);
    RobotomyRequestForm robo2("victim");
    try
    {
        robo2.beSigned(intern);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;

    ShrubberyCreationForm shrub("home");
    try
    {
        shrub.beSigned(intern);
        shrub.execute(intern);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "-------BOSS--------" << std::endl;
    std::cout << "-------------------" << std::endl;

    try
    {
        shrub.beSigned(boss);
        shrub.execute(boss);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;
    PresidentialPardonForm pres("criminal");
    try
    {
        pres.beSigned(intern);
        pres.execute(intern);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        intern.signForm(pres);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;

    Intern jackie;
    AForm *robo3;
    robo3 = jackie.makeForm("RobotomyRequestForm", "bashbosh");

    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;
    delete robo3;
    return 0;
}
