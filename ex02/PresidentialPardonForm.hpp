#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <string_view>

class PresidentialPardonForm: public AForm
{
	public:
	PresidentialPardonForm(std::string_view target);
	PresidentialPardonForm(PresidentialPardonForm const & original);

	virtual ~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(PresidentialPardonForm const & original);

	void	execute(Bureaucrat const & executor) const;

	private:
	PresidentialPardonForm();

	std::string	_target;
};

#endif