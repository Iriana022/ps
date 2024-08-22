/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:49:02 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:47 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	i = 0;
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size <= l_dst)
	{
		return (size + l_src);
	}
	else
	{
		while (i < size - l_dst - 1 && src[i])
		{
			dst[l_dst + i] = src[i];
			i++;
		}
		dst[l_dst + i] = '\0';
	}
	return (l_dst + l_src);
}
