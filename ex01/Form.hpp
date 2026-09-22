#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>
# include <string>
# include <string_view>

class Form
{
	public:
	Form(std::string_view name, size_t sign_grade, size_t exec_grade);
	Form(Form const & original);

	virtual ~Form();

	Form& operator=(Form const & original);

	void	beSigned(Bureaucrat const & bureaucrat);

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
	Form();

	std::string	const	_name;
	bool				_signed;
	size_t const		_sign_grade;
	size_t const		_exec_grade;
};

std::ostream&	operator<<(std::ostream& os, Form const & form);

#endif