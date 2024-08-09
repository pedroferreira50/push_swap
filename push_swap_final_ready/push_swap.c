#include "push_swap.h"

void	bring_smallest_to_top(t_list **stack)
{
	t_list	*current;
	t_list	*smallest_node;
	int		smallest_content;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	smallest_node = *stack;
	smallest_content = current->content;
	while (current != NULL)
	{
		if (current->content < smallest_content)
		{
			smallest_content = current->content;
			smallest_node = current;
		}
		current = current->next;
	}
	while (*stack != smallest_node)
	{
		if (smallest_node->move_down)
			operation("rra", stack, NULL);
		else
			operation("ra", stack, NULL);
	}
}

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!*stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
		operation("sa", stack_a, NULL);
	else if (first > second && second > third && first > third)
	{
		operation("sa", stack_a, NULL);
		operation("rra", stack_a, NULL);
	}
	else if (first > second && second < third && first > third)
		operation("ra", stack_a, NULL);
	else if (first < second && second > third && first < third)
	{
		operation("sa", stack_a, NULL);
		operation("ra", stack_a, NULL);
	}
	else if (first < second && second > third && first > third)
		operation("rra", stack_a, NULL);
}

void	execute_until_three_left(t_list **stack_a, t_list **stack_b, int ind)
{
	if (ind == 1)
	{
		while (count_nodes(*stack_b) > 0)
		{
			execute_all_functions_reverse(stack_a, stack_b);
			push_one_node_b_to_a(stack_a, stack_b);
		}
	}
	else if (ind == 0)
	{
		while (count_nodes(*stack_a) > 3)
		{
			execute_all_functions(stack_a, stack_b);
			push_cheapest_to_b(stack_a, stack_b);
		}
		execute_all_functions(stack_a, stack_b);
	}
}

void	push_swap_algo(t_list **stack_a, t_list **stack_b)
{
	if (count_nodes(*stack_a) == 4)
		operation("pb", stack_a, stack_b);
	else if (count_nodes(*stack_a) >= 5)
	{
		operation("pb", stack_a, stack_b);
		operation("pb", stack_a, stack_b);
	}
	else if (count_nodes(*stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	else if (count_nodes(*stack_a) == 2)
	{
		operation("ra", stack_a, stack_b);
		return ;
	}
	else if (count_nodes(*stack_a) == 1)
		return ;
	execute_until_three_left(stack_a, stack_b, 0);
	sort_three(stack_a);
	execute_until_three_left(stack_a, stack_b, 1);
	execute_all_functions_reverse(stack_a, stack_b);
	bring_smallest_to_top(stack_a);
}
void free_list(t_list *head) {
    t_list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void free_string_array(char **array) {
    int i = 0;
    if (array == NULL)
        return;
    while (array[i] != NULL) {
        free(array[i]);
        i++;
    }
    free(array);
}

void cleanup(t_list **stack_a, t_list **stack_b, char *concatenated_args, char **new_argv) {
    if (stack_a != NULL) {
        free_list(*stack_a);  // Free the linked list for stack_a
        free(stack_a);        // Free the stack_a pointer itself
    }
    if (stack_b != NULL) {
        free_list(*stack_b);  // Free the linked list for stack_b
        free(stack_b);        // Free the stack_b pointer itself
    }
    if (concatenated_args != NULL) {
        free(concatenated_args); // Free the concatenated args string
    }
    free_string_array(new_argv);  // Free the array of strings
}

/* int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*concatenated_args;
	char	**new_argv;

	if (argc < 2)
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	if(stack_a == NULL || stack_b == NULL)
	{
		cleanup(stack_a, stack_b, NULL, NULL);
		return (-1);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	concatenated_args = concatenate_args(argc, argv);
	if (concatenated_args == NULL)
	{
		cleanup(stack_a, stack_b, concatenated_args, NULL);
		return (-1);
	}
	new_argv = ft_split(concatenated_args, ' ');
	if (new_argv == NULL)
	{
		cleanup(stack_a, stack_b, concatenated_args , new_argv);
		return (-1);
	}
	init_stack(stack_a, new_argv);
	if (check_errors(stack_a, concatenated_args) == 1)
	{
		cleanup(stack_a, stack_b, concatenated_args, new_argv);
		return (-1);
	}
	if (is_sorted(*stack_a))
		push_swap_algo(stack_a, stack_b);
	cleanup(stack_a, stack_b, concatenated_args, new_argv);
	return (0);
} */

int prepare_args(int argc, char **argv, char **concatenated_args, char ***new_argv)
{
    *concatenated_args = concatenate_args(argc, argv);
    if (*concatenated_args == NULL)
        return -1;

    *new_argv = ft_split(*concatenated_args, ' ');
    if (*new_argv == NULL) {
        free(*concatenated_args);
        return -1;
    }

    return (0);
}

void process_stacks(char **new_argv, char *concatenate_args)
{
    t_list **stack_a;
    t_list **stack_b;

    stack_a = (t_list **)malloc(sizeof(t_list *));
    stack_b = (t_list **)malloc(sizeof(t_list *));
    if (!stack_a || !stack_b) {
        cleanup(stack_a, stack_b, NULL, new_argv);
        return;
    }
    *stack_a = NULL;
    *stack_b = NULL;
    init_stack(stack_a, new_argv);
    if (check_errors(stack_a, concatenate_args)) {
        cleanup(stack_a, stack_b, concatenate_args, new_argv);
        return;
    }
    if (is_sorted(*stack_a))
        push_swap_algo(stack_a, stack_b);
    cleanup(stack_a, stack_b, concatenate_args, new_argv);
}

int main(int argc, char **argv)
{
    char *concatenated_args;
    char **new_argv;

    concatenated_args = NULL;
    new_argv = NULL;
    if (argc < 2)
        return -1;
    if (prepare_args(argc, argv, &concatenated_args, &new_argv) == -1)
        return -1;
    process_stacks(new_argv, concatenated_args);
    return (0);
}
