/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 08:13:19 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:54 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (ft_strlen(big) == 0)
		return (NULL);
	while (len)
	{
		if (*big == *little)
		{
			i = 0;
			while (little[i] == big[i])
			{
				if (len < ft_strlen(little))
					return (NULL);
				i++;
				if (little[i] == '\0')
					return ((char *)(big));
			}
		}
		len--;
		big++;
	}
	return (NULL);
}
