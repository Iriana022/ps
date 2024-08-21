/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:45:54 by irazafim          #+#    #+#             */
/*   Updated: 2024/03/11 08:48:25 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_tab(char *ret, size_t len, unsigned int start, char const *s)
{
	unsigned int	i;

	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		ret = (char *)malloc(1);
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (len < ft_strlen(s))
		ret = (char *)malloc(len + 1);
	else
		ret = (char *)malloc(ft_strlen(s) - start + 1);
	if (ret != NULL)
	{
		ret = fill_tab(ret, len, start, s);
		return (ret);
	}
	return (NULL);
}
