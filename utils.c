/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:49:59 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/22 13:35:27 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (!stack || stack->size < 2)
		return (1);
	cur = stack->head;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	isqrt(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

void	put_op(t_run *run, char *op)
{
	(void)run;
	write(1, op, ft_strlen(op));
}

int	get_total_counts(t_counts *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb
		+ c->ra + c->rb + c->rr + c->rra + c->rrb + c->rrr);
}

void	print_op_count(t_run *run)
{
	ft_putnbr_fd(get_total_counts(run->counts), 1);
	ft_putchar_fd('\n', 1);
}
