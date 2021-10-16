#include "philo.h"  

int input_handler(const char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (isnum(str[i]) == ERROR)
            return (ERROR);
        i++;
    }
    return (SUCCESS);
}

void    init_input(int ac, char **av, t_input *input)
{
    input->number_of_philosophers = ft_atoi(av[1]);
    input->number_of_forks = ft_atoi(av[1]);
    input->time_to_die = ft_atoi(av[2]);
    input->time_to_eat = ft_atoi(av[3]);
    input->time_to_sleep = ft_atoi(av[4]);
    input->number_of_times_each_philosopher_must_eat = -1;
    if (ac == 6)
        input->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

int get_input(int ac, char **av, t_input *input)
{
    int i;

    i = 1;
    while (av[i])
    {
        if (input_handler(av[i]) == ERROR)
        {
            free(input);
            return (ERROR);
        }
        i++;
    }
    init_input(ac, av, input);
    return (SUCCESS);
}