/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:36:16 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 16:49:16 by iarslan          ###   ########.fr       */
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
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);