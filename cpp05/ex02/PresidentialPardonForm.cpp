#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name, int s_grade, int e_grade) : _name(name) , _s_grade(s_grade) , _e_grade(e_grade)
{
	if(s_grade > 150)
		throw GradeTooLowException("Sign grade is so low!");
	else if(s_grade < 1)
		throw GradeTooHighException("Sign grade is so high!");
	else if(e_grade > 150)
		throw GradeTooLowException("Execute grade is so low!");
	else if(e_grade < 1)
		throw GradeTooHighException("Execute grade is so high!");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm's destructor" << std::endl;
}

void execute(Bureaucrat const & executor) const
{
	if()
}
