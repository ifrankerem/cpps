#include <iostream>
#include <cmath>

class Fixed
{
  private:
	int fixed_number;
	static const int fractional_bits = 8;

  public:
  	Fixed();
	Fixed(const int x);
	Fixed(const float x);
	Fixed(const Fixed &x);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed& operator=(const Fixed& obj);
	bool operator>(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;
	Fixed operator+(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	static	Fixed& min(Fixed& obj_1, Fixed& obj_2);
	static const Fixed& min(const Fixed&  obj_1, const Fixed& obj_2);
	static	Fixed& max(Fixed& obj_1, Fixed& obj_2);
	static const Fixed& max(const Fixed&  obj_1, const Fixed& obj_2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);
