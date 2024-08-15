/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:40:36 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/15 04:19:07 by pviegas-         ###   ########.fr       */
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
