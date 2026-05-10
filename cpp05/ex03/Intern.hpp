#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm* createPresidentialPardonForm(std::string const &target);
		AForm* createRobotomyRequestForm(std::string const &target);
		AForm* createShrubberyCreationForm(std::string const &target);

	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		AForm* makeForm(std::string const &name, std::string const &target);

};

#endif