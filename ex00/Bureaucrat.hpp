#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include <string_view>

class Bureaucrat
{
	public:
	Bureaucrat(std::string_view name, size_t grade);
	Bureaucrat(Bureaucrat const & original);
	
	virtual ~Bureaucrat();
	
	Bureaucrat&	operator=(Bureaucrat const & original);

	void	incGrade();
	void	decGrade();

	std::string const &	getName() const;
	size_t				getGrade() const;

	class GradeTooHighException : public std::runtime_error
	{
		public:
			GradeTooHighException() : std::runtime_error("The grade cannot be this high.") {}
	};

	class GradeTooLowException : public std::runtime_error
	{
		public:
			GradeTooLowException() : std::runtime_error("The grade cannot be this low.") {}
	};

	protected:
	Bureaucrat();

	std::string const	_name;
	size_t				_grade;
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const & bureaucrat);

#endif