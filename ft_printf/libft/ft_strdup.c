/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:29:35 by irazafim          #+#    #+#             */
/*   Updated: 2024/02/27 07:39:33 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptrs;
	int		i;

	i = 0;
	ptrs = (char *)malloc(ft_strlen(s) + 1);
	if (ptrs != NULL)
	{
		while (s[i] != '\0')
		{
			ptrs[i] = s[i];
			i++;
		}
		ptrs[i] = '\0';
		return (ptrs);
	}
	return (NULL);
}
