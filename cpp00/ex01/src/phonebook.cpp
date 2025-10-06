/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:48:07 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/06 02:58:45 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

PhoneBook::PhoneBook(void) // constructor
{
	//std::cout << "PhoneBook is created" << std::endl;
	this->count = 0;
	this->index = 0;
}
PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook is cleaned" << std::endl;
	return ;
}
void PhoneBook::set_phonebook(Contact contact)
{
	this->l_contact[index] = contact;
	this->index = (this->index + 1) % 8;
	if (this->count < 8)
		this->count++;
}
static std::string line()
{
	std::string x;
	for (int i = 0; i < 45; i++)
		x += '-';
	return (x);
}
void PhoneBook::print_list(void)
{
	int	i;
	int	j;

	i = -1;
	std::cout << line() << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX"
				<< "|" << std::setw(10) << "NAME"
				<< "|" << std::setw(10) << "LASTNAME"
				<< "|" << std::setw(10) << "NICKNAME"
				<< "|" << std::endl;
	std::cout << line() << std::endl;
	while (++i <= this->count - 1)
	{
		j = i + 1;
		std::cout << "|" << std::setw(10) << j << "|" << std::setw(10) << this->l_contact[i].getter("NAME") << "|" << std::setw(10) << this->l_contact[i].getter("LASTNAME") << "|" << std::setw(10) << this->l_contact[i].getter("NICKNAME") << "|" << std::endl;
		std::cout << line() << std::endl;
	}
}
void PhoneBook::print_one(int idx)
{
	std::cout << "First Name: " << this->l_contact[idx].getter("NAME") << std::endl;
	std::cout << "Last Name: " << this->l_contact[idx].getter("LASTNAME") << std::endl;
	std::cout << "Nickame: " << this->l_contact[idx].getter("NICKNAME") << std::endl;
	std::cout << "Phone Number: " << this->l_contact[idx].getter("NUMBER") << std::endl;
	std::cout << "Darkest Secret: " << this->l_contact[idx].getter("SECRET") << std::endl;
}

int PhoneBook::listsize(void)
{
	return(this->count);
}
