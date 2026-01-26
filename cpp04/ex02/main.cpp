#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int N = 2;
	Animal **arr = new Animal*[N];
	for(int i = 0; i < N/2 ; i++)
		arr[i] = new Dog;
	// for(int i = N/2 ; i < N ; i++)
	// 	arr[i] = new Cat;
	for(int i = 0 ; i < N ; i++)
 		arr[i]->makeSound();
	for(int i = 0 ; i < N ; i++)
		delete arr[i];
	delete [] arr;
	return 0;
}