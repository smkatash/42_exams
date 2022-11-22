/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:28:04 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 22:49:01 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	display(int one, int two)
{
	int	i;
	int	ref;
	int	max;

	if (one > two)
		ref = two;
	else
		ref = one;
	i = 1;
	while (i <= ref)
	{
		if (one % i == 0 && two % i == 0)
			max = i;
		i++;
	}
	printf("%d", max);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		display(atoi(argv[1]), atoi(argv[2]));
// 	}
// 	printf("\n");
// 	return (0);
// }
