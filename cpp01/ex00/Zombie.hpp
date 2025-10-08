/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 08:36:46 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/08 09:10:39 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class Zombie
{
	private :
	std::string name; 
	public :
	void announce(void);
	Zombie* newZombie( std::string name );
	std::string getName(Zombie *zombie);
	std::string Zombie::setName(std::string name);


	
};