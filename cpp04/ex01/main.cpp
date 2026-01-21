#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(j);
	delete(i);
	//there is important show UB behavior to eval!!
	//crate data in the cat and delete in the deconstructor so it will fail in the valgrind

	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* BrokenCat = new WrongCat();
	std::cout << BrokenCat->getType() << " " << std::endl;

	BrokenCat->makeSound();
	WrongMeta->makeSound();

	delete(WrongMeta);
	delete(BrokenCat);

	return 0;
}