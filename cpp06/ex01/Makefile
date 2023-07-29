# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 19:07:23 by amenesca          #+#    #+#              #
#    Updated: 2023/07/29 19:49:13 by amenesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer

SRC = main.cpp Serializer.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ -o $(NAME) $(CPPFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

phony: all clean fclean re