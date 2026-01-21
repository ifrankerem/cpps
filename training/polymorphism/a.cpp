#include <iostream>
#include <string>

class A
{
  private:
  public:
	virtual ~A()
	{
		std::cout << "A's dst\n";
	}
	virtual void ft_do_something() = 0;  // ben üstüne override yapabilirim demek!!
};

class B : public A
{
  private:
	int *data;

  public:
	void ft_do_something() // ben üstüne override yapabilirim demek!!
	{
		std::cout << "ım B\n";
	}
	void ft_leak()
	{
		data = new int[10];
	}
	~B()
	{
		std::cout << "B's dst\n";
		delete [] data;
	}
};

class C : public A
{
  private:
  public:
	void ft_do_something() // ben üstüne override yapabilirim demek!!
	{
		std::cout << "ım C\n";
	}
};


class D : public B
{
	private:

	public:
		void ft_do_something()
		{
			std::cout << "ım D\n";
		}
};



int	main(void)
{
	// A *ptrrrrrr = 0;
	// B b;
	// A &ref = b;
	A *ptr = new B; // BU GİBİ BİR KULLANIM VAR İSE
	((B*)ptr)->ft_leak();
	//A *ptr_2 = new C;
	//D d;
	//A *ptr_3 = new D;

	// d.ft_do_something();
	// ptr_3->ft_do_something();
	// ptr->ft_do_something();
	// ptr_2->ft_do_something();
	delete(ptr);
	// delete(ptr_2);
	// delete(ptr_3);
}
