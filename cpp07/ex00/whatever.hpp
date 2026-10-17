#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &a , T &b)
{
	T trash(a);
	a = b;
	b = trash;
}

template<typename T>
const T& min(const T &a,const T &b)
{
	if(b > a)
		return a;
	else
		return b;
}


template<typename T>
const T& max(const T &a,const T &b)
{
	if(a > b)
		return a;
	else
		return b;
}

#endif
