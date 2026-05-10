#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

	std::string _target;

	public:
		ShrubberyCreationForm(std::string const &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& obj);

#endif