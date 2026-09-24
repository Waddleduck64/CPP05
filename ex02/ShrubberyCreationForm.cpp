#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
// #include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string_view target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & original): AForm(original), _target(original._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & original)
{
	if (this == &original)
		return *this;
	AForm::operator=(original);
	_target = original._target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	// ??????????????????????????????
}
/*		Private		*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}
