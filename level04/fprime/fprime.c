/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:12:37 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/22 05:30:36 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int	is_prime(int n)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i <= n)
	{
		if (n % i == 0)
			count++;
		i++;
	}
	if (count == 2)
		return (n);
	return (-1);
}

int	divide_num(int num, int prime)
{
	if (num % prime == 0)
	{
		num = num / prime;
		return (num);
	}
	return (-1);
}

void	find_primes(int num)
{
	int	prime;

	prime = 2;
	if (num == 1)
		printf("%d", num);
	else
	{
		while (prime <= num)
		{
			if (num == 1)
				break ;
			if (is_prime(prime) != -1)
			{
				while (divide_num(num, prime) != -1)
				{
					num = divide_num(num, prime);
					if (num == 1)
						printf("%d", prime);
					else
						printf("%d*", prime);
				}
			}
			prime++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		find_primes(ft_atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
