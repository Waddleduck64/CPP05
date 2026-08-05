#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string_view name, size_t grade): _name(name), _grade(grade)
{
	if (grade < 1 || grade > 150)
	{
		//exception?????? //either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & original): _name(original._name), _grade(original._grade)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & original)
{
	if (this == &original)
		return *this;
	// _name = original._name; // We cannot do this because _name is const.
	_grade = original._grade;
	return *this;
}

void	Bureaucrat::incGrade()
{
	if (_grade <= 1)
	{
		//exception??????
	}
	_grade--;
}

void	Bureaucrat::decGrade()
{
	if (_grade >= 150)
	{
		//exception??????
	}
	_grade++;
}

std::string	const &	Bureaucrat::getName() const
{
	return _name;
}

size_t				Bureaucrat::getGrade() const
{
	return _grade;
}

/*		Protected		*/

Bureaucrat::Bureaucrat(): _name("Hermes Conrad"), _grade(1)
{}

//////////////////////////////////////

std::ostream&	operator<<(std::ostream& os, Bureaucrat const & bureaucrat)
{
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}
