/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_update_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:41:27 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/09 17:41:28 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	movements_to_top(int stack_size, int node_position, int *move_down)
{
	int	middle;

	middle = (stack_size + 1) / 2;
	if (node_position > middle)
	{
		*move_down = 1;
		return (stack_size - node_position + 1);
	}
	else
	{
		*move_down = 0;
		return (node_position - 1);
	}
}

// c_s is closest_smaller
int	find_target(int value, t_list **list_b)
{
	t_list	*current;
	int		c_s;
	int		max;

	current = *list_b;
	c_s = -1;
	while (current != NULL)
	{
		if (current->content < value && (c_s == -1 || current->content > c_s))
			c_s = current->content;
		current = current->next;
	}
	if (c_s == -1)
	{
		current = *list_b;
		max = current->content;
		while (current != NULL)
		{
			if (current->content > max)
				max = current->content;
			current = current->next;
		}
		return (max);
	}
	return (c_s);
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	update_index_with_array(t_list **head, int *arr, int n)
{
	t_list	*current;
	int		i;

	current = *head;
	i = 0;
	while (current != NULL)
	{
		while (i < n)
		{
			if (arr[i] == current->content)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}
