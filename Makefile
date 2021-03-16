ONE = philo_one
TWO = philo_two
THREE = philo_three
CC = gcc
CFLAGS = -Wall -Wextra -Werror

PATH_1 = ./philo_one/
PATH_2 = ./philo_two/
PATH_3 = ./philo_three/
SRCS_1 = 
SRCS_2 = 
SRCS_3 = 

OBJS_1 = $(addprefix $(PATH_1), $(SRCS_1:.c=.o))
OBJS_2 = $(addprefix $(PATH_2), $(SRCS_2:.c=.o))
OBJS_3 = $(addprefix $(PATH_3), $(SRCS_3:.c=.o))

all: $(ONE) $(TWO) $(THREE)

.c.o: 
	$(CC) $(CFLAGS) -c $^ -o $@

$(ONE): $(OBJS_1)
		$(CC) $(CFLAGS) -o $@ $^

$(TWO): $(OBJS_2)
		$(CC) $(CFLAGS) -o $@ $^

$(THREE): $(OBJS_3)
		$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -f $(OBJS_1) $(OBJS_2) $(OBJS_3)

fclean: clean
	rm -f $(ONE) $(TWO) $(THREE)

re: fclean all

.PHONY: all clean fclean re
