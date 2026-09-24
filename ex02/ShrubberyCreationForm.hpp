#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include <string>
# include <string_view>

class ShrubberyCreationForm: public AForm
{
	public:
	ShrubberyCreationForm(std::string_view target);
	ShrubberyCreationForm(ShrubberyCreationForm const & original);

	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & original);

	void	execute(Bureaucrat const & executor);

	private:
	ShrubberyCreationForm();

	std::string	_target;
};

#endif