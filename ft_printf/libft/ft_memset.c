/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:24:58 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:30 by irazafim         ###   ########.fr       */
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
