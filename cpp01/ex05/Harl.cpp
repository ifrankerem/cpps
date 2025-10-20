/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:36:34 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 02:41:13 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is READY!!" << std::endl;
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
	for(int j = 0; j < 4; j++)
		{
			(this->*funcPTR[j])();
			std::cout << "address of function " << &funcPTR[j] << std::endl;	
		}
	// void(Harl::*funcPTR[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error}
	while(i < 4 && options[i] != level)
		i++;
	// if(i < 4)
	// 	(this->*funcPTR[i])(); //this obj->function
	// else
	// 	std::cout << "There is no mode called " << level << " in HARL" << std::endl;
}
