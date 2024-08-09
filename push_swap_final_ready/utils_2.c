/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:41:02 by pviegas-          #+#    #+#             */
/*   Updated: 2024/08/09 17:41:03 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	dest_length = 0;
	src_length = 0;
	i = 0;
	while (dest[dest_length] != '\0')
		dest_length++;
	while (src[src_length] != '\0')
		src_length++;
	j = dest_length;
	if (dest_length < size - 1 && size > 0)
	{
		while (i + dest_length < size - 1 && src[i] != '\0')
			dest[j++] = src[i++];
		dest[j] = '\0';
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}

char	*concatenate_args(int argc, char **argv)
{
	int		total_len;
	int		i;
	char	*result;

	total_len = 0;
	i = 1;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]) + 1;
		i++;
	}
	result = (char *)malloc(total_len * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(result, argv[i], total_len);
		if (i < argc - 1)
			ft_strlcat(result, " ", total_len);
		i++;
	}
	return (result);
}

int	count_nodes(t_list *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
