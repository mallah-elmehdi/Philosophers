NAME = philo
FLAG = -Wall -Wextra -Werror
THRD = -lpthread
SEG = -fsanitize=address
UTIL= util/atoi.c util/error.c util/isnum.c util/calloc.c
PHILO = philo.c input.c
MAIN = main.c

$(NAME):
	@gcc  $(PHILO) $(UTIL) $(MAIN) $(FLAG) $(SEG) $(THRD) -o $(NAME) 

all : $(NAME)

clean:
	@rm -fr philo.dSYM

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all