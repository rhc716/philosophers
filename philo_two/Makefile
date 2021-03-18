NAME = philo_three
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBS = #-lpthread

all: $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^ ${LIBS}

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re