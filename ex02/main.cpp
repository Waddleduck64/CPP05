#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
// #include <iostream>

int	main()
{
	Bureaucrat	big_chungus("Big Chungus", 1);
	Bureaucrat	medium_chungus("Medium Chungus", 10);
	ShrubberyCreationForm	shrub("local");

	// std::cout << big_chungus << '\n' << medium_chungus << '\n' << shrub << std::endl;

	// medium_chungus.signForm(shrub);
	// std::cout << shrub << std::endl;
	// big_chungus.signForm(shrub);
	// std::cout << shrub << std::endl;

	big_chungus.signForm(shrub);
	shrub.execute(big_chungus);
}
