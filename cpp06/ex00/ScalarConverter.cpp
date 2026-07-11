#include "ScalarConverter.hpp"
#include <limits.h>
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
	int flag0 = 0;
	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	bool impossible = false;
	std::string char_output = "char: Non displayable";
	const char *str = literal.c_str();
	if(literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if(literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inff" << std::endl;
		return;
	}
	if(literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inff" << std::endl;
		return;
	}
	for(int i = 0; i < static_cast<int>(literal.length()); i++)
	{
		if((literal[i] != 'f' || literal[i] != '+' || literal[i] != '-' || literal[i] != '.') && (literal[i] < 48 && literal[i] > 57))
			flag0++;
		else if(literal[i] == 'f')
			flag++;
		else if(literal[i] == '+')
			flag1++;
		else if(literal[i] == '-')
			flag2++;
		else if(literal[i] == '.')
			flag3++;
		if(flag0 >= 2 || flag >= 2 || flag1 >= 2 || flag2 >= 2 || flag3 >= 2)
			impossible = true;
	}
	if(impossible == true)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if(literal.length() == 1)
	{
		if((literal[0] > 31) && (literal[0]< 127))
		{
			c_value = static_cast<char>(literal[0]);
			std::cout << "char: " << c_value << std::endl;
		}
		else
			std::cout << char_output << std::endl;
		i_value = static_cast<int>(literal[0]);
		f_value = static_cast<float>(literal[0]);
		d_value = static_cast<double>(literal[0]);
		std::cout << "int: " << i_value << std::endl;
		std::cout << "float: " << f_value << ".0f" << std::endl;
		std::cout << "double: " << d_value << ".0" << std::endl;
		return;
	}
	else
	{
		f_value = atof(str);
		if(f_value > INT_MAX || f_value < INT_MIN)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f_value << std::endl;
			d_value = static_cast<double>(f_value);
			std::cout << "float: " << f_value << ".0f" << std::endl;
			std::cout << "double: " << d_value << ".0" << std::endl;
			return;
		}
		if(f_value > 127 || f_value < 0)
		{
			std::cout << "char: impossible" << std::endl;
			i_value = static_cast<int>(f_value);
			f_value = static_cast<float>(f_value);
			d_value = static_cast<double>(f_value);
			std::cout << "int: " << i_value << std::endl;
			std::cout << "float: " << f_value << ".0f" << std::endl;
			std::cout << "double: " << d_value << ".0" << std::endl;
			return;
		}
	}

	
}
