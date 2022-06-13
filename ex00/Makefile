CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME	= megaphone
SRCS	= megaphone.cpp
OBJS	= megaphone.o

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re