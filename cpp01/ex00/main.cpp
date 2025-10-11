/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:28:41 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/08 21:34:05 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1;
	zombie1 = newZombie("kerem");
	zombie1->announce();
	//randomChump("kerem");
	return 0;
}