/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:22:15 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 15:22:16 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"  

void	*philo_routine(t_philo *philo)
{
	while (1)
	{
		if (philo->input->philo_died
			|| (philo->input->nbr_eat != -1 && philo->nbr_meals
				== philo->input->nbr_eat))
			break ;
		if (philo_is_eating(philo) == NULL)
			return (NULL);
		philo->done_eat = 0;
		philo->eats = time_in_us();
		ft_usleep(philo->input->time_to_eat);
		philo->done_eat = 1;
		if (philo_is_sleeping(philo) == NULL)
			return (NULL);
		ft_usleep(philo->input->time_to_sleep);
		if (!philo->input->philo_died)
			print_msg("is thinking", philo->input, philo->id);
	}
	return ("DONE");
}

int	hang(t_philo *philos, t_input *input)
{
	while (1)
	{
		if (philo_has_died(philos, input) == SUCCESS
			|| all_philo_done(philos, input) == SUCCESS)
			break ;
	}
	free (philos);
	return (SUCCESS);
}

int	philo(t_input *input)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = philo_init(input);
	if (philos == NULL)
		return (ERROR);
	while (i < input->nbr_philos)
	{
		philos[i].eats = time_in_us();
		if (pthread_create(&philos[i].thread, NULL,
				(void *)philo_routine, &philos[i]) != 0)
		{
			free(philos);
			return (ERROR);
		}
		ft_usleep(500);
		i++;
	}
	return (hang(philos, input));
}
