/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:28:07 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:24 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	pow_ten(int len)
{
	if (len == 0)
		return (1);
	else
		return (10 * pow_ten(len - 1));
}

static char	*result(int n, int total, char *arr)
{
	long int	res;
	int			i;

	i = 0;
	if (n < 0)
	{
		arr[i] = '-';
		i++;
		n *= -1;
	}
	while (total > 0)
	{
		res = n / pow_ten(total - 1);
		arr[i] = res + '0';
		n %= pow_ten(total - 1);
		total--;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	int			cd;
	char		*arr;
	int			total_length;

	cd = count_digit(n);
	total_length = cd;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		total_length++;
	arr = (char *)malloc((total_length + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr = result(n, cd, arr);
	return (arr);
}
