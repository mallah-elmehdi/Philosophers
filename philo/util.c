/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:27:57 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 15:27:59 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_in_us(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 * 1000) + current_time.tv_usec);
}

void	print_msg(const char *msg, t_input *input, int id)
{
	pthread_mutex_lock(&input->print);
	printf("%lld %u %s\n", (time_in_us() - input->start_time) / 1000, id, msg);
	pthread_mutex_unlock(&input->print);
}

void	ft_usleep(long long time)
{
	long long	sleep_time;
	long long	current_time;

	current_time = time_in_us();
	if (time < 50000)
		sleep_time = time;
	else
		sleep_time = time - 50000;
	usleep(sleep_time);
	while ((time_in_us() - current_time) < time)
		;
}
