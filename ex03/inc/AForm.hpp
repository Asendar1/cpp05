#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		virtual ~AForm();
		AForm(const AForm &o);
		AForm &operator=(const AForm &o);

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const class Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);
