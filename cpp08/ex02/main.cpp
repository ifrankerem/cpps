#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

static void title(const std::string &s)
{
	std::cout << "\n===== " << s << " =====" << std::endl;
}

template <typename It>
static void printRange(It begin, It end)
{
	std::cout << "[";
	for (It it = begin; it != end; ++it)
	{
		if (it != begin)
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << "]" << std::endl;
}

int main()
{
	title("subject main with MutantStack");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	title("same main with std::list (output must match)");
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> l(lst);
	}

	title("stack functions still work");
	{
		MutantStack<int> m;
		std::cout << "empty: " << m.empty() << " size: " << m.size()
				  << "   (expected 1 0)" << std::endl;
		for (int i = 1; i <= 5; i++)
			m.push(i * 10);
		std::cout << "top: " << m.top() << " size: " << m.size()
				  << "   (expected 50 5)" << std::endl;
		m.pop();
		m.pop();
		std::cout << "after 2 pops top: " << m.top() << "   (expected 30)" << std::endl;
		printRange(m.begin(), m.end()); // [10 20 30]
	}

	title("empty stack: begin == end");
	{
		MutantStack<int> m;
		std::cout << (m.begin() == m.end() ? "OK" : "WRONG") << std::endl;
		printRange(m.begin(), m.end()); // []
	}

	title("walk backwards from end");
	{
		MutantStack<int> m;
		m.push(1);
		m.push(2);
		m.push(3);
		MutantStack<int>::iterator it = m.end();
		while (it != m.begin())
		{
			--it;
			std::cout << *it << " ";
		}
		std::cout << "  (expected 3 2 1)" << std::endl;
	}

	title("write through iterator");
	{
		MutantStack<int> m;
		m.push(1);
		m.push(2);
		m.push(3);
		for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
			*it *= 100;
		printRange(m.begin(), m.end()); // [100 200 300]
		std::cout << "top: " << m.top() << "   (expected 300)" << std::endl;
	}

	title("STL algorithms on MutantStack");
	{
		MutantStack<int> m;
		int arr[] = {42, 7, 19, 7, 88, -3};
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
			m.push(arr[i]);
		std::cout << "find 19: "
				  << (std::find(m.begin(), m.end(), 19) != m.end() ? "found" : "not found")
				  << "   (expected found)" << std::endl;
		std::cout << "count 7: " << std::count(m.begin(), m.end(), 7)
				  << "   (expected 2)" << std::endl;
		std::cout << "max: " << *std::max_element(m.begin(), m.end())
				  << "   (expected 88)" << std::endl;
		std::cout << "sum: " << std::accumulate(m.begin(), m.end(), 0)
				  << "   (expected 160)" << std::endl;
		std::cout << "distance: " << std::distance(m.begin(), m.end())
				  << "   (expected 6)" << std::endl;
		std::vector<int> v(m.begin(), m.end());
		std::cout << "copied to vector: ";
		printRange(v.begin(), v.end()); // [42 7 19 7 88 -3]
		std::sort(m.begin(), m.end());
		std::cout << "sorted in place: ";
		printRange(m.begin(), m.end()); // [-3 7 7 19 42 88]
		std::cout << "top after sort: " << m.top() << "   (expected 88)" << std::endl;
	}

	title("copy constructor (deep copy)");
	{
		MutantStack<int> a;
		a.push(1);
		a.push(2);
		MutantStack<int> b(a);
		b.push(3);
		*b.begin() = 99;
		std::cout << "a: ";
		printRange(a.begin(), a.end()); // [1 2]
		std::cout << "b: ";
		printRange(b.begin(), b.end()); // [99 2 3]
	}

	title("assignment operator (deep copy)");
	{
		MutantStack<int> a;
		a.push(1);
		a.push(2);
		MutantStack<int> b;
		b.push(500);
		b = a;
		a.push(3);
		std::cout << "a: ";
		printRange(a.begin(), a.end()); // [1 2 3]
		std::cout << "b: ";
		printRange(b.begin(), b.end()); // [1 2]
		MutantStack<int> &self = b; // through a reference so clang does not reject b = b
		b = self;
		std::cout << "b after self-assign: ";
		printRange(b.begin(), b.end()); // [1 2]
	}

	title("convert to std::stack");
	{
		MutantStack<int> m;
		m.push(4);
		m.push(8);
		std::stack<int> s(m);
		std::cout << "std::stack top: " << s.top() << " size: " << s.size()
				  << "   (expected 8 2)" << std::endl;
	}

	title("other element type: std::string");
	{
		MutantStack<std::string> m;
		m.push("hello");
		m.push("mutant");
		m.push("stack");
		printRange(m.begin(), m.end()); // [hello mutant stack]
	}

	title("other underlying containers");
	{
		MutantStack<int, std::vector<int> > mv;
		MutantStack<int, std::list<int> > ml;
		for (int i = 1; i <= 4; i++)
		{
			mv.push(i);
			ml.push(i * i);
		}
		std::cout << "vector based: ";
		printRange(mv.begin(), mv.end()); // [1 2 3 4]
		std::cout << "list based:   ";
		printRange(ml.begin(), ml.end()); // [1 4 9 16]
	}

	title("100 000 elements");
	{
		MutantStack<int> m;
		for (int i = 0; i < 100000; i++)
			m.push(i);
		long sum = 0;
		for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
			sum += *it;
		std::cout << "size: " << m.size() << " sum: " << sum
				  << "   (expected 100000 4999950000)" << std::endl;
	}

	title("const MutantStack");
	{
		MutantStack<int> m;
		m.push(1);
		m.push(2);
		const MutantStack<int> &cm = m;
		MutantStack<int>::const_iterator it = cm.begin();
		std::cout << *it << "   (expected 1)" << std::endl;
	}

	title("reverse iterator");
	{
		MutantStack<int> m;
		m.push(1);
		m.push(2);
		m.push(3);
		printRange(m.rbegin(), m.rend()); // [3 2 1]
	}

	title("const reverse iterator");
	{
		MutantStack<int> m;
		m.push(1);
		m.push(2);
		m.push(3);
		const MutantStack<int> &cm = m;
		MutantStack<int>::const_reverse_iterator it = cm.rbegin();
		std::cout << *it << "   (expected 3)" << std::endl;
		printRange(cm.rbegin(), cm.rend()); // [3 2 1]
	}

	return 0;
}
