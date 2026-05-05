#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {} // using Initialization list
Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw()
{	
	return _message.c_str(); // c style string
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {} // using Initialization list
Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw()
{	
	return _message.c_str();  // c style string
}

Form::Form(std::string name, int s_grade, int e_grade) : _name(name) , _s_grade(s_grade) , _e_grade(e_grade)
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

Form::Form(const Form& other) : _name(other._name) , _s_grade(other._s_grade) , _e_grade(other._e_grade)
{
	std::cout << "Forms's copy constructor" << std::endl;
	*this = other;
}

Form::~Form()
{
	std::cout << "Forms's destructor" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
		this->indicator = other.indicator;
	return(*this);
}

std::string Form::getName() const
{
	return(this->_name);
}

bool Form::getindicator() const
{
	return(this->indicator);
}

int Form::get_s_grade() const
{
	return(this->_s_grade);
}


int Form::get_e_grade() const
{
	return(this->_e_grade);
}

void Form::beSigned(Bureaucrat& obj)
{
	if(obj.getGrade() <= this->_s_grade)
		this->indicator = true;
	else
		throw GradeTooLowException("Bureaucrat's grade is too low for signing!");
}


std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << "Form Name: " << obj.getName() << " Indıcator: " << obj.getindicator() << " Sign Grade: " << obj.get_s_grade() << " Execute Grade: " << obj.get_e_grade();
	return(out);
}
