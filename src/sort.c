/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:43:47 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:09:21 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	clean_cost(t_data **a)
{
	t_data	*curr;

	curr = *a;
	while (curr)
	{
		curr->cost = 0;
		curr = curr->next;
	}
}

void	exec_ins_ab(t_data **a, t_data **b, size_t i_a)
{
	size_t	i;
	size_t	l_a;

	l_a = count_list(*a);
	i = -1;
	while (++i < i_a - 1 && i_a <= (l_a / 2))
		rotate(a, "ra");
	i = -1;
	while (++i < l_a - i_a + 1 && i_a > (l_a / 2))
		reverse_rotate(a, "rra");
	push(a, b, "pa");
}

void	ajust(t_data **a)
{
	size_t	min_index;
	size_t	len_a;
	size_t	i;

	min_index = find_min_index(a);
	len_a = count_list(*a);
	i = -1;
	while (++i < min_index - 1 && min_index <= (len_a / 2))
		rotate(a, "ra");
	i = -1;
	while (++i < len_a - min_index + 1 && min_index > (len_a / 2))
		reverse_rotate(a, "rra");
}

void	final_sort(t_data **a, t_data **b)
{
	t_data			*curr;
	size_t			big_than_b;
	size_t			len_a;

	if (!is_sorted(*a))
		sort_three(a);
	curr = *b;
	len_a = count_list(*a);
	while (curr)
	{
		if (is_new_max(curr->content, a))
			big_than_b = calc_max_b_index(*a);
		else
			big_than_b = search_big_than_b(*a, curr->content);
		exec_ins_ab(a, b, big_than_b);
		len_a++;
		curr = *b;
	}
	if (!is_sorted(*a))
		ajust(a);
}

void	sort(t_data **a, t_data **b)
{
	int		stack_len;
	t_cheap	*cheapest;

	push(b, a, "pb");
	push(b, a, "pb");
	stack_len = count_list(*a);
	while (stack_len > 3)
	{
		catch_cost(a, b);
		cheapest = find_cheapest(*a);
		if (!cheapest)
			exit(1);
		clean_cost(a);
		exec(a, b, cheapest, 0);
		--stack_len;
		free(cheapest);
	}
	final_sort(a, b);
}
