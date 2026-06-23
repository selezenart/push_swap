/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:37:10 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/23 13:02:22 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_once(int *seen, int *target)
{
	if (*seen)
		return (-1);
	*seen = 1;
	*target = 1;
	return (0);
}

static int	match(char *f, t_run *r, int *strat, int *seen)
{
	if (!ft_strncmp(f, FLAG_BENCH, ft_strlen(FLAG_BENCH) + 1))
		return (set_once(&seen[0], &r->bench));
	if (*strat)
		return (-1);
	if (!ft_strncmp(f, FLAG_ADAPT, ft_strlen(FLAG_ADAPT) + 1))
		r->strategy = ADAPTIVE;
	else if (!ft_strncmp(f, FLAG_SIMPLE, ft_strlen(FLAG_SIMPLE) + 1))
		r->strategy = SIMPLE;
	else if (!ft_strncmp(f, FLAG_MEDIUM, ft_strlen(FLAG_MEDIUM) + 1))
		r->strategy = MEDIUM;
	else if (!ft_strncmp(f, FLAG_COMPLEX, ft_strlen(FLAG_COMPLEX) + 1))
		r->strategy = COMPLEX;
	else
		return (-1);
	*strat = 1;
	return (0);
}

static int	shift_args(char **av, int ac, int start)
{
	int	offset;

	offset = 1;
	while (start < ac)
	{
		if (av[start][0] == '-' && av[start][1] == '-')
			return (-1);
		av[offset++] = av[start++];
	}
	av[offset] = NULL;
	return (offset);
}

int	parse_flags(int ac, char **av, t_run *r)
{
	int	i;
	int	strat;
	int	seen[2];

	r->strategy = ADAPTIVE;
	r->bench = 0;
	strat = 0;
	seen[0] = 0;
	seen[1] = 0;
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (match(av[i], r, &strat, seen) < 0)
			return (-1);
		i++;
	}
	return (shift_args(av, ac, i));
}
