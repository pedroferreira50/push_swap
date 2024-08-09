#include "push_swap.h"

int	find_closest_higher(t_list *current, t_list **list_a)
{
	int		closest_higher;
	t_list	*current_a;

	closest_higher = INT_MAX;
	current_a = *list_a;
	while (current_a != NULL)
	{
		if (current_a->content > current->content
			&& current_a->content < closest_higher)
		{
			closest_higher = current_a->content;
		}
		current_a = current_a->next;
	}
	return (closest_higher);
}

int	find_target_reverse(t_list *current, t_list **list_a)
{
	int		target;
	int		min;
	t_list	*current_a;

	target = find_closest_higher(current, list_a);
	current_a = *list_a;
	if (target == INT_MAX)
	{
		min = current_a->content;
		while (current_a != NULL)
		{
			if (current_a->content < min)
			{
				min = current_a->content;
			}
			current_a = current_a->next;
		}
		return (min);
	}
	return (target);
}

void	find_target_nodes_reverse(t_list **list_a, t_list **list_b)
{
	t_list	*current_b;

	current_b = *list_b;
	while (current_b != NULL)
	{
		current_b->target_index = find_target_reverse(current_b, list_a);
		current_b = current_b->next;
	}
}

void	execute_all_functions_reverse(t_list **stack_a, t_list **stack_b)
{
	index_stack(stack_a);
	find_target_nodes_reverse(stack_a, stack_b);
	assign_positions(stack_a);
	update_movements(stack_a);
	index_stack(stack_b);
	assign_positions(stack_b);
	update_movements(stack_b);
}

/* int	find_target_reverse(t_list *current, t_list **list_a)
{
	int		closest_higher;
	int		target;
	int		min;
	t_list	*current_a;

	current_a = *list_a;
	target = INT_MAX;
	closest_higher = INT_MAX;
	while (current_a != NULL)
	{
		if (current_a->content > current->content
			&& current_a->content < closest_higher)
		{
			closest_higher = current_a->content;
			target = closest_higher;
		}
		current_a = current_a->next;
	}
	if (target == INT_MAX)
	{
		current_a = *list_a;
		min = current_a->content;
		while (current_a != NULL)
		{
			if (current_a->content < min)
				min = current_a->content;
			current_a = current_a->next;
		}
		return (min);
	}
	return (target);
} */
