#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a;
	Bureaucrat b("bob", 1);
	Bureaucrat c(b);
	Bureaucrat d;
	d = b;

	std::cout << b << std::endl;

	try {
		Bureaucrat high("charlie", 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		b.incrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat e("alice", 150);
	std::cout << e << std::endl;

	try
	{
		e.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form f("FormA", 50, 100);
	std::cout << f << std::endl;
	try
	{
		b.signForm(f);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << f << std::endl;
	try
	{
		f.beSigned(e);
	}
	catch(const std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		e.signForm(f);
	}
	catch(const std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}
