#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm",145,137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm's destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return(*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) , _target(other._target)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->ft_check_req(executor);

	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str()); // the same thing as fstream + ios::out . wants const char * (c_str())

	if(file.is_open())
	{
		file << "          &&& &&  & &&\n";
		file << "      && &\\/&\\|& ()|/ @, &&\n";
		file << "      &\\/(/&/&||/& /_/)_&/_&\n";
		file << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
		file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		file << "&&   && & &| &| /& & % ()& /&&\n";
		file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
		file << "     &&     \\|||\n";
		file << "             |||\n";
		file << "             |||\n";
		file << "             |||\n";
		file << "       , -=-~  .-^- _\n";

		file.close();
	}
	else
		std::cerr << "Unable to open file!" << std::endl;
}


std::string ShrubberyCreationForm::getTarget() const {
	return(this->_target);
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& obj)
{
	out << "AForm Name: " << obj.getName() << " Indicator: " << obj.getindicator() << " Sign Grade: " << obj.get_s_grade() << " Execute Grade: " << obj.get_e_grade() << " Target Name: " << obj.getTarget();
	return(out);
}
