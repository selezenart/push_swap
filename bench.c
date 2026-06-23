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
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(percent, fd);
	ft_putchar_fd('.', fd);
	if (decimal < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(decimal, fd);
	ft_putstr_fd("%\n", fd);
}

static void	print_strategy(t_run *run)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (run->strategy == SIMPLE)
		ft_putstr_fd("Simple", 2);
	else if (run->strategy == MEDIUM)
		ft_putstr_fd("Medium", 2);
	else if (run->strategy == COMPLEX)
		ft_putstr_fd("Complex", 2);
	else
		ft_putstr_fd("Adaptive", 2);
	ft_putstr_fd(" / ", 2);
	if (run->chosen == SIMPLE)
		ft_putstr_fd("O(n^2)", 2);
	else if (run->chosen == MEDIUM)
		ft_putstr_fd("O(n√n)", 2);
	else
		ft_putstr_fd("O(n log n)", 2);
	ft_putchar_fd('\n', 2);
}

static void	print_range(char **n, int *v, int a, int b)
{
	ft_putstr_fd("[bench] ", 2);
	while (a < b)
	{
		ft_putstr_fd(n[a], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(v[a], 2);
		if (a + 1 < b)
			ft_putchar_fd(' ', 2);
		a++;
	}
	ft_putchar_fd('\n', 2);
}

static void	print_counts(t_counts *c)
{
	char	*n[11];
	int		*v;

	n[0] = "sa";
	n[1] = "sb";
	n[2] = "ss";
	n[3] = "pa";
	n[4] = "pb";
	n[5] = "ra";
	n[6] = "rb";
	n[7] = "rr";
	n[8] = "rra";
	n[9] = "rrb";
	n[10] = "rrr";
	v = (int *)c;
	print_range(n, v, 0, 5);
	print_range(n, v, 5, 11);
}

void	print_bench(t_run *run)
{
	int	total;

	print_disorder(run->disorder, 2);
	print_strategy(run);
	total = get_total_counts(run->counts);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
	print_counts(run->counts);
}
