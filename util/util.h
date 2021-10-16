#ifndef UTIL_H
# define UTIL_H
# include <stdio.h>
# include <stdlib.h>
# define ERROR 1
# define SUCCESS 0

// typedef struct s_test
// {
//     int i;

// } t_test;

int		ft_atoi(const char *str);
int	isnum(char element);
int error(const char *msg);
void	*ft_calloc(int a, int b);

#endif