#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << name << " constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << name << " destructor called" << std::endl;
}

AForm::AForm(const AForm &o) : name(o.name), isSigned(o.isSigned), signGrade(o.signGrade), executeGrade(o.executeGrade)
{
	std::cout << "AForm " << name << " copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &o) // all other fields are const
{
	if (this != &o)
		isSigned = o.isSigned;
	std::cout << "AForm " << name << " copy assignment operator called" << std::endl;
	return *this;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecuteGrade() const
{
	return executeGrade;
}

void AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("the Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm " << AForm.getName() << ", sign grade " << AForm.getSignGrade()
		<< ", execute grade " << AForm.getExecuteGrade() << ", is signed: "
		<< (AForm.getIsSigned() ? "true" : "false");
	return out;	
}
