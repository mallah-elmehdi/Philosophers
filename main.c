#include "philo.h"  

// t_test *src()
// {
//     static t_test abc;
//     return(&abc);
// }

int main(int ac, char **av)
{
    t_input *input;

    if (ac != 5 && ac != 6)
        return (error("Wrong number of argument"));
    input = (t_input *)ft_calloc(sizeof(t_input), 2);
    if (input == NULL)
        return (error("Something went wrong"));
    if (get_input(ac, av, input) == ERROR)
        return (error("Invalid input"));
    if (philo(input) == ERROR)
        return (error("Something went wrong"));
    return (SUCCESS);
}

// LEAKS
// 1 - (t_input *input)