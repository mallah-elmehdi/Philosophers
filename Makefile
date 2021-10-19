NAME = philo
FLAG = -Wall -Wextra -Werror
THRD = -lpthread
UTIL= util/atoi.c util/error.c util/isnum.c util/calloc.c
PHILO = philo.c input.c init.c action.c util.c
MAIN = main.c

$(NAME):
	@gcc $(FLAG) $(PHILO) $(UTIL) $(MAIN) $(THRD) -o $(NAME) 

all : $(NAME)

clean:
	@rm -fr philo.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all