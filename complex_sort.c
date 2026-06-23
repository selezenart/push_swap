/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:53:31 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/23 13:16:53 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(int *vals, int size, int v)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		if (vals[i] < v)
			c++;
		i++;
	}
	return (c);
}

static int	normalize(t_stack *a)
{
	int		*vals;
	t_node	*cur;
	int		i;

	vals = malloc(sizeof(int) * a->size);
	if (!vals)
		return (0);
	cur = a->head;
	i = 0;
	while (cur)
	{
		vals[i++] = cur->value;
		cur = cur->next;
	}
	cur = a->head;
	while (cur)
	{
		cur->value = count_smaller(vals, a->size, cur->value);
		cur = cur->next;
	}
	free(vals);
	return (1);
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	radix(t_run *run)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	max_bits = get_max_bits(run->stack_a->size);
	bit = 0;
	while (bit < max_bits)
	{
		size = (*run).stack_a->size;
		i = 0;
		while (i < size)
		{
			if ((run->stack_a->head->value >> bit) & 1)
				ra(run);
			else
				pb(run);
			i++;
		}
		while (run->stack_b->size > 0)
			pa(run);
		bit++;
	}
}

void	radix_sort_stacks(t_run *run)
{
	t_stack	*a;
	t_stack	*b;

	a = (*run).stack_a;
	b = (*run).stack_b;
	if (a->size < 2 || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sa(run);
		return ;
	}
	if (!normalize(a))
		free_and_exit(&a, &b);
	radix(run);
}
