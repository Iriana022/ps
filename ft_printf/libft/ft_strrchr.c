/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:23:01 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:13:25 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len_s;
	char	*ret_s;
	char	*ptr_ret;

	ret_s = (char *)s;
	len_s = ft_strlen(ret_s);
	ptr_ret = ret_s + len_s;
	while (len_s + 1)
	{
		if (*(ret_s + len_s) == (char)c)
			return (ptr_ret);
		ptr_ret--;
		len_s--;
	}
	return (0);
}
