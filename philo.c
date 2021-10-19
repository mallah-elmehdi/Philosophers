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
		if (philo->nbr_eat != -1 && philo->nbr_eat == 0)
			break ;
		if (philo_is_eating(philo) == NULL)
			return (NULL);
		philo->done_eat = get_time();
		usleep(philo->time_to_eat * 1000);
		if (philo_is_sleeping(philo) == NULL)
			return (NULL);
		usleep(philo->time_to_sleep * 1000);
		print_msg("is thinking", philo->current_time, philo->id);
	}
	return ("DONE");
}

int	philo(t_input *input)
{
	unsigned int	i;
	t_philo			*philos;

	i = 0;
	philos = philo_init(input);
	if (philos == NULL)
		return (ERROR);
	while (i < input->nbr_philos)
	{
		philos[i].done_eat = get_time();
		if (pthread_create(&philos[i].thread, NULL,
				(void *)philo_routine, &philos[i]) != 0)
		{
			free(input);
			free(philos);
			return (ERROR);
		}
		usleep(100);
		i++;
	}
	return (philo_has_died(philos, input));
}
