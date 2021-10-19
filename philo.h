/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:52 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 15:24:53 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "util/util.h"
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	unsigned long	nbr_philos;
	unsigned long	nbr_of_forks;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	long			nbr_eat;
	unsigned long	current_time;
	unsigned long	done_eat;
}	t_philo;

typedef struct s_input
{
	unsigned long	nbr_philos;
	unsigned long	nbr_of_forks;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	long			nbr_eat;
	unsigned long	current_time;
}	t_input;

// input.c
int				input_handler(const char *str);
int				get_input(int ac, char **av, t_input *input);
void			init_input(int ac, char **av, t_input *input);
// philo.c
void			*philo_routine(t_philo *philo);
int				philo(t_input *input);
// init.c
void			philo_fill(t_input *input, t_philo *philo, unsigned int i);
t_philo			*philo_init(t_input *input);
// action
void			*philo_is_eating(t_philo *philo);
void			*philo_is_sleeping(t_philo *philo);
int				philo_has_died(t_philo *philos, t_input *input);
int				all_philo_done(t_philo *philos, t_input *input);
// util
unsigned long	get_time(void);
void			print_msg(const char *msg, unsigned long id,
					unsigned long current_time);

#endif
