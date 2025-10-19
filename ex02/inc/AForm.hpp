#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		~Form();
		Form(const Form &o);
		Form &operator=(const Form &o);

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const class Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);
