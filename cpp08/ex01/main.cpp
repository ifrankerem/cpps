#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <climits>
#include <cstdlib>
#include <ctime>

static void title(const std::string &s)
{
	std::cout << "\n===== " << s << " =====" << std::endl;
}

static void printSpans(Span &sp, const std::string &expected)
{
	try
	{
		std::cout << "shortest: " << sp.shortestSpan();
		std::cout << " | longest: " << sp.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what();
	}
	std::cout << "   (expected " << expected << ")" << std::endl;
}

int main()
{
	title("subject example");
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; // 2
		std::cout << sp.longestSpan() << std::endl;  // 14
	}

	title("too few numbers");
	{
		Span empty(5);
		printSpans(empty, "exception");
		Span one(5);
		one.addNumber(42);
		printSpans(one, "exception");
	}

	title("capacity full");
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try
		{
			sp.addNumber(3);
			std::cout << "no exception: WRONG" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "exception: " << e.what() << "   (expected)" << std::endl;
		}
		printSpans(sp, "1 | 1"); // failed add must not change anything
	}

	title("capacity 0");
	{
		Span sp(0);
		try
		{
			sp.addNumber(1);
			std::cout << "no exception: WRONG" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "exception: " << e.what() << "   (expected)" << std::endl;
		}
	}

	title("duplicates and negatives");
	{
		Span dup(3);
		dup.addNumber(7);
		dup.addNumber(7);
		dup.addNumber(20);
		printSpans(dup, "0 | 13");

		Span neg(4);
		neg.addNumber(-10);
		neg.addNumber(-3);
		neg.addNumber(5);
		neg.addNumber(-20);
		printSpans(neg, "7 | 25");
	}

	title("two Spans are independent");
	{
		Span a(2);
		Span b(2);
		a.addNumber(1);
		a.addNumber(2);
		b.addNumber(10); // must work: b is empty
		b.addNumber(30);
		printSpans(a, "1 | 1");
		printSpans(b, "20 | 20");
	}

	title("int limits");
	{
		Span sp(2);
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		printSpans(sp, "4294967295 | 4294967295, needs a wider return type than int");
	}

	title("addRange from vector, list, deque, array");
	{
		int arr[] = {100, 1, 50};
		std::vector<int> v(arr, arr + 3);
		std::list<int> l;
		l.push_back(-5);
		l.push_back(30);
		std::deque<int> d;
		d.push_back(33);

		Span sp(10);
		sp.addRange(v.begin(), v.end());
		sp.addRange(l.begin(), l.end());
		sp.addRange(d.begin(), d.end());
		sp.addRange(arr, arr + 1); // raw pointers are iterators too
		printSpans(sp, "0 | 105");
	}

	title("addRange over capacity");
	{
		std::vector<int> v(10, 5);
		Span sp(5);
		sp.addNumber(1);
		try
		{
			sp.addRange(v.begin(), v.end());
			std::cout << "no exception: WRONG" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "exception: " << e.what() << "   (expected)" << std::endl;
		}
		printSpans(sp, "exception, only 1 number if nothing was added");
	}

	title("copy constructor and assignment (deep copy)");
	{
		Span a(3);
		a.addNumber(1);
		a.addNumber(10);

		Span b(a);
		b.addNumber(4);
		printSpans(a, "9 | 9");
		printSpans(b, "3 | 9");

		Span c(1);
		c = b;
		try
		{
			c.addNumber(99); // c now has capacity 3 and is full
			std::cout << "no exception: WRONG" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "exception: " << e.what() << "   (expected)" << std::endl;
		}
		printSpans(c, "3 | 9");
	}

	title("10 000 numbers, known answer");
	{
		std::vector<int> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(i * 3);
		Span sp(10000);
		sp.addRange(v.begin(), v.end());
		printSpans(sp, "3 | 29997");
	}

	title("100 000 random numbers");
	{
		std::srand(std::time(NULL));
		std::vector<int> v;
		for (int i = 0; i < 100000; i++)
			v.push_back(std::rand());
		Span sp(100000);
		sp.addRange(v.begin(), v.end());
		printSpans(sp, "small | close to RAND_MAX");
	}

	title("const Span");
	{
		Span sp(3);
		sp.addNumber(5);
		sp.addNumber(1);
		sp.addNumber(12);
		const Span &ref = sp;
		std::cout << ref.shortestSpan() << " | " << ref.longestSpan()
				  << "   (expected 4 | 11)" << std::endl;
	}

	return 0;
}
