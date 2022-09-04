/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 05:57:51 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/04 18:42:52 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			count++;
			while ((str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
				i++;
		}
		while ((str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')))
			i++;
	}
	return (count);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while(arr)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_length(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

char **copy_ptr(char **arr, char *str, int words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while(str[i] && j < words)
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		arr[j] = malloc(sizeof(char) * (count_length(&str[i]) + 1));
		if (!arr[j])
		{
			free_all(arr);
			return (NULL);
		}
		k = 0;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			arr[j][k++] = str[i++];
		}
		arr[j][k] = '\0';
		j++;
	}
	return (arr);
}

char	**ft_split(char *str)
{
	int	words;
	char **arr;

	words = count_words(str);
	arr = malloc(sizeof(char*) * (words + 1));
	if (!arr)
		return (NULL);
	arr = copy_ptr(arr, str, words);
	arr[words] = NULL;
	return (arr);
}

// int	main(void)
// {
// 	char *str = "me myself and i";
// 	char **split;
// 	int	i;

// 	i = 0;
// 	split = ft_split(str);
// 	while(split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	return (0);
// }