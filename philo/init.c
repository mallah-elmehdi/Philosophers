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

t_philo	*philo_init(t_input *input)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)ft_calloc(sizeof(t_philo), (input->nbr_philos + 1));
	if (philos == NULL)
		return (NULL);
	while (i < input->nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].nbr_meals = 0;
		philos[i].done_eat = 1;
		philos[i].input = input;
		if (pthread_mutex_init(&philos[i].fork, NULL) != 0)
		{
			free(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
