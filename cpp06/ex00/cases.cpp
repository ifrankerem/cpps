#include <stdio.h>
int main()
{
	//! ERROR !
	const int x = 42;
	//int *p = &x;
	// *p = 10;

	//! MUST BE ERROR BUT IT SILENTS IT
	int *p = (int *)&x;
	*p = 10;
	// C style cast ovverrides this safety check
	printf("%d\n",p);
	printf("%d\n",x);
}