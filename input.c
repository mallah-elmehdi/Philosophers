/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:20:00 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 15:20:02 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"  

int	input_handler(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isnum(str[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	init_input(int ac, char **av, t_input *input)
{
	input->nbr_philos = ft_atoi(av[1]);
	input->nbr_of_forks = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]) * 1000;
	input->time_to_eat = ft_atoi(av[3]) * 1000;
	input->time_to_sleep = ft_atoi(av[4]) * 1000;
	input->start_time = time_in_us();
	input->philo_died = 0;
	input->nbr_eat = -1;
	if (ac == 6)
		input->nbr_eat = ft_atoi(av[5]);
}

int	check_input(t_input *input)
{
	if (input->nbr_philos < 0
		|| input->nbr_of_forks < 0
		|| input->time_to_die < 0
		|| input->time_to_eat < 0
		|| input->time_to_sleep < 0
		|| input->nbr_eat < -1)
		return (ERROR);
	return (SUCCESS);
}

int	get_input(int ac, char **av, t_input *input)
{
	int	i;

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
	return (check_input(input));
}
