#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	big_chungus("Big Chungus", 1);

	try
	{
		big_chungus.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException const & e)
	{
		std::cout << e.what() << std::endl;
	}
}
