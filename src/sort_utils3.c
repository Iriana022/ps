/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:46:19 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 13:47:24 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
