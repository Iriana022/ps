/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriana <iriana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:44:47 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/21 21:56:10 by iriana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_substring(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		s++;
	}
	return (count);
}

static char	*copy_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	**loop_char(char **res, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			res[i++] = copy_word(s, c);
			if (!res[i - 1])
			{
				while (i--)
					free(res[i]);
				free(res);
				return (NULL);
			}
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		count_word;
	char	**result;

	count_word = nb_substring(s, c);
	result = (char **)malloc((count_word + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[count_word] = NULL;
	return ((char **)loop_char(result, s, c));
}
