/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:36:20 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 12:14:41 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}
void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void	Zombie::setName(std::string name)
{
	this->name = name;
}

