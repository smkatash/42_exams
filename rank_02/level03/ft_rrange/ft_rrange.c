/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:47:07 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 21:57:40 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	i;
	int	*arr;

	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	printf("Len: %d\n", len);
	arr = malloc(sizeof(int) * len);
	i = 0;
	while (end >= start)
		arr[i++] = end--;
	return (arr);
}

// int	main(void)
// {
// 	int	*arr;
// 	int	i;

// 	arr = ft_rrange(-1, 2);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf(" : %d\n", arr[i]);
// 		i++;
// 	}
// 	return (0);
// }
