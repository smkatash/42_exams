/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:47:33 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/04 12:48:58 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void put_nmb(int num)
{
	char str[10] = "0123456789";

	if (num > 9)
		put_nmb(num / 10);
	write(1, &str[num % 10], 1);
	
}

int	check_for_fizz_buzz(int number)
{
	if (number % 5 == 0 && number % 3 == 0)
		write(1, "fizzbuzz", 8);
	else if (number % 5 == 0)
		write(1, "buzz", 4);
	else if (number % 3 == 0)
		write(1, "fizz", 4);
	else
		return (0);
	return (1);
}

int	main(void)
{
	int	i;
	int	number;

	i = 1;
	while (i <= 100)
	{
		if (check_for_fizz_buzz(i) == 0)
			put_nmb(i);
		write(1, "\n", 1);
		i++;
	}
}
