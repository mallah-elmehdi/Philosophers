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

unsigned long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 * 1000) + current_time.tv_usec);
}

void	print_msg(const char *msg, unsigned long id, unsigned long current_time)
{
	printf("%lu %d %s\n", (get_time() - current_time) / 1000, id, msg);
}
