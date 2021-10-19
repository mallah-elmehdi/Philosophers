/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:19:26 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 15:19:27 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fill(t_input *input, t_philo *philo, unsigned int i)
{
	philo->id = i + 1;
	philo->nbr_philos = input->nbr_philos;
	philo->nbr_of_forks = input->nbr_of_forks;
	philo->time_to_eat = input->time_to_eat;
	philo->time_to_sleep = input->time_to_sleep;
	philo->time_to_die = input->time_to_die;
	philo->nbr_eat = input->nbr_eat;
	philo->current_time = input->current_time;
}

t_philo	*philo_init(t_input *input)
{
	unsigned int	i;
	t_philo			*philos;

	i = 0;
	philos = (t_philo *)ft_calloc(sizeof(t_philo), (input->nbr_philos + 1));
	if (philos == NULL)
	{
		free(input);
		return (NULL);
	}
	while (i < input->nbr_philos)
	{
		philo_fill(input, &philos[i], i);
		if (pthread_mutex_init(&philos[i].fork, NULL) != 0)
		{
			free(philos);
			free(input);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
