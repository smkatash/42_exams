/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:40:11 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/19 22:53:14 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	find_match(char *a, char *b)
{
	int	len;
	int	counter;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(a);
	counter = 0;
	while (a[i])
	{
		while (b[j])
		{
			if (a[i] == b[j])
			{
				counter++;
				i++;
			}
			j++;
		}
		i++;
	}
	if (len == counter)
		return (1);
	return (0);
}

void	print_first(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*first;
	char	*second;

	if (argc == 3)
	{
		first = argv[1];
		second = argv[2];
		if (find_match(first, second) == 1)
			print_first(first);
	}
	write(1, "\n", 1);
	return (0);
}
