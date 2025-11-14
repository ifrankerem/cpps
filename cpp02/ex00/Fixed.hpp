#include <iostream>

class Fixed
{
  private:
	int fixed_number;
	static const int fractional_bits = 8;

  public:
	Fixed();
	Fixed(Fixed &x);
	~Fixed();
	Fixed& operator=(const Fixed& obj);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};