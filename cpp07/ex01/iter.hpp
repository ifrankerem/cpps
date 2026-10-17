#ifndef ITER_HPP
#define ITER_HPP


#include <cstddef>

template<typename T,typename F>
void iter(T arr[],const size_t size, F func)
{
	for(size_t i = 0 ; i < size ; i++)
		func(arr[i]);
}

//there is second path of doing this u can overlaod 2 functions for const and non-const with same template typename T


#endif 
