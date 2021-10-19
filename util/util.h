/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:45:11 by emallah           #+#    #+#             */
/*   Updated: 2021/10/19 14:45:15 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <stdio.h>
# include <stdlib.h>
# define ERROR 1
# define SUCCESS 0

int		ft_atoi(const char *str);
int		isnum(char element);
int		error(const char *msg);
void	*ft_calloc(int a, int b);

#endif
