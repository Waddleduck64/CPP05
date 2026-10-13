#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string_view target): AForm("PresidentialPardonForm", 145, 137), _target(target)
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
	std::string filename = _target + "_shrubbery";
	std::ofstream treefile(filename);
	treefile <<
	"       _-_               _-_               _-_               _-_               _-_               _-_" "\n"
	"    /~~   ~~\\         /~~   ~~\\         /~~   ~~\\         /~~   ~~\\         /~~   ~~\\         /~~   ~~\\" "\n"
	" /~~         ~~\\   /~~         ~~\\   /~~         ~~\\   /~~         ~~\\   /~~         ~~\\   /~~         ~~\\" "\n"
	"{               } {               } {               } {               } {               } {               }" "\n"
	" \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /" "\n"
	"   ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~" "\n"
	"_- -   | | _- _   _- -   | | _- _   _- -   | | _- _   _- -   | | _- _   _- -   | | _- _   _- -   | | _- _" "\n"
	"  _ -  | |   -_     _ -  | |   -_     _ -  | |   -_     _ -  | |   -_     _ -  | |   -_     _ -  | |   -_" "\n"
	"      // \\\\             // \\\\             // \\\\             // \\\\             // \\\\             // \\\\" << std::endl;
	treefile.close();
}
/*		Private		*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 145, 137), _target("default")
{}
