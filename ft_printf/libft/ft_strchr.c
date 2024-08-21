/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:51:03 by irazafim          #+#    #+#             */
/*   Updated: 2024/03/11 08:07:06 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_ret;
	size_t	i;

	i = 0;
	s_ret = (char *)s;
	while (i <= ft_strlen(s_ret))
	{
		if (s_ret[i] == (char)c)
			return (&s_ret[i]);
		i++;
	}
	return (NULL);
}
