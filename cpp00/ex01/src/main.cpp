/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:54:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/12 01:48:52 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	int x;
	Contact contact;
	PhoneBook pb;

	std::string input;
	std::string command;
	while (1)
	{
		std::cout << "Please type one of these commands 'ADD' 'SEARCH' 'EXIT'" << std::endl;
		if(!std::getline(std::cin,command))
			break;
		// if (command.empty())
		// 	continue ; buraya bak bazen menü 2 defa basılıyor!!!
		if (command == "ADD")
		{
			std::string temp;
			std::cout << "Please write infos about who u wanna add in the phonebook!" << std::endl;
			std::cout << "Name: ";
			if(contact.set_firstname() == -1)
				return 0;
			std::cout << "LastName: ";
			if(contact.set_lastname() == -1)
				return 0;
			std::cout << "Nickname: ";
			if(contact.set_nickname() == -1)
				return 0;
			std::cout << "Phone Number: ";
			if(contact.set_number() == -1)
				return 0;
			std::cout << "Darkest Secret: ";
			if(contact.set_secret() == -1)
				return 0;
			pb.set_phonebook(contact);
			std::cout << "Contact added to PhoneBook!" << std::endl;
		}
		else if (command == "SEARCH")
		{
			pb.print_list();
			std::cout << "Enter index of contact to display,if you want to exit please type 0 : ";
			while (1)
			{
				if(!std::getline(std::cin, input))
					return 0;
				x = input[0] - '0';
				if (input.length() != 1 || !isdigit(input[0]) || input.empty() || input[0] == '9')
					std::cout << "Please enter values from 0-8 (0 for exit): ";
				else if (x > pb.listsize() || x < 0 )
					std::cout << "There is no index " << x << " in the list. Please try again: ";
				else
					break ;
			}
			if (x == 0)
				continue ;
			pb.print_one(x - 1);
		}
		else if (command == "EXIT")
		{
			return (0);
		}
	}
	return (0);
}