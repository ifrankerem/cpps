#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if(this != &other)
		*this = other;
	return(*this);
}

void ScalarConverter::convert(const std::string literal)
{
	char c_value;
	int i_value;
	float f_value;
	double d_value;
	std::string char_output = "char: Non displayable";
	const char *str = literal.c_str();
	// if(literal.size() == 1)
	// {
	// 	if(literal[0] < '0' || literal[0] > '9')
	// 	{
	// 		c_value = literal[0];
	// 		i_value = static_cast<int>(c_value);
	// 		f_value = static_cast<float>(c_value);
	// 		d_value = static_cast<double>(c_value);
	// 		std::cout << "char: " << c_value << std::endl;
	// 		std::cout << "int: " << i_value << std::endl;
	// 		std::cout << "float: " << f_value << ".0f" << std::endl;
	// 		std::cout << "double: " << d_value << ".0" << std::endl;
	// 	}
	// 	else
	// 	{
	// 		i_value = atoi(str);
	// 		f_value = static_cast<float>(i_value);
	// 		d_value = static_cast<double>(i_value);
	// 		std::cout << char_output << std::endl;
	// 		std::cout << "int: " << i_value << std::endl;
	// 		std::cout << "float: " << f_value << ".0f" << std::endl;
	// 		std::cout << "double: " << d_value << ".0" << std::endl;
	// 	}
	// }
	// else
	// {
	// 	bool flag = false;
	// 	for(int i = 0; i < (int)literal.size(); i++)
	// 	{
	// 		if((literal[i] > '0' || literal[i] > '9') && (literal[i+1] > '0' || literal[i+1] > '9'))
	// 		 	flag = true;
	// 		else
	// 			flag = false;
	// 	} 
	// 	if(flag == true) //?
	// 	{
	// 		std::cout << "char: impossible" << std::endl;
	// 		std::cout << "int: impossible" << std::endl;
	// 		std::cout << "float: impossible" << std::endl;
	// 		std::cout << "double: impossible" << std::endl;
	// 		return ;
	// 	}
	// 	else
	// 	{
	// 		i_value = atoi(str);
	// 		f_value = static_cast<float>(i_value);
	// 		d_value = static_cast<double>(i_value);
	// 		c_value = static_cast<char>(i_value);
	// 		std::cout << "char: " << c_value << std::endl;
	// 		std::cout << "int: " << i_value << std::endl;
	// 		std::cout << "float: " << f_value << ".0f" << std::endl;
	// 		std::cout << "double: " << d_value << ".0" << std::endl;

	// 	}
	// 	if(literal[literal.size() - 1] == 'f')
	// 	{
	// 		f_value = static_cast<float>(atof(str));
	// 		d_value = atof(str);
	// 		i_value = static_cast<int>(atof(str));
	// 		c_value = static_cast<char>(i_value);
	// 		std::cout << "char: " << c_value << std::endl;
	// 		std::cout << "int: " << i_value << std::endl;
	// 		std::cout << "float: " << f_value << ".0f" << std::endl;
	// 		std::cout << "double: " << d_value << ".0" << std::endl;
	// 	}
	// 	else if(literal.find('.') != std::string::npos)
	// 	{
	// 		d_value = atof(str);
	// 		f_value = static_cast<float>(d_value);
	// 		i_value = static_cast<int>(d_value);
	// 		c_value = static_cast<char>(i_value);
	// 		std::cout << "char: " << c_value << std::endl;
	// 		std::cout << "int: " << i_value << std::endl;
	// 		std::cout << "float: " << f_value << ".0f" << std::endl;
	// 		std::cout << "double: " << d_value << std::endl;
	// 	}
	// }

}