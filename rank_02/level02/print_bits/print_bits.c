/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:38:12 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:38:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    print_bits(unsigned char octet)
{
    int             i;
    unsigned char bit;

    i = 7;
    while (i >= 0)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
		printf("\n");
        i--;
    }
}


// int main(void)
// {
//     int c;

//     c = 2;
//     print_bits(c);
//     // c = -2;
//     // print_bits(c);
//     return (0);
// }
