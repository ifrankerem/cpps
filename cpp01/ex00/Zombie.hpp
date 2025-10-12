/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 08:36:46 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/12 16:56:07 by iarslan          ###   ########.fr       */
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
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
