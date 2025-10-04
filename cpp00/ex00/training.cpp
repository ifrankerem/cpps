#include <cstring>
#include <iostream>

class Names
{
  public:
	char name[100];

	void set_name(const char *input)
	{
		strcpy(name, input);
	}
	void ft_writer()
	{
		std::cout << "Merhaba senin ismin " << name << std::endl;
	}
};

int	main(void)
{
	Names name_1;
	name_1.set_name("kerem");
	name_1.ft_writer();
}