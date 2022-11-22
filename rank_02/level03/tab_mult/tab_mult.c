/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:57:24 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/21 03:05:09 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *s)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		num = num * 10 + (s[i] - 48);
		i++;
	}
	return (num);
}

void	putnbr(int num)
{
	char	c;

	if (num >= 10)
	{
		putnbr(num / 10);
		putnbr(num % 10);
	}
	else if (num < 10)
	{
		c = num + 48;
		write(1, &c, 1);
	}
}

void	table(int num, char *s)
{
	int		i;
	int		j;
	char	n;
	int		result;

	i = 1;
	n = '1';
	while (i <= 9)
	{
		write(1, &n, 1);
		write(1, " ", 1);
		write(1, "x", 1);
		write(1, " ", 1);
		j = 0;
		while (s[j] != '\0')
		{
			write(1, &s[j], 1);
			j++;
		}
		write(1, " ", 1);
		write(1, "=", 1);
		write(1, " ", 1);
		result = num * i;
		putnbr(result);
		if (i != 9)
			write(1, "\n", 1);
		n++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		table(ft_atoi(argv[1]), argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
