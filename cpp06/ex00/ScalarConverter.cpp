#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isIntLiteral(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i = 1;

	if (i == literal.length())
		return false;

	for (; i < literal.length(); ++i)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::hasOneDot(const std::string& literal, bool endsWithF)
{
	size_t len = literal.length();
	size_t lastIndex = endsWithF ? len - 2 : len - 1;

	size_t dotCount = 0;
	size_t dotPos = std::string::npos;

	for (size_t i = 0; i < len; ++i)
	{
		if (literal[i] == '.')
		{
			dotCount++;
			dotPos = i;
		}
	}

	if (dotCount != 1)
		return false;
	if (dotPos == 0 || dotPos >= lastIndex)
		return false;
	return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& literal)
{
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;
	if (literal.find('f') != literal.length() - 1)
		return false;
	if (!hasOneDot(literal, true))
		return false;

	for (size_t i = 0; i < literal.length() - 1; ++i)
	{
		char c = literal[i];
		if (!isdigit(c) && c != '+' && c != '-' && c != '.')
			return false;
	}
	return true;
}

bool ScalarConverter::isDoubleLiteral(const std::string& literal)
{
	if (literal.empty())
		return false;
	if (!hasOneDot(literal, false))
		return false;

	for (size_t i = 0; i < literal.length(); ++i)
	{
		char c = literal[i];
		if (!isdigit(c) && c != '+' && c != '-' && c != '.')
			return false;
	}
	return true;
}

e_type ScalarConverter::detectType(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
		return PSEUDO_NAN;
	if (literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff")
		return PSEUDO_INF;
	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	if (isIntLiteral(literal))
		return INT;
	if (isFloatLiteral(literal))
		return FLOAT;
	if (isDoubleLiteral(literal))
		return DOUBLE;
	return INVALID;
}

void ScalarConverter::printChar(double value)
{
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	if (value < -FLT_MAX || value > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	e_type type = detectType(literal);

	switch (type)
	{
		case PSEUDO_NAN:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break;

		case PSEUDO_INF:
		{
			std::string sign;
			if (literal[0] == '-')
				sign = "-";
			else
				sign = "+";
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << sign << "inff" << std::endl;
			std::cout << "double: " << sign << "inf" << std::endl;
			break;
		}

		case CHAR:
		{
			double value = static_cast<double>(literal[0]);
			printChar(value);
			printInt(value);
			printFloat(value);
			printDouble(value);
			break;
		}

		case INT:
		{
			char* end;
			errno = 0;
			long x = std::strtol(literal.c_str(), &end, 10);
			if (*end != '\0')
			{
				printImpossible();
				break;
			}

			bool intOverflow = (errno == ERANGE || x > INT_MAX || x < INT_MIN);
			double value = std::strtod(literal.c_str(), &end);
			if (*end != '\0')
			{
				printImpossible();
				break;
			}

			printChar(value);
			if (intOverflow)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(x) << std::endl;
			printFloat(value);
			printDouble(value);
			break;
		}

		case FLOAT:
		{
			char* end;
			float f = std::strtof(literal.c_str(), &end);
			if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
			{
				printImpossible();
				break;
			}
			double value = static_cast<double>(f);
			printChar(value);
			printInt(value);
			printFloat(value);
			printDouble(value);
			break;
		}

		case DOUBLE:
		{
			char* end;
			double d = std::strtod(literal.c_str(), &end);
			if (*end != '\0')
			{
				printImpossible();
				break;
			}
			printChar(d);
			printInt(d);
			printFloat(d);
			printDouble(d);
			break;
		}

		case INVALID:
		default:
			printImpossible();
			break;
	}
}
