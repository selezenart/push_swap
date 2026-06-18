/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 02:09:47 by aselezen         ###   ########.fr       */
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

static int	check_stack(int **values, int ret)
{
	if (ret > 0 && has_duplicates(*values, ret))
	{
		free(*values);
		*values = NULL;
		return (-1);
	}
	return (ret);
}

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
	if (size < 1 || !validate_input(tokens, size))
		ret = -1;
	else
		ret = fill_values(tokens, size, values);
	if (split)
		free_nb_array(tokens);
	return (check_stack(values, ret));
}
