#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <string_view>

class RobotomyRequestForm: public AForm
{
	public:
	RobotomyRequestForm(std::string_view target);
	RobotomyRequestForm(RobotomyRequestForm const & original);

	virtual ~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(RobotomyRequestForm const & original);

	void	execute(Bureaucrat const & executor) const;

	private:
	RobotomyRequestForm();

	std::string	_target;
};

#endif