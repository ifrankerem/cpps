CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98 -pedantic
INFILES = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJFILES = $(INFILES:.cpp=.o)

NAME = Abstract

all: $(NAME)

$(NAME):$(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re