/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:44:19 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 11:44:40 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_data *data, const char *name)
{
	int	tmp;

	tmp = data->content;
	data->content = data->next->content;
	data->next->content = tmp;
	if (NULL == name)
		return ;
	if (ft_strncmp(name, "sa", 69) == 0)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *a, t_data *b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_putstr_fd("ss\n", 1);	
}

void	push(t_data **stack_one, t_data **stack_two, const char *name)
{
	int	value;
	t_data	*new;
	t_data	*tmp;

	value = (*stack_two)->content;
	new = create_new_element(value);
	new->next = *stack_one;
	*stack_one = new;
	tmp = *stack_two;
	*stack_two = (*stack_two)->next;
	free(tmp);
	if (ft_strncmp(name, "pa", 69) == 0)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}
