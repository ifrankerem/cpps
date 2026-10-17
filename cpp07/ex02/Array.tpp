#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <cstddef>
#include <stdexcept>

template <typename T>
Array<T>::Array() : _size(0), _arr(new T[0]()) {}



template <typename T>
Array<T>::Array(const unsigned int &n): _size(n), _arr(new T[n]()) {}


template <typename T>
Array<T>::Array(const Array& other) : _size(0) , _arr(new T[0]()) //safety first
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T *arr2 = new T[other._size];
		//deep copy
		for(size_t i = 0; i < other._size; i++)
			arr2[i] = other._arr[i];
		delete [] (_arr);
		this->_size = other._size;
		this->_arr = arr2;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if(i >= this->_size)
		throw std::out_of_range("Out of bounds!");
	return _arr[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const //const version read-only
{
	if(i >= this->_size)
		throw std::out_of_range("Out of bounds!");
	return _arr[i];
}

template <typename T>
size_t Array<T>::size() const
{
	return(this->_size);
}

template <typename T>
Array<T>::~Array()
{
	delete[](this->_arr);
}


#endif

