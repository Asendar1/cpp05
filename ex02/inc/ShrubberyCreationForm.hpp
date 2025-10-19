#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &o);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &o);

        void execute(const Bureaucrat &executor) const;
};