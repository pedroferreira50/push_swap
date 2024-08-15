#include "push_swap.h"
#include "get_next_line.h"

int	operation_checker(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0 || ft_strcmp(str, "rr\n") == 0
		|| ft_strcmp(str, "rrr\n") == 0)
		rrr_rr_ss(stack_a, stack_b, str);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else
		return (1);
	return (0);
}

int test(t_list **stack_a, t_list **stack_b)
{
    char *line;

    while ((line = get_next_line(0)) != NULL)
    {
        if (operation_checker(line, stack_a, stack_b) == 1)
        {
            write(2, "Error\n", 6);
            free(line);
            return 0;
        }
        free(line);
    }

    return 1;
}

void	process_stacks_checker(char **new_argv, char *concatenated_args)
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
	if (test(stack_a, stack_b) == 0 || check_errors(stack_a, concatenated_args))
	{
		cleanup(stack_a, stack_b, concatenated_args, new_argv);
		return ;
	}
	if (is_sorted(*stack_a) == 0 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	cleanup(stack_a, stack_b, concatenated_args, new_argv);
}

int	main(int argc, char **argv)
{
	char	*concatenated_args;
	char	**new_argv;

	concatenated_args = NULL;
	new_argv = NULL;
	if (argc < 2)
		return (-1);
	if (prepare_args(argc, argv, &concatenated_args, &new_argv) == -1)
		return (-1);
	process_stacks_checker(new_argv, concatenated_args);
	return (0);
}