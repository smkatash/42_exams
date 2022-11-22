/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:37:27 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:37:28 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int    self_loop(char *str, char c, int pos)
{
    int i;

    i = 0;
    while (i < pos)
    {
        if (str[i] == c)
            return(0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    char *first;
    char *second;

    if (argc == 3)
    {
        i = 0;
        j = 0;
        first = argv[1];
        second = argv[2];
        while (first[i])
        {
            j = 0;
            while(second[j])
            {
                if (second[j] == first[i])
                {
                    if (self_loop(first, first[i], i) == 1)
                    {
                        write(1, &first[i], 1);
                        break;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

