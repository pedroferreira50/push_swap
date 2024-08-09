#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	long			content;
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
	int				move_down;
	int				movement_to_top;
	int				target_index;
	int				position;
}	t_list;

void	operation(char *str, t_list **stack_a, t_list **stack_b);
void	push_cheapest_to_b(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	push_one_node_b_to_a(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
int		movements_to_top(int stack_size, int node_position, int *move_down);
int		find_target(int value, t_list **list_b);
void	bubble_sort(int *arr, int n);
void	update_index_with_array(t_list **head, int *arr, int n);
void	index_stack(t_list **stack);
int		assign_positions(t_list **head);
void	update_movements(t_list **head);
int		count_nodes(t_list *stack);
void	execute_all_functions_reverse(t_list **stack_a, t_list **stack_b);
void	execute_all_functions(t_list **stack_a, t_list **stack_b);
long	ft_atoi(const char *nptr);
int		check_errors(t_list **stack_a, char *concatenated_args);
int		ft_isdigit(int c);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **head);
char	*concatenate_args(int argc, char **argv);
void	init_stack(t_list **stack, char **argv);
int		is_sorted(t_list *head);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(const char *str);

#endif