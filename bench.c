/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:10:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 02:10:18 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double d, int fd)
{
	int	percent;
	int	decimal;

	percent = (int)(d * 100);
	decimal = (int)(d * 10000) % 100;
	ft_putstr_fd("Disorder: ", fd);
	ft_putnbr_fd(percent, fd);
	ft_putchar_fd('.', fd);
	if (decimal < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(decimal, fd);
	ft_putstr_fd("%\n", fd);
}

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

static void	print_counts(t_counts *c, int fd)
{
	char	*ops;
	int		*v;
	int		i;

	ops = "sa sb ss pa pb ra rb rr rra rrb rrr";
	v = (int *)c;
	i = 0;
	while (i < 11)
	{
		while (*ops && *ops != ' ')
			ft_putchar_fd(*ops++, fd);
		if (*ops == ' ')
			ops++;
		ft_putstr_fd(": ", fd);
		ft_putnbr_fd(v[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	print_bench(t_run *run)
{
	int	total;

	print_disorder(run->disorder, 2);
	print_strategy(run->chosen, 2);
	print_counts(run->counts, 2);
	total = get_total_counts(run->counts);
	ft_putstr_fd("Total ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
}
