#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int N = 4;
	Animal **arr = new Animal*[N];
	for(int i = 0; i < N/2 ; i++)
		arr[i] = new Dog;
	for(int i = N/2 ; i < N ; i++)
	 	arr[i] = new Cat;
	for(int i = 0 ; i < N ; i++)
 		arr[i]->makeSound();
	for(int i = 0 ; i < N ; i++)
		delete arr[i];
	delete [] arr;


	Cat *kit = new Cat;

	kit->set_ideas("moooooo");
	std::cout << kit->get_ideas() << std::endl;

	delete kit;

	Cat *mother_kit = new Cat;

	mother_kit->set_ideas("ım an orange cat");

	Cat *child_kit = new Cat(*mother_kit);

	std::cout << mother_kit->get_ideas() << std::endl;
	std::cout << child_kit->get_ideas() << std::endl;

	delete mother_kit;
	delete child_kit;


	Dog *father_dog = new Dog;
	Dog *child_dog = new Dog;

	father_dog->set_ideas("ı hate vegetables");

	*child_dog = *father_dog;

	father_dog->set_ideas("bla");

	std::cout << father_dog->get_ideas() << std::endl;
	std::cout << child_dog->get_ideas() << std::endl;

	delete father_dog;
	delete child_dog;


	return 0;
}
