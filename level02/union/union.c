/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:23:42 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/19 21:37:15 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	self_loop(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	get_without_db(char *a, char *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a[i])
	{
		if (self_loop(a, a[i], i) == 1)
			write(1, &a[i], 1);
		i++;
	}
	while (b[j])
	{
		if (self_loop(b, b[j], j) == 1)
		{
			if (self_loop(a, b[j], i) == 1)
				write(1, &b[j], 1);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	char	*first;
	char	*second;
	char	*s;

	if (argc == 3)
	{
		first = argv[1];
		second = argv[2];
		get_without_db(first, second);
	}
	write(1, "\n", 1);
	return (0);
}
