/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:58:47 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/22 14:19:27 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

/* list structure */
typedef struct s_data
{
	int				content;
	int				cost;
	struct s_data	*next;
}	t_data;

/* cheapest */
typedef struct s_cheapest
{
	size_t	index;
	int		content;
}	t_cheap;
typedef long long int	t_llint;
/* error management */
void	handle_errors(int ac, char **av);
void	check_double(t_data *data);
void	show_error_mess(void);

/* atol */
t_llint	ft_atol(const char *s);

/* init */
void	insert_data(t_data **data, int ac, char **av);
t_data	*create_new_element(int nbr);

/* operations */
void	swap(t_data *data, const char *name);
void	push(t_data **stack_one, t_data **stack_two, const char *name);
void	ss(t_data *a, t_data *b);
void	rotate(t_data **stack, const char *name);
void	rr(t_data **a, t_data **b);
void	reverse_rotate(t_data **stack, const char *name);
void	rrr(t_data **a, t_data **b);

/* sort */
void	sort_two(t_data **stack);
void	sort_three(t_data **stack);
void	sort_four(t_data **a, t_data **b);
void	sort(t_data **a, t_data **b);

/*sort_utils*/
size_t	is_new_max(int value, t_data **b);
size_t	is_new_min(int value, t_data **b);
size_t	calc_max_b_index(t_data *b);
size_t	calc_cost(t_data **a, t_data **b, size_t a_index);
size_t	calc_directly_greather_than_a_index(t_data *b, int a);
size_t	calc_cost_in_another_maner(int a, int len_a, t_data **b, int a_index);
void	catch_cost(t_data **a, t_data **b);
void	exec(t_data **a, t_data **b, t_cheap *cheapest, size_t i);
t_cheap	*find_cheapest(t_data *a);
size_t	search_big_than_b(t_data *a, int n);
void	push_in_a(t_data **a, t_data **b, size_t a_index, size_t len_a);

/* utils */
void	print_data(t_data *data);
t_data	*find_last(t_data *node);
size_t	count_list(t_data *stack);
size_t	is_sorted(t_data *stack);
size_t	find_min_index(t_data **stack);
void	double_free(char **arr);
void	free_list(t_data *data);
void	free_and_error(char ***arg);
#endif
