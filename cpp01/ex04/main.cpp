/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:16:16 by iarslan           #+#    #+#             */
/*   Updated: 2025/10/20 14:04:18 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream> // for ifstream and ofstream

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		std::cout << "Please use this program as ./sed filename string1 string2" << std::endl;
		return -1;
	}
	std::string line;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream input_file(argv[1]);
	if(!input_file.is_open())
	{
		std::cerr << "Couldn't open the file!" << std::endl;
		input_file.close();
		return -1;
	}
	if(s1.empty())
	{
		std::cerr << "string 1 cannot be empty!!" << std::endl;
		return -1;
	}
	std::string output_name = argv[1];
	output_name += ".replace";
	std::ofstream output_file(output_name.c_str());
	if(!output_file.is_open())
	{
		std::cerr << "Couldn't create the file!" << std::endl;
		output_file.close();
		input_file.close();
		return -1;
	}
	while(std::getline(input_file,line))
	{
		size_t index = line.find(s1);
		while(index != std::string::npos)
		{
			std::string n_line = line.substr(0,index);
			output_file << n_line;
			output_file << s2;
			line = line.substr(index + s1.size());
			index = line.find(s1);
		}
		if(input_file.peek() == EOF)
			output_file << line;
		else
			output_file << line << std::endl;
	}
	input_file.close();
	output_file.close();
	return 0;
}