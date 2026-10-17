#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template<typename T>
class Array
{
private:
    size_t _size;
    T *_arr;

public:
    Array();
    explicit Array(const unsigned int &n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[](unsigned int i);
    const T& operator[](unsigned int i) const;
    size_t size() const;
    ~Array();
};

#include "Array.tpp"

#endif
