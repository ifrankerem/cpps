# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 03:36:25 by iarslan           #+#    #+#              #
#    Updated: 2025/10/05 22:17:35 by iarslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = phone

CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC_DIR   = src
INC_DIR   = include
OBJ_DIR   = obj

SRC_FILES = main.cpp phonebook.cpp contact.cpp
SRC       = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

