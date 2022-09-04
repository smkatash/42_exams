/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:15:37 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/04 18:39:28 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	if (begin_list->next == NULL)
		return (0);
	i = 1;
	list = begin_list;
	while (list)
	{
		if (list->next != NULL)
			i++;
		list = list->next;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list	*list;
// 	int		num;
// 	int		i;

// 	list = malloc(sizeof(t_list));
// 	list->next = malloc(sizeof(t_list));
// 	list->next->next = malloc(sizeof(t_list));
// 	list->next->next->next = malloc(sizeof(t_list));
// 	list->next->next->next->next = NULL;
// 	num = ft_list_size(list);
// 	printf("%d\n", num);
// 	return (0);
// }
