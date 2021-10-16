#include "philo.h"  

void    *thread_routine(t_philo *philosopher)
{   
    if (philosopher->thread_id < philosopher->number_of_philosophers)
        printf("Thread ID %u next %u\n", philosopher->thread_id, (philosopher + 1)->thread_id);
    else
        printf("Thread ID %u next %u\n", philosopher->thread_id, (philosopher - philosopher->number_of_philosophers + 1)->thread_id);
    return (NULL);
}

t_philo *philo_init(t_input *input)
{
    unsigned int    i;
    t_philo         *philosophers;

    i = 0;
    philosophers = (t_philo *)ft_calloc(sizeof(t_philo), (input->number_of_philosophers + 1));
    if (philosophers == NULL)
    {
        free(input);
        return (NULL);
    }
    while (i < input->number_of_philosophers)
    {
        philosophers[i].thread_id = i + 1;
        philosophers[i].number_of_philosophers = input->number_of_philosophers;
        philosophers[i].number_of_forks = input->number_of_forks;
        philosophers[i].time_to_eat = input->time_to_eat;
        philosophers[i].time_to_sleep = input->time_to_sleep;
        philosophers[i].time_to_die = input->time_to_die;
        philosophers[i].number_of_times_each_philosopher_must_eat = input->number_of_times_each_philosopher_must_eat;
        i++;
    }
    return (philosophers);
}

int philo(t_input *input)
{
    unsigned int    i;
    t_philo         *philosophers;

    i = 0;
    philosophers = philo_init(input);
    if (philosophers == NULL)
        return (ERROR);
    while (i < input->number_of_philosophers)
    {
        if (pthread_create(&philosophers[i].thread, NULL, (void *)thread_routine, &philosophers[i]) != SUCCESS)
        {
            free(input);
            free(philosophers);
            return (ERROR);
        }
        usleep(100);
        i++;
    }
    return (SUCCESS);
}