/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:36:34 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 15:49:38 by iarslan          ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
	int i = 0;
	std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*funcPTR[4])(void);
	funcPTR[0] = &Harl::debug;
	funcPTR[1] = &Harl::info;
	funcPTR[2] = &Harl::warning;
	funcPTR[3] = &Harl::error;
	// void(Harl::*funcPTR[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error}
	while(i < 4 && options[i] != level)
		i++;
	if(i < 4)
		(this->*funcPTR[i])();
	else
		std::cout << "There is no mode called " << level << " in HARL" << std::endl;
}
