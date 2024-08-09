/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:41:19 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/09 17:41:20 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rb(t_list **head)
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

static void	rra(t_list **head)
{
	t_list	*last;

	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	(*head)->previous = last;
	*head = last;
	last = last->previous;
	last->next = NULL;
	(*head)->previous = NULL;
}

static void	rrb(t_list **head)
{
	t_list	*last;

	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	(*head)->previous = last;
	*head = last;
	last = last->previous;
	last->next = NULL;
	(*head)->previous = NULL;
}

static void	rrr_rr_ss(t_list **stack_a, t_list **stack_b, char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	if (length == 3 && ft_strcmp(str, "rrr") == 0)
	{
		rra(stack_a);
		rrb(stack_b);
	}
	if (length == 2 && ft_strcmp(str, "ss") == 0)
	{
		sa(stack_a);
		sb(stack_b);
	}
	if (length == 2 && ft_strcmp(str, "rr") == 0)
	{
		ra(stack_a);
		rb(stack_b);
	}
}

void	operation(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa") == 0)
		sa(stack_a);
	if (ft_strcmp(str, "sb") == 0)
		sb(stack_b);
	if (ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "rr") == 0
		|| ft_strcmp(str, "rrr") == 0)
		rrr_rr_ss(stack_a, stack_b, str);
	if (ft_strcmp(str, "pa") == 0)
		pa(stack_a, stack_b);
	if (ft_strcmp(str, "pb") == 0)
		pb(stack_a, stack_b);
	if (ft_strcmp(str, "ra") == 0)
		ra(stack_a);
	if (ft_strcmp(str, "rb") == 0)
		rb(stack_b);
	if (ft_strcmp(str, "rra") == 0)
		rra(stack_a);
	if (ft_strcmp(str, "rrb") == 0)
		rrb(stack_b);
	ft_putstr(str);
	ft_putstr("\n");
}
