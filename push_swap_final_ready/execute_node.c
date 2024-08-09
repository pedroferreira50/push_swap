#include "push_swap.h"

static t_list	*find_target_node(t_list *stack_b, int target_index)
{
	t_list	*node;

	node = stack_b;
	while (node)
	{
		if (node->content == target_index)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static int	calculate_total_cost(t_list *stack_b, t_list *node)
{
	t_list	*target_node;
	int		cost_a;
	int		cost_b;

	if (node->movement_to_top < 0)
		cost_a = -node->movement_to_top;
	else
		cost_a = node->movement_to_top;
	target_node = find_target_node(stack_b, node->target_index);
	if (target_node)
	{
		if (target_node->movement_to_top < 0)
			cost_b = -target_node->movement_to_top;
		else
			cost_b = target_node->movement_to_top;
	}
	else
		cost_b = 0;
	return (cost_a + cost_b);
}

static t_list	*find_cheapest_node(t_list *stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;
	int		min_cost;
	int		total_cost;

	min_cost = INT_MAX;
	cheapest_node = NULL;
	while (stack_a)
	{
		total_cost = calculate_total_cost(*stack_b, stack_a);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest_node = stack_a;
		}
		stack_a = (stack_a)->next;
	}
	return (cheapest_node);
}

static void	execute_cheapest_move(t_list **stack_a,
	t_list **stack_b, t_list *cheapest_node, t_list *target_node)
{
	if (target_node->move_down == cheapest_node->move_down)
	{
		while (*stack_a != cheapest_node && *stack_b != target_node)
		{
			if (cheapest_node->move_down && target_node->move_down)
				operation("rrr", stack_a, stack_b);
			else
				operation("rr", stack_a, stack_b);
		}
	}
	while (*stack_a != cheapest_node)
	{
		if (cheapest_node->move_down)
			operation("rra", stack_a, NULL);
		else
			operation("ra", stack_a, NULL);
	}
	while (*stack_b != target_node)
	{
		if (target_node->move_down)
			operation("rrb", NULL, stack_b);
		else
			operation("rb", NULL, stack_b);
	}
	operation("pb", stack_a, stack_b);
}

void	push_cheapest_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;
	t_list	*target_node;

	cheapest_node = find_cheapest_node(*stack_a, stack_b);
	target_node = find_target_node(*stack_b, cheapest_node->target_index);
	if (cheapest_node)
		execute_cheapest_move(stack_a, stack_b, cheapest_node, target_node);
}
