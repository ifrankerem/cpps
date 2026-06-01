#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "Intern.hpp"
#include <climits>
#include <cstdlib> // std::rand, std::srand
#include <ctime>   // std::time

int main()
{
	std::srand(std::time(NULL)); //for true randomness
	// try{
	// 	Bureaucrat a("a",151);
	// 	std::cout << a << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try{
	// 	Bureaucrat b("b",-31);
	// 	std::cout << b << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try{
	// 	Bureaucrat c("c",INT_MAX);
	// 	std::cout << c << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	Bureaucrat d("d",INT_MIN);
	// 	std::cout << d << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	Bureaucrat e("e",1);
	// 	std::cout << e << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	Bureaucrat f("f",150);
	// 	std::cout << f << std::endl;

	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try{
	// 	Bureaucrat g("g",42);
	// 	std::cout << g << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try{
	// 	Bureaucrat hate("g",42);
	// 	hate.ft_increment();
	// 	std::cout << hate << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	Bureaucrat thorne("g",42);
	// 	thorne.ft_decrement();
	// 	std::cout << thorne << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	//--------------------------------------

	// try{
	// 	PresidentialPardonForm form1("target1");
	// 	std::cout << form1 << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	RobotomyRequestForm form1("target1");
	// 	std::cout << form1 << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	ShrubberyCreationForm form1("target1");
	// 	std::cout << form1 << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	PresidentialPardonForm form1("target1");
	// 	RobotomyRequestForm form2("target1");
	// 	ShrubberyCreationForm form3("target1");

	// 	Bureaucrat Adam("Adam",4);

	// 	Adam.signForm(form1);
	// 	Adam.signForm(form2);
	// 	Adam.signForm(form3);
	// 	form1.execute(Adam);
	// 	form2.execute(Adam);
	// 	form3.execute(Adam);
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	PresidentialPardonForm form1("target2");
	// 	RobotomyRequestForm form2("target2");
	// 	ShrubberyCreationForm form3("target2");

	// 	Bureaucrat signer("Coco",26);
	// 	Bureaucrat executor("Adam",4);

	// 	signer.signForm(form1);
	// 	signer.signForm(form2);
	// 	signer.signForm(form3);
	// 	form1.execute(executor);
	// 	form2.execute(executor);
	// 	form3.execute(executor);
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try{
	// 	RobotomyRequestForm form("unsigned_target");
	// 	Bureaucrat executor("Executor", 1);

	// 	form.execute(executor);
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try{
	// 	PresidentialPardonForm form("target4");

	// 	Bureaucrat signer("HighSigner", 1);
	// 	Bureaucrat executor("WeakExecutor", 10);

	// 	signer.signForm(form);
	// 	form.execute(executor);
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	//--------------------------------------

	try
	{
		Intern intern;

		AForm* form1 = intern.makeForm("presidential pardon", "target1");
		AForm* form2 = intern.makeForm("robotomy request", "target2");
		AForm* form3 = intern.makeForm("shrubbery creation", "target3");

		Bureaucrat boss("Boss", 1);

		if (form1)
		{
			boss.signForm(*form1);
			form1->execute(boss);
			delete form1;
		}
		if (form2)
		{
			boss.signForm(*form2);
			form2->execute(boss);
			delete form2;
		}
		if (form3)
		{
			boss.signForm(*form3);
			form3->execute(boss);
			delete form3;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* form = intern.makeForm("UnknownForm", "target");

		// try{
		// 	boss.signForm(*form);
		// 	form->execute(boss);
		// 	delete form;
		// }
		// catch(std::exception &e){
		// 	std::cout << e.what() << std::endl;
		// } its not like java there is no unchecked exceptation for cpp

		if (form)
			delete form;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm* form = intern.makeForm("robotomy request", "unsigned_target");

		if (form)
		{
			try
			{
				form->execute(boss);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		Intern intern;
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("WeakExecutor", 10);

		AForm* form = intern.makeForm("presidential pardon", "target4");

		if (form)
		{
			signer.signForm(*form);

			try
			{
				form->execute(executor);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
