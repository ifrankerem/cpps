#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

template <typename T>
void test(T &container, int value, const std::string &name)
{
	std::cout << "[" << name << "] search " << value << ": ";
	try
	{
		typename T::iterator it = easyfind(container, value);
		std::cout << "found " << *it << " at index "
				  << std::distance(container.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
}

int main()
{
	int arr[] = {4, 8, 15, 16, 23, 42, 8, -7};
	size_t n = sizeof(arr) / sizeof(arr[0]);

	std::cout << "===== vector =====" << std::endl;
	std::vector<int> v(arr, arr + n);
	test(v, 4, "vector");   // first element
	test(v, 23, "vector");  // middle
	test(v, -7, "vector");  // last element, negative
	test(v, 8, "vector");   // duplicate: must return index 1, not 6
	test(v, 99, "vector");  // not found

	std::cout << "\n===== list =====" << std::endl;
	std::list<int> l(arr, arr + n);
	test(l, 42, "list");
	test(l, 0, "list");

	std::cout << "\n===== deque =====" << std::endl;
	std::deque<int> d(arr, arr + n);
	test(d, 16, "deque");
	test(d, 1000, "deque");

	std::cout << "\n===== empty =====" << std::endl;
	std::vector<int> empty;
	test(empty, 0, "empty vector");

	std::cout << "\n===== modify through iterator =====" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(v, 15);
		*it = 1500;
		std::cout << "v[2] is now " << v[2] << std::endl;
		test(v, 15, "vector");
		test(v, 1500, "vector");
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== big vector =====" << std::endl;
	std::vector<int> big;
	for (int i = 0; i < 100000; i++)
		big.push_back(i * 2);
	test(big, 199998, "big vector"); // last
	test(big, 777, "big vector");    // odd, never there

	// Uncomment after adding a const overload (returns const_iterator)
	// std::cout << "\n===== const =====" << std::endl;
	// const std::vector<int> cv(arr, arr + n);
	// std::vector<int>::const_iterator cit = easyfind(cv, 42);
	// std::cout << "const found " << *cit << std::endl;

	return 0;
}
