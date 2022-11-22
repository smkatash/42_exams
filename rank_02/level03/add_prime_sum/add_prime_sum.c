/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:16:08 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 01:44:12 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *s)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (s[i])
	{
		if (s[i] == '-')
		{
			if (s[i] == '-')
				neg = -1;
			i++;
		}
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * neg);
}

void	ft_itoa_print(int num)
{
	char	s;

	if (num > 9)
	{
		ft_itoa_print(num / 10);
		ft_itoa_print(num % 10);
	}
	else if (num >= 0 && num <= 9)
	{
		s = num + '0';
		write(1, &s, 1);
	}
}

int	add_primes(int num)
{
	int	i;
	int	j;
	int	count;
	int	n;

	j = 2;
	n = 0;
	while (j <= num)
	{
		i = 1;
		count = 0;
		while (i <= num)
		{
			if (j % i == 0)
				count++;
			i++;
		}
		if (count == 2)
			n += j;
		j++;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	char	zero;
	int		num;

	zero = 48;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		if (num > 1)
		{
			num = add_primes(num);
			ft_itoa_print(num);
		}
		else
			write(1, &zero, 1);
	}
	else
		write(1, &zero, 1);
	write(1, "\n", 1);
	return (0);
}
