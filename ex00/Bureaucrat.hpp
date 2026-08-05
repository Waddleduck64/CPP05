#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <string_view>
# include <iostream>

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

	protected:
	Bureaucrat();

	std::string const	_name;
	size_t				_grade;
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const & bureaucrat);

#endif