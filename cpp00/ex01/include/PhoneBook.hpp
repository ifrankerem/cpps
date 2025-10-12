/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:46:15 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/12 00:22:46 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
  private:
	int count;
	int index;
	Contact l_contact[8];

  public:
	PhoneBook(void);
	~PhoneBook(void);
	void set_phonebook(Contact contact);
	void print_list(void);
	void print_one(int idx);
	int listsize(void);

};

#endif