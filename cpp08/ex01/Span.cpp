#include "Span.hpp"
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

Span::Span() : _capacity(0)
{
}

Span::Span(const unsigned int &n)
{
	this->_capacity = n;
	_container.reserve(n);
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
   		this->_capacity = other._capacity;
   		this->_container = other._container;
    }

    return *this;
}

Span::~Span()
{
}

void Span::addNumber(const int &value)
{
	if(this->_container.size() >= this->_capacity)
		throw std::length_error("You reached the capacity!");
	_container.push_back(value);
}

long Span::shortestSpan() const
{
	if(this->_container.size() <= 1)
		throw std::length_error("Not enough numbers to find a span");
	std::vector<long> sorted(this->_container.begin(), this->_container.end());
	std::sort(sorted.begin(),sorted.end());
	std::adjacent_difference(sorted.begin(), sorted.end(), sorted.begin());
	std::vector<long>::iterator it_min = std::min_element(sorted.begin() + 1, sorted.end()); //first value skip + 1
	return *it_min;
}

long Span::longestSpan() const
{
	if(this->_container.size() <= 1)
		throw std::length_error("Not enough numbers to find a span");
	std::vector<int>::const_iterator it_max = std::max_element(_container.begin(), _container.end());
	std::vector<int>::const_iterator it_min = std::min_element(_container.begin(), _container.end());
	long max = *it_max;
	long min = *it_min;
	return (max - min);
}
