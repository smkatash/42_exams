/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:38:05 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:38:07 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int max(int *tab, unsigned int len)
{
    int          max;
    unsigned int i;

    if (len < 1)
        return (0);
    i = 1;
    max = tab[0];
    while (i < len)
    {
        if (max <= tab[i])
            max = tab[i];
        i++;
    }
    return (max);
}

// int max(int *tab, unsigned int len)
// {
//     int max;
//     int i;

//     if (len == 0)
//         return (0);
//     max = 0;
//     while (0 < len)
//     {
//         if (*tab >= max)
//             max = *tab;
//         tab++;
//         len--;
//     }
//     return (max);
// }

int main(void)
{
     int array[] = {-1, -1, -10, 6565600, -200};
    int num;
    
    num = max(array, 5);
    printf("%d\n", num);
    return (0);
}