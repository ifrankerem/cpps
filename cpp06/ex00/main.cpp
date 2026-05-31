#include "ScalarConverter.hpp"

void test(const std::string &literal)
{
	std::cout << "<<<<<  " << literal << "  <<<<<" << std::endl;
	ScalarConverter::convert(literal);
	std::cout << "---------------" << std::endl;
}



int main(void)
{
    // char literal cases
    test("a");
    test("z");
    test("*");

    // single digit must be numeric, not char
    test("0");
    test("8");
    test("9");

    // int cases
    test("42");
    test("-42");
    test("+42");
    test("2147483647");
    test("-2147483648");

    // int overflow cases
    test("2147483648");
    test("-2147483649");
    test("999999999999999999999999");

    // float cases
    test("0.0f");
    test("8.0f");
    test("42.0f");
    test("-42.42f");
    test("+42.42f");

    // double cases
    test("0.0");
    test("8.0");
    test("42.0");
    test("-42.42");
    test("+42.42");

    // pseudo literals
    test("nan");
    test("nanf");
    test("+inf");
    test("+inff");
    test("-inf");
    test("-inff");

    // invalid literals
    test("");
    test("abcfo");
    test("42foo");
    test("4f2");
    test("42.0ff");
    test("++42");
    test("--42");
    test("42..0");
    test(".");
    test("f");

    return 0;
}