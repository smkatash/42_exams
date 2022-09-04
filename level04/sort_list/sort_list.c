/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:47:27 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/04 18:43:33 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {
// 	t_list	*temp;
// 	int		temp_int;

// 	temp = lst;
// 	while (lst->next != NULL)
// 	{
// 		if (((*cmp)(lst->data, lst->next->data)) == 0)
// 		{
// 			temp_int = lst->data;
// 			lst->data = lst->next->data;
// 			lst->next->data = temp_int;
// 			lst = temp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = temp;
// 	return (lst);
// }

int	cmp(int a, int b)
{
	if (a > b)
		return (0);
	else
		return (-1);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		temp_int;
	t_list	*temp;

	temp = lst;
	while (temp->next != NULL)
	{
		if (((*cmp)(*(int *)temp->data, *(int *)temp->next->data)) == 0)
		{
			temp_int = *(int *)temp->data;
			*(int *)temp->data = *(int *)temp->next->data;
			*(int *)temp->next->data = temp_int;
			temp = lst;
		}
		else
			temp = temp->next;
	}
	return (lst);
}

// int	main(void)
// {
// 	t_list	a;
// 	t_list	b;
// 	t_list	c;
// 	t_list	*temp1;
// 	int		i;
// 	int		j;
// 	int		k;
// 	t_list	*temp;

// 	i = 10;
// 	j = 3;
// 	k = 1;
// 	a.data = (void *)&i;
// 	a.next = &b;
// 	b.data = (void *)&j;
// 	b.next = &c;
// 	c.data = (void *)&k;
// 	c.next = NULL;
// 	temp1 = &a;
// 	while (temp1)
// 	{
// 		printf("%d, ", *(int *)temp1->data);
// 		temp1 = temp1->next;
// 	}
// 	printf("\n");
// 	temp = sort_list(&a, cmp);
// 	while (temp)
// 	{
// 		printf("%d, ", *(int *)temp->data);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
