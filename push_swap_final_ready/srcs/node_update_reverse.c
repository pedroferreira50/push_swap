/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_update_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:41:33 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/14 02:39:31 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

int find_closest_higher(t_list *current, t_list **list_a, int min, int *found)
{
    int closest_higher;
    t_list *current_a;

	current_a = *list_a;
	closest_higher = INT_MAX;
    while (current_a != NULL)
    {
        if (current_a->content > current->content && current_a->content < closest_higher)
        {
            closest_higher = current_a->content;
            *found = 1;
        }
        current_a = current_a->next;
    }
    current_a = *list_a;
    while (current_a != NULL)
    {
        if (current_a->content == INT_MAX && *found == 0)
                return (INT_MAX);
        current_a = current_a->next;
    }
	if (*found == 1)
        return (closest_higher);
    return (min);
}
int find_smallest_number(t_list *list)
{
    int smallest = list->content;
    t_list *current = list->next;

    while (current != NULL)
    {
        if (current->content < smallest)
        {
            smallest = current->content;
        }
        current = current->next;
    }

    return smallest;
}

int find_target_reverse(t_list *current, t_list **list_a)
{
    int target;
    t_list *current_a;
	int	min;
	int	found;

	found = 0;
	current_a = *list_a;
	min = find_smallest_number(current_a);
	target = find_closest_higher(current, list_a, min, &found);
    if (target == min)
        return (min);
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


