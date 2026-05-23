#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

	const std::string _name;
	bool indicator;
	const int _s_grade;
	const int _e_grade;

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

		Form(std::string name, int s_grade, int e_grade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		void beSigned(const Bureaucrat& obj);
		std::string getName() const;
		bool getindicator() const;
		int get_s_grade() const;
		int get_e_grade() const;
};

std::ostream& operator<<(std::ostream& out, const Form& obj);


#endif
