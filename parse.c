/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/22 12:42:42 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	*join_args(int ac, char **av)
{
	char	*res;
	char	*tmp;
	int		i;

	res = ft_strdup(av[1]);
	i = 2;
	while (res && i < ac)
	{
		tmp = ft_strjoin(res, " ");
		free(res);
		if (!tmp)
			return (NULL);
		res = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	return (res);
}

int	parse(int ac, char **av, int **values)
{
	char	**tokens;
	char	*joined;
	int		size;
	int		ret;

	joined = join_args(ac, av);
	if (!joined)
		return (-1);
	tokens = ft_split(joined, ' ');
	free(joined);
	if (!tokens)
		return (-1);
	size = get_size(tokens);
	if (size < 1 || !validate_input(tokens, size))
		ret = -1;
	else
		ret = fill_values(tokens, size, values);
	free_nb_array(tokens);
	return (check_stack(values, ret));
}
