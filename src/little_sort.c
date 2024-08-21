/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:41:46 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 11:42:10 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static size_t	find_max_index(t_data *stack)
{
	size_t	i;
	size_t	j;
	int	max;

	max = stack->content;
	j = 0;
	i = 0;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			i = j;
		}
		stack = stack->next;
		++j;
	}
	return (i);
}

void	sort_two(t_data **stack)
{
		swap(*stack, "sa");
}

void	sort_three(t_data **stack)
{
	size_t	i;

	i = find_max_index(*stack);
	if (i == 0)
		rotate(stack, "ra");
	else if (i == 1)
		reverse_rotate(stack, "rra");
	else
		swap(*stack, "sa");
	if (!is_sorted(*stack))
		swap(*stack, "sa");
}
