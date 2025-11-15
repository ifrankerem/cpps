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
	Fixed& operator=(const Fixed& obj);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);