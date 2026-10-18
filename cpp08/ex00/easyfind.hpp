#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, const int &i)
{
	typename T::iterator it = std::find(container.begin(),container.end(),i);
	if(it == container.end())
		throw std::invalid_argument("There is no value that u trying to find!");
	return it;
}


#endif
