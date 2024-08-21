/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriana <iriana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:39:39 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/21 22:35:53 by iriana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

void	free_list(t_data *data)
{
	t_data	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		free(tmp);
	}
}

void	double_free(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	show_error_mess(void)
{
	ft_printf("Error\n");
	exit(1);
}

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
	int 	i;
	int	j;
	int	counter;
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
void	handle_errors(int ac, char **av)
{
	int 		i;
	int		j;
	long long int	n;
	char		**arg;

	i = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			exit(1);
		j = -1;
		while (arg[++j] != NULL)
		{
			check_error(arg[j], arg);
			n = ft_atol(arg[j]);
			if (!(n >= INT_MIN && n <= INT_MAX))
			{
				double_free(arg);
				show_error_mess();
			}
		}
	}
	double_free(arg);
}
