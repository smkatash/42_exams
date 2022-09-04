/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:58:43 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 22:15:48 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	search_hidden(char *first, char *second)
{
	int	i;
	int	j;
	int	len;
	int	count;

	len = ft_strlen(first);
	count = 0;
	i = 0;
	j = 0;
	while (first[i])
	{
		while (second[j])
		{
			if (second[j] == first[i])
			{
				count++;
				i++;
			}
			j++;
		}
		i++;
	}
	if (len == count)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		search_hidden(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
