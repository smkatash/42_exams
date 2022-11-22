/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:47:29 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 21:17:31 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*range(int start, int end)
{
	int	len;
	int	i;
	int	*arr;

	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	arr = malloc(sizeof(int) * len);
	i = 0;
	if (start > end)
	{
		while (start >= end)
			arr[i++] = start--;
	}
	else
	{
		while (start <= end)
			arr[i++] = start++;
	}
	return (arr);
}

// int	main(void)
// {
// 	int	*arr;
// 	int	i;

// 	arr = range(1, -5);
// 	i = 0;
// 	while (i < 8)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// 	return (0);
// }
