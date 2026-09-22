#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	big_chungus("Big Chungus", 1);
	Bureaucrat	medium_chungus("Medium Chungus", 10);
	Form		spellcheck("Automated Spellchecker-checker update 42.69", 1, 150);

	std::cout << big_chungus << '\n' << medium_chungus << '\n' << spellcheck << std::endl;

	medium_chungus.signForm(spellcheck);
	std::cout << spellcheck << std::endl;
	big_chungus.signForm(spellcheck);
	std::cout << spellcheck << std::endl;
}
