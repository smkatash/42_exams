/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:38:34 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:38:38 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
    unsigned char r;
    unsigned char l;
    unsigned final;

    r = octet >> 4;
    l = octet << 4;
    final = r | l;
    return (final);
}