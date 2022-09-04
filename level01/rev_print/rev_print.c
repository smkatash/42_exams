/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:23:08 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:23:09 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char *str;

    i = 0;
    str = argv[1];
    if (argc == 2)
    {
        while(str[i] != '\0')
            i++;
        i -= 1;
        while(i > -1)
        {
            write(1, &str[i], 1);
            i--;
        }
    }  
    write(1, "\n", 1);
    return (0);
}