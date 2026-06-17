/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:10 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:36:10 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	return (stack);
}

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

// Builds a stack from values, keeping input order (values[0] on top).
t_stack	*create_stack(int *values, int size)
{
	t_stack	*stack;
	t_node	*node;
	t_node	*last;
	int		i;

	stack = create_empty_stack();
	if (!stack)
		return (NULL);
	last = NULL;
	i = 0;
	while (i < size)
	{
		node = new_node(values[i]);
		if (!node)
			return (free_stack(stack), NULL);
		if (!stack->head)
			stack->head = node;
		else
			last->next = node;
		last = node;
		stack->size++;
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return ;
	cur = stack->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(stack);
}
