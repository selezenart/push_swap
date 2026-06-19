/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:37:10 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/19 14:59:49 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	match(char *f, t_run *r)
{
	if (!ft_strncmp(f, FLAG_ADAPT, ft_strlen(FLAG_ADAPT) + 1))
		r->strategy = ADAPTIVE;
	else if (!ft_strncmp(f, FLAG_SIMPLE, ft_strlen(FLAG_SIMPLE) + 1))
		r->strategy = SIMPLE;
	else if (!ft_strncmp(f, FLAG_MEDIUM, ft_strlen(FLAG_MEDIUM) + 1))
		r->strategy = MEDIUM;
	else if (!ft_strncmp(f, FLAG_COMPLEX, ft_strlen(FLAG_COMPLEX) + 1))
		r->strategy = COMPLEX;
	else if (!ft_strncmp(f, FLAG_BENCH, ft_strlen(FLAG_BENCH) + 1))
		r->bench = 1;
	else
		return (-1);
	return (0);
}

int	parse_flags(int *ac, char ***av, t_run *r)
{
	char	*f;

	r->strategy = ADAPTIVE;
	r->bench = 0;
	while (*ac >= 2)
	{
		f = (*av)[1];
		if (f[0] != '-' || f[1] != '-')
			return (0);
		if (match(f, r) < 0)
			return (-1);
		(*av)[1] = (*av)[0];
		(*av)++;
		(*ac)--;
	}
	return (0);
}
