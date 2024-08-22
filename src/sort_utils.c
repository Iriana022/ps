/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:32:34 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 13:48:23 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	is_new_max(int value, t_data **b)
{
	t_data	*curr;

	curr = *b;
	while (curr)
	{
		if (value < curr->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

size_t	is_new_min(int value, t_data **b)
{
	t_data	*curr;

	curr = *b;
	while (curr)
	{
		if (value > curr->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

size_t	calc_max_b_index(t_data *b)
{
	int		max;
	size_t	j;
	size_t	i;

	max = b->content;
	j = 1;
	i = 1;
	while (b)
	{
		if (b->content > max)
		{
			max = b->content;
			i = j;
		}
		b = b->next;
		++j;
	}
	return (i + 1);
}

size_t	calc_cost(t_data **a, t_data **b, size_t a_index)
{
	size_t	max_b_index;
	size_t	i;
	size_t	cost;
	size_t	len_b;
	size_t	len_a;

	max_b_index = calc_max_b_index(*b);
	i = -1;
	cost = 0;
	len_b = count_list(*b);
	if (max_b_index <= (size_t)(len_b / 2))
		while (++i < max_b_index - 1)
			cost++;
	else
		while (++i < (size_t)len_b - max_b_index + 1)
			cost++;
	i = -1;
	len_a = count_list(*a);
	if (a_index <= len_a / 2)
		while (++i < (size_t)(a_index - 1))
			cost++;
	else
		while (++i < (size_t)(len_a - a_index + 1))
			cost++;
	return (cost + 1);
}

size_t	calc_directly_greather_than_a_index(t_data *b, int a)
{
	int			big_than_a;
	int			found;
	size_t		i;
	size_t		j;

	found = 0;
	i = 1;
	j = i;
	while (b)
	{
		if (found && b->content < a && b->content > big_than_a)
		{
			big_than_a = b->content;
			j = i;
		}
		if (b->content < a && !found)
		{
			found = 1;
			big_than_a = b->content;
			j = i;
		}
		++i;
		b = b->next;
	}
	return (j);
}
