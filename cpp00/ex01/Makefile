# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 03:36:25 by iarslan           #+#    #+#              #
#    Updated: 2025/10/05 03:37:39 by iarslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
INFILES = 	phonebook.cpp\

OBJFILES = $(INFILES:.cpp=.o)

NAME = phone

all: $(NAME)

$(NAME):$(OBJFILES)
	$(C++) $(C++FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

