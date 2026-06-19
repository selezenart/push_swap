/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:54:15 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 15:49:23 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

# define SIMPLE   "--simple"
# define MEDIUM   "--medium"
# define COMPLX   "--complex"
# define ADAPT    "--adaptive"
# define BENCH    "--bench"

// Singly-linked stack node. Mirrors t_list but stores the int inline,
// so no void * content / cast is needed.
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	t_stack;

// Op counters for --bench mode
typedef struct s_counts
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_counts;

typedef struct s_run
{
	double		disorder;
	int			bench;
	int			strategy;
	int			chosen;
	int			total_ops;
	t_counts	*counts;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_run;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

// Parsing — returns size on success, -1 on error (validates format/range/dups)
int		parse(int ac, char **av, int **values);
int		validate_input(char **tokens, int size);
int		has_duplicates(int *values, int size);

// Stack creation
t_stack	*create_stack(int *values, int size);
t_stack	*create_empty_stack(void);
void	free_stack(t_stack *stack);

// Error
void	error_exit(void);
void	free_and_exit(t_stack **a, t_stack **b);

// Low-level move primitives (silent; shared with the checker)
void	swap(t_stack **s);
void	push(t_stack **dst, t_stack **src);
void	rotate(t_stack **s);
void	reverse_rotate(t_stack **s);

// Stack operations (all accept an optional t_counts * — pass NULL to skip)
void	sa(t_run *run);
void	sb(t_run *run);
void	ss(t_run *run);
void	ra(t_run *run);
void	rb(t_run *run);
void	rr(t_run *run);
void	pa(t_run *run);
void	pb(t_run *run);
void	rra(t_run *run);
void	rrb(t_run *run);
void	rrr(t_run *run);

// Utils
int		is_sorted(t_stack *stack);
int		get_size(char **nb_array);
void	free_nb_array(char **nb_array);
int		parse_flags(int *ac, char ***av, t_run *r);
int		isqrt(int n);
void	put_op(t_run *run, char *op);
void	print_op_count(t_run *run);

//Sorting

void	selection_sort_stacks(t_run *run);
void	medium_sort_stacks(t_run *run);
void	sort_three(t_run *run);
void	sort_five(t_run *run);
void	radix_sort_stacks(t_run *run);

// Solver — disorder metric + algorithm chooser
double	compute_disorder(t_stack *a);
void	run_and_bench(t_stack **a, t_stack **b, t_run *run);

// Bench (--bench) — report to stderr
void	print_bench(t_run *run);
int		get_total_counts(t_counts *c);

#endif
