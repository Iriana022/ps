/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:51:31 by irazafim          #+#    #+#             */
/*   Updated: 2024/05/11 11:54:48 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_u_int(unsigned int nb, int *count)
{
	if (nb == 4294967295)
	{
		ft_putstr_fd("4294967295", 1);
		*count += 10;
		return ;
	}
	if (nb > 9)
	{
		ft_put_u_int(nb / 10, count);
		ft_put_u_int(nb % 10, count);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		(*count)++;
	}
}

void	ft_puthexa_lower(unsigned int nb, char *hex_char, int *count)
{
	if (nb > 15)
	{
		ft_puthexa_lower(nb / 16, "0123456789abcdef", count);
		ft_puthexa_lower(nb % 16, "0123456789abcdef", count);
	}
	else
	{
		ft_putchar_fd(hex_char[nb], 1);
		(*count)++;
	}
}

void	ft_puthexa_lower_l(unsigned long nb, char *hex_char, int *count)
{
	if (nb > 15)
	{
		ft_puthexa_lower_l(nb / 16, "0123456789abcdef", count);
		ft_puthexa_lower_l(nb % 16, "0123456789abcdef", count);
	}
	else
	{
		ft_putchar_fd(hex_char[nb], 1);
		(*count)++;
	}
}

void	ft_puthexa_upper(unsigned int nb, char *hex_char, int *count)
{
	if (nb > 15)
	{
		ft_puthexa_upper(nb / 16, "0123456789ABCDEF", count);
		ft_puthexa_upper(nb % 16, "0123456789ABCDEF", count);
	}
	else
	{
		ft_putchar_fd(hex_char[nb], 1);
		(*count)++;
	}
}

void	ft_putpointer(unsigned long ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		(*count) += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthexa_lower_l(ptr, "0123456789abcdef", count);
		(*count) += 2;
	}
}
