/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:36:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(char **nb_array)
{
	int	i;

	i = 0;
	while (nb_array[i])
		i++;
	return (i);
}

void	free_nb_array(char **nb_array)
{
	int	i;

	i = 0;
	while (nb_array[i])
		free(nb_array[i++]);
	free(nb_array);
}

static int	fill_values(char **tokens, int size, int **values)
{
	int	i;

	*values = malloc(sizeof(int) * size);
	if (!*values)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*values)[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (size);
}

// Splits args into ints. A single arg is treated as a space-separated list,
// many args are taken as-is. No validation yet — caller checks the return.
int	parse(int ac, char **av, int **values)
{
	char	**tokens;
	int		size;
	int		split;
	int		ret;

	split = (ac == 2);
	if (split)
		tokens = ft_split(av[1], ' ');
	else
		tokens = av + 1;
	if (!tokens)
		return (-1);
	size = get_size(tokens);
	ret = fill_values(tokens, size, values);
	if (split)
		free_nb_array(tokens);
	return (ret);
}
