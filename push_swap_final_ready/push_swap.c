/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:41:10 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/13 07:26:40 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


int	main(int argc, char **argv)
{
	char	*concatenated_args;
	char	**new_argv;

	concatenated_args = NULL;
	new_argv = NULL;
	if (argc < 2)
		return (-1);
	/*if (argc >= 2 && argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit (1);
	}*/
	if (prepare_args(argc, argv, &concatenated_args, &new_argv) == -1)
		return (-1);
	process_stacks(new_argv, concatenated_args);
	return (0);
}
