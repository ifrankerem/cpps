#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>


template<typename T, typename container_type = std::deque<T> >


class MutantStack : public std::stack<T,container_type>
{
private:
	
public:
	
 	typedef typename container_type::iterator iterator;
 	typedef typename container_type::const_iterator const_iterator;
 	typedef typename container_type::reverse_iterator reverse_iterator;
 	typedef typename container_type::const_reverse_iterator const_reverse_iterator;
  

    MutantStack()
    {}
    MutantStack(const MutantStack& other) : std::stack<T,container_type>(other)
    {}
    MutantStack& operator=(const MutantStack& other)
    {
  		if(this != &other)
    		std::stack<T,container_type>::operator=(other);
    	return(*this);
    }
    ~MutantStack()    //there is no value for MutantStack so base class destructor can called no problem
    {}

    iterator begin()
    {
    	return this->c.begin();
	}
    iterator end()
    {
    	return this->c.end();
    }
    const_iterator begin() const
    {
    	return this->c.begin();
	}
    const_iterator end() const
    {
    	return this->c.end();
    }
    reverse_iterator rbegin()
    {
    	return this->c.rbegin();
	}
    reverse_iterator rend()
    {
    	return this->c.rend();
    }
    const_reverse_iterator rbegin() const
    {
    	return this->c.rbegin();
	}
    const_reverse_iterator rend() const
    {
    	return this->c.rend();
    }

};

#endif
