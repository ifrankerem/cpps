/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 00:46:27 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 16:58:55 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string x = "HI THIS IS BRAIN";
	std::string* stringPTR = &x;
	std::string& stringREF = x;
	
	std::cout << "Address of string: " << &x << std::endl;
	std::cout << "Address of held by ptr: " << stringPTR << std::endl;
	std::cout << "Address of held by ref: " << &stringREF << std::endl;

	std::cout << "The value of string variable: " << x << std::endl;
	std::cout << "The value pointed by ptr: "<< *stringPTR << std::endl;
	std::cout << "The value pointed by ref: "<<  stringREF << std::endl;
	return 0;
}
