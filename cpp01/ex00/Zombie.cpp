/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 08:40:17 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/08 09:58:11 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
// std::string Zombie::getName(Zombie *zombie)
// {
// 	return(this->name);
// }
void Zombie::setName(std::string name)
{
	this->name = name;
}
Zombie* newZombie( std::string name )
{
	Zombie *zombie = new(Zombie);
	(*zombie).setName(name);
	return(zombie);
}
void randomChump( std::string name )
{
	Zombie *zombie = newZombie(name);
	zombie->announce();
	delete(zombie);
}
