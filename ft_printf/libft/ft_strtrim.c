/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:24:15 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:56 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;
	int		len;

	start = 0;
	while (s1[start] && char_in_set(s1[start], (char *)set))
		start++;
	len = ft_strlen(s1 + start);
	end = len + start - 1;
	while (len && char_in_set(s1[end], (char *)set))
	{
		end--;
		len--;
	}
	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1 + start, len + 1);
	return (ret);
}
