#include "philo.h"  

void    *philo_is_eating(t_philo *philo)
{
    if (pthread_mutex_lock(&philo->fork) != 0)
        return (NULL);
    printf("%lu %d has taken a fork\n", (get_time() - philo->current_time) / 1000, philo->thread_id);
    if (philo->thread_id < philo->nbr_of_philos)
    {
        if (pthread_mutex_lock(&(philo + 1)->fork) != 0)
            return (NULL);
    }
    else
    {
        if (pthread_mutex_lock(&(philo - philo->nbr_of_philos + 1)->fork) != 0)
             return (NULL);
    }
    printf("%lu %d has taken a fork\n", (get_time() - philo->current_time) / 1000, philo->thread_id);
    printf("%lu %d is eating\n", (get_time() - philo->current_time) / 1000, philo->thread_id);
    return ("GOOD");
}

void    *philo_is_sleeping(t_philo *philo)
{
    if (pthread_mutex_unlock(&philo->fork) != 0)
		return (NULL);
    if (philo->thread_id < philo->nbr_of_philos)
    {
        if (pthread_mutex_unlock(&(philo + 1)->fork) != 0)
            return (NULL);
    }
    else
    {
        if (pthread_mutex_unlock(&(philo - philo->nbr_of_philos + 1)->fork) != 0)
            return (NULL);
    }
	if (philo->nbr_eat != -1 && philo->nbr_eat != 0)
		philo->nbr_eat--;
    printf("%lu %d is sleeping\n", (get_time() - philo->current_time) / 1000, philo->thread_id);
    return ("GOOD");
}

int    all_philo_done(t_philo *philos, t_input *input)
{
    unsigned int i;
    
	i = 0;
	while (i < input->nbr_of_philos)
	{
		if (philos[i].nbr_eat != 0)
			return (ERROR);
		i++;
	}
    return (SUCCESS);
}

int    philo_has_died(t_philo *philos, t_input *input)
{
    unsigned int i;
    
    while (1)
    {
        i = 0;
		if (all_philo_done(philos, input) == SUCCESS)
		{
			free(input);
			free(philos);
			break ;
		}
        while (i < input->nbr_of_philos)
        {
            if (get_time() - philos[i].done_eating >= philos[i].time_to_die * 1000) 
            {
                printf("%lu %d has died\n", (get_time() - philos[i].current_time) / 1000, philos[i].thread_id);
				free(input);
				free(philos);
                return (SUCCESS);
            }
            // usleep(100);
            i++;
        }
    }
    return (SUCCESS);
}