#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {} // using Initialization list
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{	
	return _message.c_str(); // c style string
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {} // using Initialization list
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{	
	return _message.c_str();  // c style string
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)  
{
	std::cout << "Bureaucrat's constructor" << std::endl;
	if(grade > 150)
		throw GradeTooLowException("Grade is too low!");
	else if(grade < 1)
		throw GradeTooHighException("Grade is too high!");
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Bureaucrat's copy constructor" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat's destructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat's copy assignment constructor" << std::endl;
	if(this != &other)
		this->_grade = other._grade;
	return(*this);
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const 
{
	return this->_grade;
}

void Bureaucrat::ft_increment(int value)
{
	if(this->_grade - value < 1)
		throw GradeTooHighException("Increment value is too much!");
	else 
		this->_grade -= value;
}

void Bureaucrat::ft_decrement(int value)
{
	if(this->_grade + value > 150)
		throw GradeTooLowException("Decrement value is too much!");
	else 
		this->_grade += value;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return(out);
}

void Bureaucrat::signForm(AForm &obj)
{
	try{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign "<< obj.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	std::cout << this->getName() << "executed" << form.getName() << std::endl;
}

