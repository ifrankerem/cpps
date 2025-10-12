# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 03:36:25 by iarslan           #+#    #+#              #
#    Updated: 2025/10/12 00:22:55 by iarslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = phone

C++       = c++
C++_FLAGS  = -Wall -Wextra -Werror -std=c++98

SRC_DIR   = src
INC_DIR   = include
OBJ_DIR   = obj

SRC_FILES = main.cpp PhoneBook.cpp Contact.cpp
SRC       = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(C++) $(C++_FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

