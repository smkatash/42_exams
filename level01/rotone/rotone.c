/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:24:09 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:24:10 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int     i;
    char    *str;
    int     letter;

    i = 0;
    str = argv[1];
    if (argc == 2)
    {
        while (str[i] != '\0')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                if (str[i] == 'z')
                    letter = str[i] - 25;
                else 
                    letter = str[i] + 1;                
            }
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                if (str[i] == 'Z')
                    letter = str[i] - 25;
                else 
                    letter = str[i] + 1;               
            }
            else
                letter = str[i];
            write(1, &letter, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
