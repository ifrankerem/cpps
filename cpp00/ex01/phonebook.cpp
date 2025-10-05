/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 23:08:38 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/05 03:56:46 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact()
	{
		std::string first_name = "";
		std::string last_name = "";
		std::string nickname = "";
		std::string phone_number = "";
		std::string darkest_secret = "";
	}

	std::string adjust_firstname(std::string newvalue)
	{
		if (newvalue.size() != 0)
			first_name = newvalue;
		return (first_name);
	}
	std::string adjust_lastname(std::string newvalue)
	{
		if (newvalue.size() != 0)
			last_name = newvalue;
		return (last_name);
	}
	std::string adjust_nickname(std::string newvalue)
	{
		if (newvalue.size() != 0)
			nickname = newvalue;
		return (nickname);
	}
	std::string adjust_phone_number(std::string newvalue)
	{
		if (newvalue.size() != 0)
			phone_number = newvalue;
		return (phone_number);
	}
	std::string adjust_darkest_secret(std::string newvalue)
	{
		if (newvalue.size() != 0)
			darkest_secret = newvalue;
		return (darkest_secret);
	}
	// bunlar bir method veya member function
};

class PhoneBook
{
  private:
	int count;
	int index;
	Contact l_contact[8];

  public:
	PhoneBook() // constructor
	{
		count = 0;
		index = 0;
	}
	void set_phonebook(Contact contact)
	{
		l_contact[index] = contact;
		index = (index + 1) % 8;
		if (count < 8)
			count++;
	}
	void print_list()
	{
		int i = -1;
		while (++i <= index - 1)
			std::cout << i << "|" << l_contact[i].adjust_firstname("") << "|" << l_contact[i].adjust_lastname("") << "|" << l_contact[i].adjust_nickname("") << std::endl;
	}
	void print_one(int idx)
	{
		std::cout << "First Name: " << l_contact[idx].adjust_firstname("") << std::endl;
		std::cout << "Last Name: " << l_contact[idx].adjust_lastname("") << std::endl;
		std::cout << "Nickame: " << l_contact[idx].adjust_nickname("") << std::endl;
		std::cout << "Phone Number: " << l_contact[idx].adjust_phone_number("") << std::endl;
		std::cout << "Darkest Secret: " << l_contact[idx].adjust_darkest_secret("") << std::endl;
	}
};

int	main(void)
{
	int			x;
	Contact		contact;
	PhoneBook	pb;

	std::string input;
	std::string command;
	while (1)
	{
		std::cout << "Please type one of these commands 'ADD' 'SEARCH' 'EXIT'" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			std::string temp;
			std::cout << "Please write infos about who u wanna add in the phonebook!" << std::endl;
			std::cout << "Name: ";
			contact.adjust_firstname((std::getline(std::cin, temp), temp));
			std::cout << "LastName: ";
			contact.adjust_lastname((std::getline(std::cin, temp), temp));
			std::cout << "Nickname: ";
			contact.adjust_nickname((std::getline(std::cin, temp), temp));
			std::cout << "Phone Number: ";
			contact.adjust_phone_number((std::getline(std::cin, temp), temp));
			std::cout << "Darkest Secret: ";
			contact.adjust_darkest_secret((std::getline(std::cin, temp), temp));
			pb.set_phonebook(contact);
		}
		else if (command == "SEARCH")
		{
			pb.print_list();
			std::cout << "Enter index of contact to display: ";
			std::getline(std::cin, input);
			//! buraya tekrar bak stringten int dönüsümü yapılacak
			pb.print_one(x);
		}
		else if (command == "EXIT")
		{
			return (0);
		}
	}
	return (0);
}
//#todo
// .hpp dosyalarını main.cpp dosyalarını ayarla!!
//satır 137 bak!
//koda calıs ve cpp00 bitirip diğer insanların örneklerine bak iyice derinlemesine öğren