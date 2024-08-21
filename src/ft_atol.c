/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:28 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 11:40:54 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	is_space(char c)
{ 
	return ((c >= 8 && c <= 13) || c == 32);
}

long long int	ft_atol(const char *s)
{
	long long int	number;
	long long int	sign;
	int		i;

	i = 0;
	sign = 1;
	while (s[i] && is_space(s[i]))
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		++i;
	}
	number = 0;
	while (s[i])
	{
		number *= 10;
		number += s[i] - '0';
		++i;
	}
	return (sign * number);
}
