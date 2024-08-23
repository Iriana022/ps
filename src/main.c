/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:42:28 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/23 09:44:02 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ret(t_data *p)
{
	free_list(p);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*a;
	t_data	*b;
	size_t	stack_len;

	if (ac == 1)
		return (1);
	handle_errors(ac, av);
	a = NULL;
	b = NULL;
	insert_data(&a, ac, av);
	check_double(a);
	stack_len = count_list(a);
	if (stack_len == 1)
		return (ret(a));
	else if (stack_len == 2 && !is_sorted(a))
		sort_two(&a);
	else if (stack_len == 3 && !is_sorted(a))
		sort_three(&a);
	else if (stack_len > 3 && !is_sorted(a))
		sort(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
