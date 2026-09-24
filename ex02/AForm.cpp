#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string_view name, size_t sign_grade, size_t exec_grade): _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	_signed = false;
}

AForm::AForm(AForm const & original): _name(original._name), _signed(original._signed), _sign_grade(original._sign_grade), _exec_grade(original._exec_grade)
{}

AForm::~AForm()
{}

AForm& AForm::operator=(AForm const & original)
{
	if (this == &original)
		return *this;
	// _name = original._name; // We cannot do this because _name is const.
	_signed = original._signed;
	// _sign_grade = original._sign_grade; // We cannot do this because _sign_grade is const.
	// _exec_grade = original._exec_grade; // We cannot do this because _exec_grade is const.
	return *this;
}

void	AForm::beSigned(Bureaucrat const & signer)
{
	if (_sign_grade < signer.getGrade())
		throw GradeTooLowException();
	_signed = true;
}

std::string	const &	AForm::getName() const
{
	return _name;
}

bool				AForm::isSigned() const
{
	return _signed;
}


size_t				AForm::getSignGrade() const
{
	return _sign_grade;
}


size_t				AForm::getExecGrade() const
{
	return _exec_grade;
}

/*		Protected		*/

void	AForm::executionCheck(Bureaucrat const & executor) const
{
	if (_signed == false)
		throw FormNotSignedException();
	if (_exec_grade < executor.getGrade())
		throw GradeTooLowException();
}

/*		Private		*/

AForm::AForm(): _name("Useless Form"), _sign_grade(150), _exec_grade(150)
{}

//////////////////////////////////////

std::ostream&	operator<<(std::ostream& os, AForm const & form)
{
	os << form.getName() << ": ";
	if (form.isSigned() == false)
		os << "un";
	os << "signed, required signing grade " << form.getSignGrade() << ", ";
	os << "required executing grade " << form.getExecGrade() << ".";
	return os;
}
