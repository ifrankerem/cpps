/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:54:47 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/06 02:58:02 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

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

void Contact::set_firstname()
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
		std::getline(std::cin, first_name);
		if (first_name.size() != 0)
			break ;
		else
			error_flag = 1;
	}
}

void Contact::set_lastname()
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
		std::getline(std::cin, last_name);
		if (last_name.size() != 0)
			break ;
		else
			error_flag = 1;
	}
}

void Contact::set_nickname()
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
		std::getline(std::cin, nickname);
		if (nickname.size() != 0)
			break ;
		else
			error_flag = 1;
	}
}

void Contact::set_number()
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
		std::getline(std::cin, phone_number);
		if (phone_number.size() != 0)
			break ;
		else
			error_flag = 1;
	}
}

void Contact::set_secret()
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
		std::getline(std::cin, darkest_secret);
		if (darkest_secret.size() != 0)
			break ;
		else
			error_flag = 1;
	}
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
// bunlar bir method veya member function