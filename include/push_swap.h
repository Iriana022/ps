#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

/* list structure */
typedef struct s_data
{
	int		content;
	int		cost;
	struct s_data	*next;
}	t_data;

/* cheapest */
typedef struct s_cheapest
{
	size_t	index;
	int		content;
}	t_cheapest;

/* error management */
void		handle_errors(int ac, char **av);
void		check_double(t_data *data);

/* atol */
long long int	ft_atol(const char *s);

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

/* utils */
void	print_data(t_data *data);
t_data	*find_last(t_data *node);
size_t	count_list(t_data *stack);
size_t	is_sorted(t_data *stack);
size_t	find_min_index(t_data **stack);
void	double_free(char **arr);
void	free_list(t_data *data);
#endif
