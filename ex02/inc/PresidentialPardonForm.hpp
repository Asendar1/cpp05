#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &o);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &o);

        void execute(const Bureaucrat &executor) const;
};