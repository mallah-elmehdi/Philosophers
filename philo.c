#include "philo.h"  

void    *philo_routine(t_philo *philo)
{
	while (1)
	{
		if (philo_is_eating(philo) == NULL)
			return (NULL);
		philo->done_eating = get_time();
		usleep(philo->time_to_eat * 1000);
		if (philo_is_sleeping(philo) == NULL)
			return (NULL);
		usleep(philo->time_to_sleep * 1000);
		printf("%lu %d is thinking\n", (get_time() - philo->current_time) / 1000, philo->thread_id);
	}
	return (NULL);
}

int philo(t_input *input)
{
	unsigned int    i;
	t_philo         *philos;

	i = 0;
	philos = philo_init(input);
	if (philos == NULL)
		return (ERROR);
	while (i < input->nbr_of_philos)
	{
		philos[i].done_eating = get_time();
		if (pthread_create(&philos[i].thread, NULL, (void *)philo_routine, &philos[i]) != SUCCESS)
		{
			free(input);
			free(philos);
			return (ERROR);
		}
		usleep(100);
		i++;
	}
	if (philo_has_died(philos, input) == SUCCESS)
	{			
		free(input);
		free(philos);
		return (SUCCESS);
	}
return (SUCCESS);
}