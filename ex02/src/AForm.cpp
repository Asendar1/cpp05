#include "AForm.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << name << "constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << name << " destructor called" << std::endl;
}

Form::Form(const Form &o) : name(o.name), isSigned(o.isSigned), signGrade(o.signGrade), executeGrade(o.executeGrade)
{
	std::cout << "Form " << name << " copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &o) // all other fields are const
{
	if (this != &o)
		isSigned = o.isSigned;
	std::cout << "Form " << name << " copy assignment operator called" << std::endl;
	return *this;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecuteGrade() const
{
	return executeGrade;
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << ", sign grade " << form.getSignGrade()
		<< ", execute grade " << form.getExecuteGrade() << ", is signed: "
		<< (form.getIsSigned() ? "true" : "false");
	return out;
}
