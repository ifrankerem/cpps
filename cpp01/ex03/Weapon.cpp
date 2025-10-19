/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:46:08 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/19 21:31:06 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}
Weapon::~Weapon()
{
	return;
}
std::string& Weapon::getType()
{
	std::string &ref_type = this->type;
	return(ref_type);
}
std::string& Weapon::setType(std::string name)
{
	std::string &ref_type = this->type;
	ref_type = name;
	return(ref_type);
}
