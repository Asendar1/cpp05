#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &o);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &o);

        void execute(const Bureaucrat &executor) const;
};