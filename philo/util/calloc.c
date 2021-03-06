/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:45:27 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 14:45:29 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	*ft_calloc(int a, int b)
{
	int		i;
	void	*p;

	i = 0;
	p = malloc(a * b);
	if (!p)
		return (NULL);
	while (i < (a * b))
	{
		((unsigned char *)p)[i] = '\0';
		i++;
	}
	return (p);
}
