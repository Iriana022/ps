/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:24:58 by irazafim          #+#    #+#             */
/*   Updated: 2024/02/24 10:16:22 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*u_str;
	size_t			i;

	i = 0;
	u_str = (unsigned char *)s;
	while (i < n)
	{
		u_str[i] = c;
		i++;
	}
	return (s);
}
