#include "whatever.hpp"
#include <iostream>
#include <string>

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl; // :: olarak cagirilmasinin nedeni iostrem kutuphanesindende gelmesi eger :: kullanmazsak ordan sessizce kullanir(ADL)
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
std::cout << ::min(1,2) << std::endl;
int x = 2;
int y = 2;
std::cout << &x << "  " << &y << "  " << &::min(x,y) << std::endl; //return the second
std::cout << &x << "  " << &y << "  " << &::max(x,y) << std::endl; //return the second

return 0;

}