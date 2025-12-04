#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;

	try {
		Bureaucrat b("bob", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat b("charlie", 2);
	std::cout << b << std::endl;
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
	return 0;
}
