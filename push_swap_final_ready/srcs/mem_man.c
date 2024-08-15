/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:40:36 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/09 17:44:04 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_string_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	cleanup(t_list **stack_a, t_list **stack_b,
				char *concatenated_args, char **new_argv)
{
	if (stack_a != NULL)
	{
		free_list(*stack_a);
		free(stack_a);
	}
	if (stack_b != NULL)
	{
		free_list(*stack_b);
		free(stack_b);
	}
	if (concatenated_args != NULL)
		free(concatenated_args);
	free_string_array(new_argv);
}

int	prepare_args(int argc, char **argv,
				char **concatenated_args, char ***new_argv)
{
	*concatenated_args = concatenate_args(argc, argv);
	if (*concatenated_args == NULL)
		return (-1);
	*new_argv = ft_split(*concatenated_args, ' ');
	if (*new_argv == NULL)
	{
		free(*concatenated_args);
		return (-1);
	}
	return (0);
}

void	process_stacks(char **new_argv, char *concatenate_args)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
	{
		cleanup(stack_a, stack_b, NULL, new_argv);
		return ;
	}
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, new_argv);
	if (check_errors(stack_a, concatenate_args))
	{
		cleanup(stack_a, stack_b, concatenate_args, new_argv);
		return ;
	}
	if (is_sorted(*stack_a))
		push_swap_algo(stack_a, stack_b);
	cleanup(stack_a, stack_b, concatenate_args, new_argv);
}
