/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:41:07 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 11:44:15 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_data	*create_new_element(int nbr)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (NULL == new)
		return (NULL);
	new->content = nbr;
	new->cost = 0;
	new->next = NULL;
	return (new);
}

void	insert_last(t_data **data, t_data *new)
{
	t_data	*curr;

	if (*data == NULL)
	{
		*data = new;
		return ;
	}
	curr = *data;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	insert_data(t_data **data, int ac, char **av)
{
	int		i;
	int		j;
	char	**arg;
	t_data	*new_el;

	i = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			exit(1);
		j = -1;
		while (arg[++j] != NULL)
		{
			new_el = create_new_element(ft_atoi(arg[j]));
			if (!new_el)
				exit(1);
			insert_last(data, new_el);
		}
		double_free(arg);
	}
}
