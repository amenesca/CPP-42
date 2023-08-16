# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 14:16:59 by amenesca          #+#    #+#              #
#    Updated: 2023/08/16 15:08:15 by amenesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRC = main.cpp BitcoinExchange.cpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
		c++ -c $< $(CPPFLAGS) -o $@

all: $(NAME)

$(NAME): $(OBJ)
	c++ -o $(NAME) $(CPPFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

phony: all clean fclean re