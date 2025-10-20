/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:52:29 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 13:19:59 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string _name;
	Weapon* _weapon;
	public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack();
};

#endif