#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	if (new == NULL)
		return ;
	if (*lst != NULL)
	{
		temp_lst = *lst;
		while (temp_lst->next != NULL)
		{
			temp_lst = temp_lst->next;
		}
		temp_lst->next = new;
		new->previous = temp_lst;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		new->previous = NULL;
		new->next = NULL;
	}
}

t_list	*ft_lstnew(long content)
{
	t_list	*newlst;

	newlst = malloc (sizeof(t_list));
	if (newlst == NULL)
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	newlst->previous = NULL;
	return (newlst);
}

long	ft_atoi(const char *nptr)
{
	long	i;
	long	j;
	long	minus;
	long	final;

	i = 0;
	j = 0;
	minus = 1;
	if (nptr == NULL)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		j = (j * 10) + (nptr[i] - '0');
		i++;
	}
	final = j * minus;
	return (final);
}

int	is_sorted(t_list *head)
{
	t_list	*current;

	current = head;
	if (!head || !head->next)
		return (0);
	while (current->next)
	{
		if (current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	init_stack(t_list **stack, char **argv)
{
	t_list	*new;
	long	i;

	i = 0;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
}
