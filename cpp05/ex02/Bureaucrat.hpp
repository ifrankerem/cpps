#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		class GradeTooHighException : public std::exception {
			private:
			std::string _message;	

			public:
			GradeTooHighException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::exception {
		
			private:
			std::string _message;

			public:
			GradeTooLowException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooLowException() throw();
		};	

		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string getName() const;
		int getGrade() const;
		void ft_increment();
		void ft_decrement();
		void signForm(AForm &obj);
		void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);


#endif