/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:11:04 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/24 19:37:56 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	int	tab[] = {8, 5, 8, 2, 10, 1, 50, -1};
// 	int	i;

// 	i = 0;
// 	sort_int_tab(tab, 8);
// 	while (i < 8)
// 	{
// 		printf("%d, ", tab[i++]);
// 	}
// 	return (0);
// }
