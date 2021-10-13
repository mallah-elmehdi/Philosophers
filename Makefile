NAME = philo
FLAG = -Wall -Wextra -Werror
THRD = -lpthread
PHILO = philo.c

$(NAME):
	@gcc -g  $(PHILO) $(THRD) -o $(NAME) 

all : $(NAME)

clean:
	@rm -fr philo.dSYM

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all