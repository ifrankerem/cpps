#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <ostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound() const; // virtual override

		void set_ideas(std::string idea);
		std::string get_ideas() const;
};

#endif
