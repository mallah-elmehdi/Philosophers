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

typedef struct s_input
{
	long long	nbr_philos;
	long long	nbr_of_forks;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long		nbr_eat;
	long long	start_time;
	int			philo_died;
}	t_input;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	died;
	long long		done_eat;
	long			nbr_meals;
	t_input			*input;
}	t_philo;

// input.c
int				input_handler(const char *str);
int				get_input(int ac, char **av, t_input *input);
void			init_input(int ac, char **av, t_input *input);
// philo.c
void			*philo_routine(t_philo *philo);
int				philo(t_input *input);
int				hang(t_philo *philos, t_input *input);
// init.c
t_philo			*philo_init(t_input *input);
// action
void			*philo_is_eating(t_philo *philo);
void			*philo_is_sleeping(t_philo *philo);
int				philo_has_died(t_philo *philo, t_input *input);
int				all_philo_done(t_philo *philos, t_input *input);
// util
long long		time_in_us(void);
void			print_msg(const char *msg, long long current_time,
					int id);
void			ft_usleep(long long time);

#endif
