/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:21:28 by irazafim          #+#    #+#             */
/*   Updated: 2024/05/11 14:13:44 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr(int nb, int *count)
{
	char	*s;
	int		i;

	s = ft_itoa(nb);
	i = ft_strlen(s);
	free(s);
	ft_putnbr_fd(nb, 1);
	*count += i;
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		(*count) += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		(*count) += ft_strlen(s);
	}
}

void	parse(va_list args, int c, int *count)
{
	if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
	}
	else if (c == 'u')
		ft_put_u_int(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthexa_lower(va_arg(args, unsigned long), H_U, count);
	else if (c == 'X')
		ft_puthexa_upper(va_arg(args, unsigned int), H_U_M, count);
	else if (c == 'p')
		ft_putpointer(va_arg(args, unsigned long), count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			parse(args, *(s + 1), &count);
			s += 2;
		}
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
			s++;
		}
	}
	va_end(args);
	return (count);
}
