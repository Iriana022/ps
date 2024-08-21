/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:34:35 by irazafim          #+#    #+#             */
/*   Updated: 2024/03/11 12:17:53 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	if ((destination == NULL) && (source == NULL))
		return (NULL);
	cdest = (char *)destination;
	csrc = (char *)source;
	i = 0;
	while (i < size)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (destination);
}
