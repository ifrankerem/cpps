#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern's constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern's copy constructor" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern's destructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern's copy assignment constructor" << std::endl;
	if(this != &other)
		(void)other; // there is no field for copy
	return(*this);
}

AForm* Intern::createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}
AForm* Intern::createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::createShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string options[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm*(Intern::*funcs[3])(std::string const &);
	funcs[0] = &Intern::createPresidentialPardonForm;
	funcs[1] = &Intern::createRobotomyRequestForm;
	funcs[2] = &Intern::createShrubberyCreationForm;
	for(int i = 0; i < 3; i++)
	{
		if(name == options[i])
		{
			std::cout << "Intern creates " << options[i] << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cerr << "Intern cannot create " << name << std::endl;
	return 0;
}