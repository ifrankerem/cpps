#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h> 
#include <iostream>
 
class Serialization
{


	
private:
	Serialization();
    Serialization(const Serialization& other);
    Serialization& operator=(const Serialization& other);
    ~Serialization();

public:

 struct Data{
		int x;
		int y;
		std::string str;
	};

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
