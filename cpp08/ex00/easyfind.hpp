#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, const int &i)
{
	typename T::iterator it = std::find(container.begin(),container.end(),i);
	if(it == container.end())
		throw std::invalid_argument("Value not found in container");
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, const int &i)
{
	typename T::const_iterator it = std::find(container.begin(),container.end(),i);
	if(it == container.end())
		throw std::invalid_argument("Value not found in container");
	return it;
}

#endif
