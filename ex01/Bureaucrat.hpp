#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const 	_name;
		int 				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &o);
		Bureaucrat &operator=(const Bureaucrat &o);

		int	getGrade() const;
		std::string getName() const;

		void incrementGrade(); // -1
		void decrementGrade(); // +1

		void signForm(AForm &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
