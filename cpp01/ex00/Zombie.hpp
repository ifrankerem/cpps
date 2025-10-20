/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 08:36:46 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 11:41:50 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
