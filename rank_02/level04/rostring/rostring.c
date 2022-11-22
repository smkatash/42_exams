/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 02:47:39 by kanykei           #+#    #+#             */
/*   Updated: 2022/07/24 03:48:18 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	word_len(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
		{
			while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
			{
				i++;
				count++;
				if (str[i] == '\0')
					return (count);
			}
		}
		count++;
		while(str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
			i++;
	}
	return (count);
}

int	skip_first(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
		i++;
	while(str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
		i++;
	while(str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return(-1);
	return (i);
}

int	find_first(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while(str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
			i++;
		if(str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
			return (i);
		else
			i++;
	}
	return (-1);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*rostring(char *str)
{
	int	i;
	int	j;
	int	words;
	char *rot;

	words = word_len(str);
	rot = malloc(sizeof(char) * (words + 1));
	if (!rot)
		return (NULL);
	j = 0;
	i = skip_first(str);
	if (i == -1)
	{
		i = 0;
		while (str[i])
		{
			while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
				rot[j++] = str[i++];
			i++;
		}
		rot[j] = '\0';
		return (rot);
	}
	while (str[i])
	{
		if (str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
		{
			rot[j++] = str[i++];
			while (str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
				i++;
		}
		while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
			rot[j++] = str[i++];
	}
	rot[j++] = ' ';
	i = find_first(str);
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
		rot[j++] = str[i++];
		
	rot[j] = '\0';
	return (rot);
}


int	main(int argc, char **argv)
{
	char	*str;
	if (argc == 2)
	{
		str = rostring(argv[1]);
		put_str(str);
		free(str);
	}
	write(1, "\n", 1);
	return (0);
}