/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:39:39 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 11:37:59 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_double(t_data *data)
{
	t_data	*curr;
	t_data	*tmp;

	curr = data;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (curr->content == tmp->content)
			{
				free_list(data);
				show_error_mess();
			}
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

void	check_error(char *s, char **ptr)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+'))
			++i;
		else if (!ft_isdigit(s[i]))
		{
			double_free(ptr);
			show_error_mess();
			++i;
		}
		else
			++i;
	}
}

size_t	count_size(int ac, char **av)
{
	int		i;
	int		j;
	int		counter;
	char	**arg;

	counter = 0;
	i = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (NULL == arg)
			exit(1);
		j = -1;
		while (arg[++j] != NULL)
			++counter;
	}
	return (counter);
}

/*
 * Return error if 
 *  - some parameters are not number
 *  - not contained in a int
 *  - has a double
 */

void	check_error_space(char **av, char ***arg, int i, int *j)
{
	while (av[i][*j])
	{
		while (av[i][*j] == 32 && av[i][*j])
			*j += 1;
		if (ft_isdigit(av[i][*j]) == 0
			&& (av[i][*j] != '-' && av[i][*j] != '+'))
		{
			if (*arg && *arg[0])
				double_free(*arg);
			show_error_mess();
		}
		else
			*j += 1;
	}
}

void	handle_errors(int ac, char **av)
{
	int				i;
	int				j;
	long long int	n;
	char			**arg;

	i = 0;
	while (++i < ac)
	{
		arg = NULL;
		j = 0;
		check_error_space(av, &arg, i, &j);
		arg = ft_split(av[i], ' ');
		if (!arg)
			exit(1);
		j = -1;
		while (arg[++j] != NULL)
		{
			check_error(arg[j], arg);
			n = ft_atol(arg[j]);
			if (!(n >= INT_MIN && n <= INT_MAX))
				free_and_error(&arg);
		}
		double_free(arg);
	}
}
