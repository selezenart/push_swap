/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:37:10 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 15:54:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	match(char *f, t_run *r)
{
	if (!ft_strncmp(f, ADAPTIVE, ft_strlen(ADAPTIVE) + 1))
		r->strategy = ADAPTIVE;
	else if (!ft_strncmp(f, SIMPLE, ft_strlen(SIMPLE)+1))
		r->strategy = SIMPLE;
	else if (!ft_strncmp(f, MEDIUM, ft_strlen(MEDIUM) + 1))
		r->strategy = MEDIUM;
	else if (!ft_strncmp(f, COMPLEX, ft_strlen(COMPLEX) + 1))
		r->strategy = COMPLEX;
	else if (!ft_strncmp(f, BENCH, ft_strlen(BENCH) + 1))
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
