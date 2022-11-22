/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:37:38 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:37:47 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int	    is_power_of_2(unsigned int n)
// {
//     int i;

//     i = 1;
//     while (i <= n)
//     {
//         if (i == n)
//             return (1);
//         i *= 2;
//     }
//     return (0);
// }

int	    is_power_of_2(unsigned int n)
{
    if (n > 0 && (n & (n - 1)) == 0)
        return (1);
    return (0);
}


// int	    is_power_of_2(unsigned int n)
// {
//     while (n != 1)
//     {
//         if (n % 2)
//             return (1);
//         n = n / 2;
//     }
//     return (0);
// }

// int main(void)
// {

//     if (is_power_of_2(1))
//         printf("Yes\n");
    
//     if (is_power_of_2(3))
//         printf("Yes\n");
//     else
//         printf("No\n");
// }