/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:36:16 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:36:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    int num;
    int neg;
    
    i = 0;
    num = 0;
    neg = 1;
    while (str[i])
    {
        if (str[i] == '-')
        {
            neg = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;
        num = num * 10 + (str[i] - '0');
        i++;
    }
    num *= neg;
    return (num);
}

// int main(void)
// {
//     char s[] = "-100000000000000";

//     printf("%d\n", ft_atoi(s));
//     printf("%d\n", atoi(s));
//     return(0);
// }