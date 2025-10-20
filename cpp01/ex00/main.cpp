/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:28:41 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 15:00:08 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie;
	zombie = newZombie("murat");
	zombie->announce();
	delete(zombie);
	randomChump("kerem");
	return (0);
}