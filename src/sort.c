/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriana <iriana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:43:47 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/21 22:24:32 by iriana           ###   ########.fr       */
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
	int	max;
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
			curr->cost = calc_cost_in_another_maner(curr->content, len_a, b, a_index);
		curr = curr->next;
		++a_index;
	}
}

void	exec(t_data **a, t_data **b, t_cheapest *cheapest)
{
	size_t	len_b;
	size_t	b_index;
	size_t	len_a;
	size_t	i;

	if (is_new_max(cheapest->content, b) || is_new_min(cheapest->content, b))
		b_index = calc_max_b_index(*b);
	else
		b_index = calc_directly_greather_than_a_index(*b, cheapest->content);
	len_b = count_list(*b);
	i = -1;
	if (b_index <= (size_t)(len_b / 2))
	{
		while (++i < b_index - 1)
			rotate(b, "rb");
	}
	else
	{
		while (++i < (size_t)len_b - b_index + 1)
			reverse_rotate(b, "rrb");
	}
	i = -1;
	len_a = count_list(*a);
	if (cheapest->index <= len_a / 2)
	{
		while (++i < (size_t)(cheapest->index - 1))
			rotate(a, "ra");
	}
	else
	{
		while (++i < (size_t)(len_a - cheapest->index + 1))
			reverse_rotate(a, "rra");
	}
	push(b, a, "pb");
}

void	print_cost(t_data **a)
{
	t_data *curr;
	
	curr = *a;
	while (curr)
	{
		printf("%d: %d\n", curr->content, curr->cost);
		curr = curr->next;
	}
}

t_cheapest	*find_cheapest(t_data *a)
{
	size_t		i;
	int			cheapest_cost;
	t_cheapest	*cheapest;

	cheapest = malloc(sizeof(t_cheapest));
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

void	push_in_a(t_data **a, t_data **b, size_t a_index, size_t len_a)
{
	size_t	i;

	i = -1;
	if (a_index <= len_a / 2)
	{
	while (++i < (size_t)(a_index - 1))
		rotate(a, "ra");
	}
	else if (a_index > len_a / 2)
	{
		while (++i < (size_t)(len_a - a_index + 1))
			reverse_rotate(a, "rra");
	}
	push(a, b, "pa");
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
	int			stack_len;
	t_cheapest	*cheapest;

	push(b, a, "pb");
	push(b, a, "pb");
	stack_len = count_list(*a);
	while (stack_len > 3)
	{
		catch_cost(a, b);
		print_cost(a);
		cheapest = find_cheapest(*a);	
		if (!cheapest)
			exit(1);
		clean_cost(a);
		exec(a, b, cheapest);
		--stack_len;
	}
	final_sort(a, b);
	free(cheapest);
}
