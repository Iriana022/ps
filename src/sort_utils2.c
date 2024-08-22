/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:38:04 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:09:44 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	calc_cost_in_another_maner(int a, int len_a, t_data **b, int a_index)
{
	size_t	b_index;
	size_t	i;
	size_t	cost;
	size_t	len_b;

	b_index = calc_directly_greather_than_a_index(*b, a);
	i = -1;
	cost = 0;
	len_b = count_list(*b);
	if (b_index <= (size_t)(len_b / 2))
		while (++i < b_index - 1)
			cost++;
	else
		while (++i < (size_t)len_b - b_index + 1)
			cost++;
	i = -1;
	if (a_index <= len_a / 2)
		while (++i < (size_t)(a_index - 1))
			cost++;
	else
		while (++i < (size_t)(len_a - a_index + 1))
			cost++;
	return (cost + 1);
}

void	catch_cost(t_data **a, t_data **b)
{
	t_data	*curr;
	int		value;
	int		a_index;
	size_t	len_a;

	curr = *a;
	a_index = 1;
	len_a = count_list(*a);
	while (curr)
	{
		value = curr->content;
		if (is_new_max(value, b) || is_new_min(value, b))
			curr->cost = calc_cost(a, b, a_index);
		else
			curr->cost = calc_cost_in_another_maner(
					curr->content, len_a, b, a_index);
		curr = curr->next;
		++a_index;
	}
}

void	exec(t_data **a, t_data **b, t_cheap *cheapest, size_t i)
{
	size_t	len_b;
	size_t	b_index;
	size_t	len_a;

	if (is_new_max(cheapest->content, b) || is_new_min(cheapest->content, b))
		b_index = calc_max_b_index(*b);
	else
		b_index = calc_directly_greather_than_a_index(*b, cheapest->content);
	len_b = count_list(*b);
	i = -1;
	if (b_index <= (size_t)(len_b / 2))
		while (++i < b_index - 1)
			rotate(b, "rb");
	else
		while (++i < (size_t)len_b - b_index + 1)
			reverse_rotate(b, "rrb");
	i = -1;
	len_a = count_list(*a);
	if (cheapest->index <= len_a / 2)
		while (++i < (size_t)(cheapest->index - 1))
			rotate(a, "ra");
	else
		while (++i < (size_t)(len_a - cheapest->index + 1))
			reverse_rotate(a, "rra");
	push(b, a, "pb");
}

t_cheap	*find_cheapest(t_data *a)
{
	size_t	i;
	int		cheapest_cost;
	t_cheap	*cheapest;

	cheapest = malloc(sizeof(t_cheap));
	if (NULL == cheapest)
		return (NULL);
	cheapest_cost = a->cost;
	i = 1;
	cheapest->index = i;
	cheapest->content = a->content;
	while (a)
	{
		if (a->cost < cheapest_cost)
		{
			cheapest_cost = a->cost;
			cheapest->index = i;
			cheapest->content = a->content;
		}
		++i;
		a = a->next;
	}
	return (cheapest);
}

size_t	search_big_than_b(t_data *a, int n)
{
	int			big_than_b;
	int			found;
	size_t		i;
	size_t		j;

	found = 0;
	i = 0;
	while (a && ++i)
	{
		if (found && a->content > n && a->content < big_than_b)
		{
			big_than_b = a->content;
			j = i;
		}
		if (a->content > n && !found)
		{
			found = 1;
			big_than_b = a->content;
			j = i;
		}
		a = a->next;
	}
	return (j);
}
