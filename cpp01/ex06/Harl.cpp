/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:36:34 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 05:16:17 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	//std::cout << "Harl is READY!!" << std::endl;
}
Harl::~Harl()
{
	return;
}
void Harl::debug(void)
{
	std::cout << "DEBUG MODE ACTİVATE!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "INFO MODE ACTİVATE!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "WARNING MODE ACTİVATE!" << std::endl;
}
void Harl::error(void)
{
	std::cout << "ERROR MODE ACTİVATE!" << std::endl;
}
void Harl::complain(std::string level)
{
	int i = 0;
	std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*funcPTR[4])(void); //pointer to a function
	funcPTR[0] = &Harl::debug;
	funcPTR[1] = &Harl::info;
	funcPTR[2] = &Harl::warning;
	funcPTR[3] = &Harl::error;
	// void(Harl::*funcPTR[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error}
	while(i < 4 && options[i] != level)
		i++;
	switch(i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*funcPTR[0])();
			/* fall through */
			case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*funcPTR[1])();
			/* fall through */
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*funcPTR[2])();
			/* fall through */
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*funcPTR[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return;
}
