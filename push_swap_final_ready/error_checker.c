/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:41:51 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/13 07:33:02 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_non_digit_characters(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '-')
			{
				if (ft_isdigit(str[i - 1]))
					return (1);
				if (!ft_isdigit(str[i + 1]))
					return (1);
			}
			else if (str[i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_values(t_list **list)
{
	t_list	*current;
	t_list	*runner;

	current = *list;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->content == runner->content)
				return (1);
			runner = runner->next;
		}
		if (current->content > 2147483647 || current->content < -2147483648)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_duplicates(t_list **list)
{
	t_list	*current;
	t_list	*runner;
	int		found;

	found = 0;
	current = *list;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->content == runner->content)
				return (found + 1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (found);
}

int	check_errors(t_list **stack_a, char *concatenated_args)
{
	if (has_non_digit_characters(concatenated_args) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_duplicates(stack_a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_values(stack_a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
