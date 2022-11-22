/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:47:17 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/04 18:41:41 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"
#include <stdio.h>

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (y <= size.y)
	{
		if (y >= begin.y)
		{
			x = 1;
			while (x <= size.x)
			{
				if (x == begin.x)
				{
					while (tab[x][y] == 0)
					{
						tab[x][y] = 'F';
						x++;
					}
				}
				x++;
			}
		}
		y++;
	}
}

void print_tab(char **a, t_point size)
{
	int i;
	int j;
	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			printf("%c ", a[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
char	**make_area(char **a, t_point size)
{
	char	**res;
	int  i, j;
	res = malloc(sizeof(char *) * size.y);
	i = 0;
	while (i < size.y)
	{
		res[i] = malloc(sizeof(char *) * (size.x + 1));
		j = 0;
		while (j < size.x)
		{
			res[i][j] = a[i][j * 2];
			j++;
		}
		i++;
	}
	return (res);
}
// int	main(void)
// {
// 	t_point size = {8, 5};
// 	t_point begin = {0, 0};
// 	char **area;
// 	char *zone[] = {
// 		"1 1 1 1 1 1 1 1",
// 		"1 0 0 0 1 0 0 1",
// 		"1 0 0 1 0 0 0 1",
// 		"1 0 1 1 0 0 0 1",
// 		"1 1 1 0 0 0 0 1",
// 	};
// 	area = make_area((char **)zone, size);
// 	print_tab(area, size);
// 	flood_fill(area, size, begin);
// 	printf("\n");
// 	print_tab(area, size);
// 	return (0);
// }
