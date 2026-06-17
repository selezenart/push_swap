/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:37:10 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:58:17 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	match(char *f, t_run *r)
{
	if (!ft_strncmp(f, "--adaptive", 11))
		r->strategy = ADAPTIVE;
	else if (!ft_strncmp(f, "--simple", 9))
		r->strategy = SIMPLE;
	else if (!ft_strncmp(f, "--medium", 9))
		r->strategy = MEDIUM;
	else if (!ft_strncmp(f, "--complex", 10))
		r->strategy = COMPLEX;
	else
		return (-1);
	return (0);
}

// Reads an optional leading strategy selector and shifts it out of av/ac so the
// rest of the code sees only the numbers. Default strategy is ADAPTIVE.
// Returns 0 on success, -1 on an unknown flag.
int	parse_flags(int *ac, char ***av, t_run *r)
{
	char	*f;

	r->strategy = ADAPTIVE;
	if (*ac < 2)
		return (0);
	f = (*av)[1];
	if (f[0] != '-' || f[1] != '-')
		return (0);
	if (match(f, r) < 0)
		return (-1);
	(*av)[1] = (*av)[0];
	(*av)++;
	(*ac)--;
	return (0);
}
