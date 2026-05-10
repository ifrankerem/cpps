#include "PresidentialPardonForm.hpp"

#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm",25,5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm's destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return(*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) , _target(other._target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->ft_check_req(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return(this->_target);
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& obj)
{
	out << "AForm Name: " << obj.getName() << " Indıcator: " << obj.getindicator() << " Sign Grade: " << obj.get_s_grade() << " Execute Grade: " << obj.get_e_grade() << " Target Name: " << obj.getTarget();
	return(out);
}
