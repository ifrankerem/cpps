#ifndef BASE_HPP
#define BASE_HPP

#include <stdlib.h>

class Base
{
private:
    

public:
    Base();
    Base(const Base& other);
    Base& operator=(const Base& other);
    virtual ~Base();
    
    static Base* generate();
    static void identify(Base* p);
    static void identify(Base& p);
};

#endif
