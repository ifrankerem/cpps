/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:23:07 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 01:58:13 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
	void debug( void );
 	void info( void );
	void warning( void );
	void error( void );
	public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif