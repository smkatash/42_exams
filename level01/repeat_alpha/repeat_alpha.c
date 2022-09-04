/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:23:19 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:23:20 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    loop(char c)
{
    char upper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char low[26] = "abcdefghijklmnopqrstuvwxyz";
    int i;

    i = 1;
    while (i <= 26)
    {
        if (upper[i] == c || low[i] == c)
            return (i);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    char *word;
    int i;
    int count;

    if (argc == 2)
    {
        word = argv[1];
        i = 0;
        count = 0;
        while (word[i] != '\0')
        {
            count = loop(word[i]);
            while(count >= 0)
            {
                write(1, &word[i], 1);
                count--;
            }
        i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}