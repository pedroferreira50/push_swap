/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:21:02 by pviegas-          #+#    #+#             */
/*   Updated: 2024/07/25 15:11:55 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (c == 0)
		return (1);
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			i++;
		else
		{
			count++;
			while (s[i] != (char)c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**free_on_error(char **tab, unsigned int i)
{
	while (i > 0)
	{
		free(tab[i - 1]);
		i--;
	}
	free(tab);
	return (NULL);
}

static char	*idk(const char *s, char c, char **array, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	array[index] = (char *)malloc ((i + 1) * sizeof(char));
	if (array[index] == NULL)
		return (NULL);
	while (s[j] != (char)c && s[j] != '\0')
	{
		array[index][j] = s[j];
		j++;
	}
	array[index][j] = '\0';
	return (array[index]);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**sstr;

	i = 0;
	k = 0;
	sstr = (char **)malloc ((countwords(s, (char)c) + 1) * sizeof(char *));
	if (sstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			i++;
		else
		{
			idk (&s[i], (char)c, sstr, k);
			if (sstr[k] == NULL)
				return (free_on_error(sstr, k));
			k++;
			while (s[i] != (char)c && s[i] != '\0')
				i++;
		}
	}
	sstr[k] = NULL;
	return (sstr);
}

/*
int	main(void)
{
	char	*str1 = " um, dois, tres, quatro, cinco, seis, sete, oito, nove. ";
	char	*str2 = " um, dois, tres, quatro, cinco, seis, sete, oito, nove.";
	char	*str3 = "um, dois, tres, quatro, cinco, seis, sete, oito, nove. ";
	char	*str4 = "um, dois, tres, quatro, cinco, seis, sete, oito, nove.";
	char	*str5 = "um.";
	char	*str6 = "  um, dois, tres, quatro, cinco, seis, sete, oito, nove. .";
	char	*str7 = "";
	char	*str8 = "            ";
	char	chr = ' ';

	char **tab = ft_split(str1, chr);
	int	num;

	num = 0;
	printf("answer = %d correct answer = 9\n", countwords(str1, chr));
	printf("answer = %d correct answer = 9\n", countwords(str2, chr));
	printf("answer = %d correct answer = 9\n", countwords(str3, chr));
	printf("answer = %d correct answer = 9\n", countwords(str4, chr));
	printf("answer = %d correct answer = 1\n", countwords(str5, chr));
	printf("answer = %d correct answer = 10\n", countwords(str6, chr));
	printf("answer = %d correct answer = 0\n", countwords(str7, chr));
	printf("answer = %d correct answer = 0\n", countwords(str8, chr));

	while (tab[num] != NULL) 
    	num++;
	for (int i = 0; i < num; i++) {
        printf("%s\n", tab[i]);
        free(tab[i]);  // Free individual substrings
    }
    free(tab);  // Free the array of pointers

	return (0);
}*/
			/*
			j = i;
			while (s[j] != (char)c && s[j] != '\0')
				j++;
			sstr[k] = (char *)malloc((j - i + 1) * sizeof(char));
			if (sstr[k] == NULL)
				return (free_on_error(sstr, k));
			l = 0;
			while (i < j)
				sstr[k][l++] = s[i++];
			sstr[k][l] = '\0';
			*/