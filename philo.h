#ifndef PHILO_H
# define PHILO_H
# include "util/util.h"
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
    unsigned int thread_id;
    pthread_t thread;
    pthread_mutex_t fork;
    unsigned int nbr_of_philos;
    unsigned int nbr_of_forks;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int nbr_eat;
    unsigned long current_time;
    unsigned long done_eating;
} t_philo;

typedef struct s_input
{
    unsigned int nbr_of_philos;
    unsigned int nbr_of_forks;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int nbr_eat;
    unsigned long current_time;
} t_input;

// input.c
int     input_handler(const char *str);
int     get_input(int ac, char **av, t_input *input);
void    init_input(int ac, char **av, t_input *input);
// philo.c
void    *philo_routine(t_philo *philo);
int     philo(t_input *input);
// init.c
void    philo_fill(t_input *input, t_philo *philo, unsigned int i);
t_philo *philo_init(t_input *input);
// action
void    *philo_is_eating(t_philo *philo);
void    *philo_is_sleeping(t_philo *philo);
int    philo_has_died(t_philo *philos, t_input *input);
// util
unsigned long   get_time(void);

#endif