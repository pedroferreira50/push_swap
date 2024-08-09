#include "push_swap.h"

void	update_movements(t_list **head)
{
	int		stack_size;
	t_list	*temp;

	stack_size = 0;
	temp = *head;
	while (temp != NULL)
	{
		stack_size++;
		temp = temp->next;
	}
	temp = *head;
	while (temp != NULL)
	{
		temp->movement_to_top = movements_to_top(stack_size,
				temp->position, &temp->move_down);
		temp = temp->next;
	}
}

int	assign_positions(t_list **head)
{
	int		position;
	t_list	*temp;

	position = 1;
	temp = *head;
	while (temp != NULL)
	{
		temp->position = position++;
		temp = temp->next;
	}
	return (position - 1);
}

void	find_target_nodes(t_list **list_a, t_list **list_b)
{
	t_list	*current_a;

	current_a = *list_a;
	while (current_a != NULL)
	{
		current_a->target_index = find_target(current_a->content, list_b);
		current_a = current_a->next;
	}
}

void	index_stack(t_list **stack)
{
	int		size;
	int		*index_array;
	int		i;
	t_list	*current;

	size = 0;
	current = *stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	index_array = (int *)malloc(size * sizeof(int));
	if (index_array == NULL)
		return ;
	current = *stack;
	i = 0;
	while (current != NULL)
	{
		index_array[i++] = current->content;
		current = current->next;
	}
	bubble_sort(index_array, size);
	update_index_with_array(stack, index_array, size);
	free(index_array);
}

void	execute_all_functions(t_list **stack_a, t_list **stack_b)
{
	index_stack(stack_a);
	find_target_nodes(stack_a, stack_b);
	assign_positions(stack_a);
	update_movements(stack_a);
	index_stack(stack_b);
	assign_positions(stack_b);
	update_movements(stack_b);
}
