/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:50:15 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/21 00:49:18 by ktashbae         ###   ########.fr       */
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
	while (s[i] != '\0')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	return (num);
}

void	print_hex(int num)
{
	char	c;

	if (num >= 16)
	{
		print_hex(num / 16);
		print_hex(num % 16);
	}
	if (num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else if (num < 16)
	{
		c = num + 'W';
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_hex(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
