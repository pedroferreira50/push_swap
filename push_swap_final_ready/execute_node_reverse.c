#include <stdio.h>
#include <string.h>
#include "push_swap.h"

static t_list	*find_node_by_content(t_list **stack, int content)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->content == content)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	move_node_to_top(t_list **stack, t_list *target_node)
{
	while (*stack != target_node)
	{
		if (target_node->move_down)
			operation("rra", stack, NULL);
		else
			operation("ra", stack, NULL);
	}
}

void	push_one_node_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	t_list	*target_node;
	int		target_index;

	current_b = *stack_b;
	if (*stack_b == NULL)
		return ;
	target_index = current_b->target_index;
	target_node = find_node_by_content(stack_a, target_index);
	move_node_to_top(stack_a, target_node);
	operation("pa", stack_a, stack_b);
}
