/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:54:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/06 03:16:39 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

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
		std::getline(std::cin, command);
		// if (command.empty())
		// 	continue ; buraya bak bazen menü 2 defa basılıyor!!!
		if (command == "ADD")
		{
			std::string temp;
			std::cout << "Please write infos about who u wanna add in the phonebook!" << std::endl;
			std::cout << "Name: ";
			contact.set_firstname();
			std::cout << "LastName: ";
			contact.set_lastname();
			std::cout << "Nickname: ";
			contact.set_nickname();
			std::cout << "Phone Number: ";
			contact.set_number();
			std::cout << "Darkest Secret: ";
			contact.set_secret();
			pb.set_phonebook(contact);
		}
		else if (command == "SEARCH")
		{
			pb.print_list();
			std::cout << "Enter index of contact to display,if you want to exit please type 0 : ";
			while (1)
			{
				std::getline(std::cin, input);
				x = std::atoi(input.c_str());
				if (input.length() != 1 || !isdigit(input[0]) || x == 9)
					std::cout << "Please enter values from 0-8: ";
				else if (x > pb.listsize())
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