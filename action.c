/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:50:27 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 14:50:28 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"  

void	*philo_is_eating(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->fork) != 0)
		return (NULL);
	print_msg("has taken a fork", philo->current_time, philo->id);
	if (philo->id < philo->nbr_philos)
	{
		if (pthread_mutex_lock(&(philo + 1)->fork) != 0)
			return (NULL);
	}
	else
	{
		if (pthread_mutex_lock(&(philo - philo->nbr_philos + 1)->fork) != 0)
			 return (NULL);
	}
	print_msg("has taken a fork", philo->current_time, philo->id);
	print_msg("is eating", philo->current_time, philo->id);
	return ("GOOD");
}

void	*philo_is_sleeping(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->fork) != 0)
		return (NULL);
	if (philo->id < philo->nbr_philos)
	{
		if (pthread_mutex_unlock(&(philo + 1)->fork) != 0)
			return (NULL);
	}
	else if (pthread_mutex_unlock(&(philo - philo->nbr_philos + 1)->fork) != 0)
		return (NULL);
	if (philo->nbr_eat != -1 && philo->nbr_eat != 0)
		philo->nbr_eat--;
	print_msg("is sleeping", philo->current_time, philo->id);
	return ("GOOD");
}

int	all_philo_done(t_philo *philos, t_input *input)
{
	unsigned int	i;

	i = 0;
	while (i < input->nbr_philos)
	{
		if (philos[i].nbr_eat != 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	philo_has_died(t_philo *philos, t_input *input)
{
	unsigned int	i;

	while (1)
	{
		i = 0;
		if (all_philo_done(philos, input) == SUCCESS)
		{
			free(input);
			free(philos);
			break ;
		}
		while (i < input->nbr_philos)
		{
			if (get_time() - philos[i].done_eat >= philos[i].time_to_die * 1000)
			{
				print_msg("has died", philos[i].current_time, philos[i].id);
				free(input);
				free(philos);
				return (SUCCESS);
			}
			usleep(100);
			i++;
		}
	}
	return (SUCCESS);
}
