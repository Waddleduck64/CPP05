#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string_view target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & original): AForm(original), _target(original._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & original)
{
	if (this == &original)
		return *this;
	AForm::operator=(original);
	_target = original._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	executionCheck(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/*		Private		*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default")
{}
