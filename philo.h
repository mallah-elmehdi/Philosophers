#ifndef PHILO_H
# define PHILO_H
# include "util/util.h"
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
    unsigned int thread_id;
    pthread_t thread;
    pthread_mutex_t mutex;
    unsigned int number_of_philosophers;
    unsigned int number_of_forks;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int number_of_times_each_philosopher_must_eat;


} t_philo;

typedef struct s_input
{
    unsigned int number_of_philosophers;
    unsigned int number_of_forks;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int number_of_times_each_philosopher_must_eat;

} t_input;

void    *thread(void *thread_id);
int     philo(t_input *input);
int     input_handler(const char *str);
void    init_input(int ac, char **av, t_input *input);
int     get_input(int ac, char **av, t_input *input);
t_philo *philo_init(t_input *input);

#endif