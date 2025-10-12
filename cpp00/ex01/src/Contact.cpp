/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:54:47 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/12 02:04:01 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	//std::cout << "Contact is created" << std::endl;
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}
Contact::~Contact(void)
{
	//std::cout << "Contact is cleaned" << std::endl;
	return ;
}

static int is_nbr(std::string x)
{
	for(size_t i = 0; i < x.size();i++)
	{
		if(!std::isdigit(x[i]))
			return -1;
	}
	return 1;
	
}
int Contact::set_firstname()
{
	int	error_flag;

	error_flag = 0;
	while (1)
	{
		if (error_flag == 1)
		{
			std::cout << "This section cant be empty!" << std::endl;
			std::cout << "Name: ";
		}
		if(!std::getline(std::cin, first_name))
			return -1;
		else if (first_name.size() != 0)
			break ;
		else
			error_flag = 1;
	}
	return 0;
}

int Contact::set_lastname()
{
	int	error_flag;

	error_flag = 0;
	while (1)
	{
		if (error_flag == 1)
		{
			std::cout << "This section cant be empty!" << std::endl;
			std::cout << "LastName: ";
		}
		if(!std::getline(std::cin, last_name))
			return -1;
		else if (last_name.size() != 0)
			break ;
		else
			error_flag = 1;
	}
	return 0;
}

int Contact::set_nickname()
{
	int	error_flag;

	error_flag = 0;
	while (1)
	{
		if (error_flag == 1)
		{
			std::cout << "This section cant be empty!" << std::endl;
			std::cout << "Nickname: ";
		}
		if(!std::getline(std::cin, nickname))
			return -1;
		else if (nickname.size() != 0)
			break ;
		else
			error_flag = 1;;
	}
	return 0;
}

int Contact::set_number()
{
	int	error_flag;

	error_flag = 0;
	while (1)
	{
		if (error_flag == 1)
		{
			std::cout << "This section cant be empty!" << std::endl;
			std::cout << "Phone Number: ";
		}
		if(!std::getline(std::cin, phone_number))
			return -1;
		else if(is_nbr(phone_number) == -1)
			{
				std::cout << "Please enter a number!!" << std::endl;
				std::cout << "Phone Number: ";
			}			
		else if (phone_number.size() != 0)
			break ;
		else
			error_flag = 1;
	}
	return 0;
}

int Contact::set_secret()
{
	int	error_flag;

	error_flag = 0;
	while (1)
	{
		if (error_flag == 1)
		{
			std::cout << "This section cant be empty!" << std::endl;
			std::cout << "Darkest Secret: ";
		}
		if(!std::getline(std::cin, darkest_secret))
			return -1;
		else if (darkest_secret.size() != 0)
			break ;
		else
			error_flag = 1;
	}
	return 0;
}
std::string Contact::getter(std::string option)
{
	if (option == "NAME")
		return (first_name);
	else if (option == "LASTNAME")
		return (last_name);
	else if (option == "NICKNAME")
		return (nickname);
	else if (option == "NUMBER")
		return (phone_number);
	else if (option == "SECRET")
		return (darkest_secret);
	return (NULL);
}
