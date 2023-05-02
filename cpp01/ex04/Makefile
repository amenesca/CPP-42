NAME = sedisforloser

SRC = main.cpp init_var.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ -o $(NAME) $(CPPFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f LoremIpsum.replace

re: fclean all

phony: all clean fclean re
