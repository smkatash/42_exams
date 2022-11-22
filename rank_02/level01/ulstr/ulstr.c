/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:24:43 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:24:45 by kanykei          ###   ########.fr       */
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
        while (str[i])
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            else if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}