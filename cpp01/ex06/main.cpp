/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:18:25 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 04:50:31 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if(argc != 2)
		std::cout << "Please use this program as ./harlFilter 'OPTION'" << std::endl;
	Harl harl;
	harl.complain(argv[1]);
}