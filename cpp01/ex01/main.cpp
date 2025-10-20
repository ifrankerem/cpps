/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:36:23 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 15:04:05 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;

	int N = 5;
	zombies = zombieHorde(N, "murat");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	return(0);
}
