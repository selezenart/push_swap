/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:55:34 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/12 17:53:58 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *conv, ...);
int		ft_putstr(const char *str);
int		ft_putchar(const char c);
int		ft_putnbr_base(long nbr, char *base);
int		ft_putnbr_base_unsigned(unsigned long nbr, char *base);
int		ft_print_ptr(void *ptr);
int		ft_handle_format(const char c, va_list args);

#endif