/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/07 00:00:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

// Reads one line (without the trailing '\n') from stdin.
// Returns a malloc'd string, or NULL on EOF with no data / read error.
char	*read_line(void);

// Applies one operation by name to the stacks using the shared move
// primitives. Returns 1 on a known op, 0 if the op is unknown / malformed.
int		apply_op(char *op, t_stack **a, t_stack **b);

#endif
