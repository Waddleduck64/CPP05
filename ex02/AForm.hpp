#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>
# include <string>
# include <string_view>

class AForm
{
	public:
	AForm(std::string_view name, size_t sign_grade, size_t exec_grade);
	AForm(AForm const & original);

	virtual ~AForm();

	AForm& operator=(AForm const & original);

	void			beSigned(Bureaucrat const & signer);
	virtual void	execute(Bureaucrat const & executor) = 0;

	std::string const &	getName() const;
	bool				isSigned() const;
	size_t				getSignGrade() const;
	size_t				getExecGrade() const;

	class GradeTooHighException : public std::runtime_error
	{
		public:
			GradeTooHighException() : std::runtime_error("This grade is too high.") {}
	};

	class GradeTooLowException : public std::runtime_error
	{
		public:
			GradeTooLowException() : std::runtime_error("This grade is too low.") {}
	};

	private:
	AForm();

	std::string const	_name;
	bool				_signed;
	size_t const		_sign_grade;
	size_t const		_exec_grade;
};

std::ostream&	operator<<(std::ostream& os, AForm const & form);

#endif