/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:46:06 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 16:13:19 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
  private:
	std::string type;

  public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType() const;
	void setType(std::string type);
};

#endif