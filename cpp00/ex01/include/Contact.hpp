/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:43:34 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/12 02:02:04 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip> // setw
#include <iostream> //std::cout , std::cin ...
#include <string>  // std::string , std::getline()

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact();
	~Contact();
	int set_firstname();
	int set_lastname();
	int set_nickname();
	int set_number();
	int set_secret();
	std::string getter(std::string option);
};

#endif