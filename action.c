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
	if (philo->id < philo->input->nbr_philos)
	{
		if (pthread_mutex_lock(&(philo + 1)->fork) != 0)
			return (NULL);
	}
	else
	{
		if (pthread_mutex_lock(&(philo - philo->input->nbr_philos + 1)->fork)
			!= 0)
			 return (NULL);
	}
	if (!philo->input->philo_died)
	{
		print_msg("has taken a fork", philo->input->start_time, philo->id);
		print_msg("has taken a fork", philo->input->start_time, philo->id);
		print_msg("is eating", philo->input->start_time, philo->id);
	}
	return ("GOOD");
}

void	*philo_is_sleeping(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->fork) != 0)
		return (NULL);
	if (philo->id < philo->input->nbr_philos)
	{
		if (pthread_mutex_unlock(&(philo + 1)->fork) != 0)
			return (NULL);
	}
	else if (pthread_mutex_unlock(&(philo - philo->input->nbr_philos + 1)->fork)
		!= 0)
		return (NULL);
	if (philo->input->nbr_eat != -1 && philo->nbr_meals < philo->input->nbr_eat)
		philo->nbr_meals++;
	if (!philo->input->philo_died)
		print_msg("is sleeping", philo->input->start_time, philo->id);
	return ("GOOD");
}

int	all_philo_done(t_philo *philos, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->nbr_philos)
	{
		if (input->nbr_eat == -1 || philos[i].nbr_meals != input->nbr_eat)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	philo_has_died(t_philo *philo)
{
	if (time_in_us() - philo->done_eat >= philo->input->time_to_die
		|| philo->input->nbr_philos <= 1)
	{
		pthread_mutex_lock(&philo->died);
		print_msg("has died", philo->input->start_time, philo->id);
		philo->input->philo_died = 1;
		return (SUCCESS);
	}
	return (ERROR);
}
