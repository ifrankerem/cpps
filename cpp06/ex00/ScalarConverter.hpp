#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_NAN,
	PSEUDO_INF,
	INVALID
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static e_type detectType(const std::string& literal);

	static bool isIntLiteral(const std::string& literal);
	static bool isFloatLiteral(const std::string& literal);
	static bool isDoubleLiteral(const std::string& literal);
	static bool hasOneDot(const std::string& literal, bool endsWithF);

	static void printChar(double value);
	static void printInt(double value);
	static void printFloat(double value);
	static void printDouble(double value);
	static void printImpossible();

public:
	static void convert(const std::string& literal);
};

#endif
