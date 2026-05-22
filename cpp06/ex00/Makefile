CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g
INFILES = ScalarConverter.cpp
OBJFILES = $(INFILES:.cpp=.o)

NAME = Form

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