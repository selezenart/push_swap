/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:10:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 13:10:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Disorder as a percentage with two decimals (e.g. 0.3725 -> "37.25%").
static void	print_disorder(double d, int fd)
{
	int	whole;
	int	frac;

	whole = (int)(d * 100);
	frac = (int)(d * 10000) % 100;
	ft_putstr_fd("Disorder: ", fd);
	ft_putnbr_fd(whole, fd);
	ft_putchar_fd('.', fd);
	if (frac < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(frac, fd);
	ft_putstr_fd("%\n", fd);
}

// Selected strategy name and its theoretical complexity class.
static void	print_strategy(int s, int fd)
{
	ft_putstr_fd("Strategy: ", fd);
	if (s == SIMPLE)
		ft_putstr_fd("Simple O(n^2)", fd);
	else if (s == MEDIUM)
		ft_putstr_fd("Medium O(n*sqrt(n))", fd);
	else
		ft_putstr_fd("Complex O(n log n)", fd);
	ft_putchar_fd('\n', fd);
}

// t_counts is 11 contiguous ints in subject order: sa sb ss pa pb ra rb rr
// rra rrb rrr. Walk it as an int array and return the running total.
static int	print_counts(t_counts *c, int fd)
{
	static char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
	int			*v;
	int			i;
	int			total;

	v = (int *)c;
	i = 0;
	total = 0;
	while (i < 11)
	{
		ft_putstr_fd(names[i], fd);
		ft_putstr_fd(": ", fd);
		ft_putnbr_fd(v[i], fd);
		ft_putchar_fd('\n', fd);
		total += v[i];
		i++;
	}
	return (total);
}

// Full --bench report to stderr. Order: disorder, strategy + class,
// total ops, then each operation count.
void	print_bench(t_run *run)
{
	int	total;

	print_disorder(run->disorder, 2);
	print_strategy(run->chosen, 2);
	total = print_counts(run->counts, 2);
	ft_putstr_fd("Total ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
}
