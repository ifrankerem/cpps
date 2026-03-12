#include <iostream>
#include <exception>
#include <string>

class custom_exception : public std::exception
{
  virtual const char* what() const throw()
  {
    return "Custom Exception";
  }
};

int main()
{
    std::string word = "four";

    try
    {
        throw custom_exception();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}