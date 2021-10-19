/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:21:30 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 15:21:32 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"  

int	main(int ac, char **av)
{
	t_input	*input;

	if (ac != 5 && ac != 6)
		return (error("Wrong nbr of argument"));
	input = (t_input *)ft_calloc(sizeof(t_input), 2);
	if (input == NULL)
		return (error("Something went wrong"));
	if (get_input(ac, av, input) == ERROR)
		return (error("Invalid input"));
	if (philo(input) == ERROR)
		return (error("Something went wrong"));
	return (SUCCESS);
}
