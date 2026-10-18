CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g
INFILES = main.cpp
HEADERS = easyfind.hpp
OBJFILES = $(INFILES:.cpp=.o)

NAME = easyfind

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
