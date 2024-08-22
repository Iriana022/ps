/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:59:18 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:29 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)destination;
	csrc = (char *)source;
	if (!cdest && !csrc)
		return (NULL);
	if (source >= destination)
	{
		ft_memcpy(cdest, csrc, size);
	}
	else
	{
		while (size)
		{
			*(cdest + (size - 1)) = *(csrc + (size - 1));
			size--;
		}
	}
	return (destination);
}
