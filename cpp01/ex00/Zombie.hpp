/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 08:36:46 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/08 09:56:34 by iarslan          ###   ########.fr       */
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
	void setName(std::string name);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
