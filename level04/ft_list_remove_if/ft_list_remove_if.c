/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:49:10 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/04 18:21:59 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				num;
}	t_list;

int	cmp(int a, int b)
{
	if (a == b)
		return (0);
	else
		return (-1);
}

// void	ft_list_remove_if(t_list **begin_list, int data_ref, int (*cmp)())
// {
// 	t_list	*prev;
// 	t_list	*temp;

// 	temp = *begin_list;
// 	prev = NULL;
// 	while (temp)
// 	{
// 		if ((*cmp)(temp->num, data_ref) == 0)
// 		{
// 			if (prev == NULL)
// 				*begin_list = temp->next;
// 			else
// 				prev->next = temp->next;
// 			free(temp);
// 		}
// 		prev = temp;
// 		temp = temp->next;
// 	}
// }

void	ft_list_remove_if(t_list **begin_list, int data_ref, int (*cmp)())
{
	t_list	*head;
	t_list	*prev;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	while (*begin_list && cmp((*begin_list)->num, data_ref) == 0)
	{
		head = *begin_list;
		*begin_list = (*begin_list)->next;
		free(head);
	}
	if (*begin_list == NULL)
		return ;
	prev = *begin_list;
	head = prev->next;
	while (head != NULL)
	{
		if (cmp(head->num, data_ref) == 0)
		{
			prev->next = prev->next->next;
			free(head);
			head = prev->next;
		}
		prev = head;
		if (head)
			head = head->next;
	}
}

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*p;

// 	a = malloc(sizeof(t_list));
// 	a->num = 10;
// 	a->next = malloc(sizeof(t_list));
// 	a->next->num = 5;
// 	a->next->next = malloc(sizeof(t_list));
// 	a->next->next->num = 1;
// 	a->next->next->next = malloc(sizeof(t_list));
// 	a->next->next->next->num = 3;
// 	a->next->next->next->next = NULL;
// 	ft_list_remove_if(&a, 1, cmp);
// 	p = a;
// 	while (p)
// 	{
// 		printf("%d\n", p->num);
// 		p = p->next;
// 	}
// 	return (0);
// }
