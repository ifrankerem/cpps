#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

		AForm(std::string name, int s_grade, int e_grade);
		virtual ~AForm() = 0;
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		void beSigned(Bureaucrat& obj);
		std::string getName() const;
		bool getindicator() const;
		int get_s_grade() const;
		int get_e_grade() const;
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);


#endif
