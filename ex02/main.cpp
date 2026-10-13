#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	big_chungus("Big Chungus", 1);
	Bureaucrat	medium_chungus("Medium Chungus", 10);
	ShrubberyCreationForm	shrub("local");
	PresidentialPardonForm	joe("Joe Mama");

	std::cout << big_chungus << '\n' << medium_chungus << '\n' << shrub << '\n' << joe << '\n' << std::endl;

	// medium_chungus.signForm(shrub);
	// std::cout << shrub << std::endl;
	// big_chungus.signForm(shrub);
	// std::cout << shrub << std::endl;

	big_chungus.signForm(shrub);
	try
	{
		shrub.execute(big_chungus);
	}
	catch (AForm::FormNotSignedException const & e)
	{
		std::cout << big_chungus.getName() << " couldn't execute this form because: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cout << big_chungus.getName() << " couldn't execute this form because: " << e.what() << std::endl;
	}

	medium_chungus.signForm(joe);
	try
	{
		joe.execute(medium_chungus);
		return 0;
	}
	catch (AForm::FormNotSignedException const & e)
	{
		std::cout << medium_chungus.getName() << " couldn't execute this form because: " << e.what() << std::endl;
		big_chungus.signForm(joe);
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cout << medium_chungus.getName() << " couldn't execute this form because: " << e.what() << std::endl;
	}

	try
	{
		joe.execute(big_chungus);
		return 0;
	}
	catch (AForm::FormNotSignedException const & e)
	{
		std::cout << big_chungus.getName() << " couldn't execute this form because: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cout << big_chungus.getName() << " couldn't execute this form because: " << e.what() << std::endl;
	}
}
