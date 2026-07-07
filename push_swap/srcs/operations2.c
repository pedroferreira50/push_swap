/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:41:15 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/09 17:41:16 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first->next = third;
	if (third != NULL)
		third->previous = first;
	second->next = first;
	first->previous = second;
	second->previous = NULL;
	*stack = second;
}

void	sb(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first->next = third;
	if (third != NULL)
		third->previous = first;
	second->next = first;
	first->previous = second;
	second->previous = NULL;
	*stack = second;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	top_b = *stack_b;
	if (*stack_b == NULL)
		return ;
	*stack_b = (*stack_b)->next;
	top_b->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->previous = top_b;
	top_b->previous = NULL;
	*stack_a = top_b;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;

	top_a = *stack_a;
	if (*stack_a == NULL)
		return ;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->previous = top_a;
	top_a->previous = NULL;
	*stack_b = top_a;
}

void	ra(t_list **head)
{
	t_list	*last;

	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	(*head)->previous = last;
	*head = (*head)->next;
	(*head)->previous = last;
	last->next->next = NULL;
}
