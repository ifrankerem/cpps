/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:18:25 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 16:58:09 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "Please use this program as ./harlFilter LEVEL" << std::endl;
		return -1;
	}
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}