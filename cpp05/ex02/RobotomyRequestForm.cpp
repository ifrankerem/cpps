#include "RobotomyRequestForm.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm",72,45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm's destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return(*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) , _target(other._target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->ft_check_req(executor);
	
	std::cout << "drilling noises!" << std::endl;

	if(std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else 
		std::cout << this->_target << " 's robotomy failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return(this->_target);
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& obj)
{
	out << "AForm Name: " << obj.getName() << " Indıcator: " << obj.getindicator() << " Sign Grade: " << obj.get_s_grade() << " Execute Grade: " << obj.get_e_grade() << " Target Name: " << obj.getTarget();
	return(out);
}

