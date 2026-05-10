#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {} // using Initialization list
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char* AForm::GradeTooHighException::what() const throw()
{	
	return _message.c_str(); // c style string
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {} // using Initialization list
AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char* AForm::GradeTooLowException::what() const throw()
{	
	return _message.c_str();  // c style string
}

AForm::notSignedException::notSignedException(const std::string& message) : _message(message) {} // using Initialization list
AForm::notSignedException::~notSignedException() throw() {}

const char* AForm::notSignedException::what() const throw()
{	
	return _message.c_str();  // c style string
}

AForm::AForm(std::string name, int s_grade, int e_grade) : _name(name) , _s_grade(s_grade) , _e_grade(e_grade)
{
	if(s_grade > 150)
		throw GradeTooLowException("Sign grade is so low!");
	else if(s_grade < 1)
		throw GradeTooHighException("Sign grade is so high!");
	else if(e_grade > 150)
		throw GradeTooLowException("Execute grade is so low!");
	else if(e_grade < 1)
		throw GradeTooHighException("Execute grade is so high!");
	this->indicator = false;
}

AForm::AForm(const AForm& other) : _name(other._name) , _s_grade(other._s_grade) , _e_grade(other._e_grade)
{
	std::cout << "AForms's copy constructor" << std::endl;
	*this = other;
}

AForm::~AForm()
{
	std::cout << "AForms's destructor" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		this->indicator = other.indicator;
	return(*this);
}

std::string AForm::getName() const
{
	return(this->_name);
}

bool AForm::getindicator() const
{
	return(this->indicator);
}

int AForm::get_s_grade() const
{
	return(this->_s_grade);
}


int AForm::get_e_grade() const
{
	return(this->_e_grade);
}

void AForm::beSigned(Bureaucrat& obj)
{
	if(obj.getGrade() <= this->_s_grade)
		this->indicator = true;
	else
		throw GradeTooLowException("Bureaucrat's grade is too low for signing!");
}

void AForm::ft_check_req(Bureaucrat const &executor) const
{
	if(this->getindicator() == false)
		throw notSignedException("Form is not signed!");
	if(executor.getGrade() > this->get_e_grade())
		throw GradeTooLowException(executor.getName() +" is too low to execute it!");
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << "AForm Name: " << obj.getName() << " Indıcator: " << obj.getindicator() << " Sign Grade: " << obj.get_s_grade() << " Execute Grade: " << obj.get_e_grade();
	return(out);
}
