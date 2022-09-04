/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:01:05 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/28 12:06:19 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char rev;
    int i;

    i = 7; 
    while(i >= 0)
    {
        rev = (rev << 1) | (octet & 1);
        octet >>= 1;
        i--;
    }
    return (rev);
}

// unsigned char reverse_bit(unsigned char octet)
// {
// 	unsigned char	r = 0;
// 	unsigned		byte_len = 8;

// 	while (byte_len--) 
//     {
// 		r = (r << 1) | (octet & 1);
// 		octet >>= 1;
// 	}
// 	return r;
// }

// int main(void)
// {
//     int c;
    
//     c = 16;
//     printf("%d", reverse_bits(c));
//     printf("\n");
//     c = 16;
//     printf("%d", reverse_bit(c));
//     return (0);
// }