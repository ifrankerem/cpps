/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:48:42 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/19 21:29:49 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
	std::string _name;
	Weapon& _weapon;
	public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack();
};

#endif