#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <vector>
#include <stdexcept>

class Span
{
private:
	unsigned int _capacity;
	std::vector<int> _container;

public:
	Span();
	Span(const unsigned int &n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	void addNumber(const int &value);
	long shortestSpan() const;
	long longestSpan() const;

	template<typename T>
	void addRange(T begin, T end)
	{
		unsigned int x = std::distance(begin, end);
		if (this->_capacity < x + this->_container.size())
			throw std::length_error("You reached the capacity!");
		this->_container.insert(this->_container.end(), begin, end);
	}
};

#endif
