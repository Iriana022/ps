/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:56:01 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:45 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initialize(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strjoin(char const *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	initialize(&i, &j);
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret == NULL)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	if (s2[j] == '\0')
	{
		ret[i] = '\0';
		return (ret);
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[j + i] = '\0';
	return (ret);
}
