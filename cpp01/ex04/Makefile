# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 21:44:13 by iarslan           #+#    #+#              #
#    Updated: 2025/10/19 21:44:51 by iarslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INFILES = main.cpp\

OBJFILES = $(INFILES:.cpp=.o)

NAME = sed

all: $(NAME)

$(NAME):$(OBJFILES)
	$(CXX) $(CXX_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re