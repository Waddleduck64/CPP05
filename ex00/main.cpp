#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	big_chungus("Big Chungus", 1);

	try
	{
		big_chungus.incGrade();
	}
	catch (Bureaucrat::GradeTooLowException const & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException const & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "This error has not been otherwise categorised." << std::endl;
	}
}
