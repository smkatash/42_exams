/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:18:25 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 22:25:42 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	display_arg(int num)
{
	char	c;

	if (num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		display_arg(num / 10);
		display_arg(num % 10);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		display_arg(argc - 1);
	}
	write(1, "\n", 1);
	return (0);
}
