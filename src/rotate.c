/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:43:11 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 11:43:39 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_data **stack, const char *name)
{
	int	value;
	t_data	*new;
	t_data	*tmp;
	t_data	*last;

	value = (*stack)->content;
	new = create_new_element(value);
	if (NULL == new)
		exit(1);
	last = find_last(*stack);
	last->next = new;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	if (NULL == name)
		return ;
	if (ft_strncmp(name, "ra", 69) == 0)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_data **a, t_data **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_data **stack, const char *name)
{
	t_data	*last;
	t_data	*new;
	t_data	*curr;

	last = find_last(*stack);
	new = create_new_element(last->content);
	if (NULL == new)
		exit(1);
	curr = *stack;
	while (curr->next)
	{
		if (curr->next->next == NULL)
		{
			curr->next = NULL;
			break ;
		}			
		curr = curr->next;		
	}
	new->next = *stack;
	*stack = new;
	free(last);
	if (NULL == name)
		return ;
	if (ft_strncmp(name, "rra", 69) == 0)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data **a, t_data **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	ft_putstr_fd("rrr\n", 1);
}
