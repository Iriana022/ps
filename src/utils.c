/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:44:47 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 13:50:39 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_data	*find_last(t_data *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

size_t	count_list(t_data *stack)
{
	size_t	counter;

	counter = 0;
	while (stack)
	{
		++counter;
		stack = stack->next;
	}
	return (counter);
}

size_t	is_sorted(t_data *stack)
{
	t_data	*curr;
	t_data	*tmp;

	curr = stack;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (curr->content > tmp->content)
				return (0);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (1);
}

size_t	find_min_index(t_data **stack)
{
	int		min;
	size_t	i;
	size_t	index;
	t_data	*curr;

	curr = *stack;
	min = curr->content;
	i = 1;
	index = i;
	while (curr)
	{
		if (curr->content < min)
		{
			min = curr->content;
			index = i;
		}
		++i;
		curr = curr->next;
	}
	return (index);
}
