/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:23:24 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:23:25 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int c;
    int r;
    char *word;

    word = argv[1];
    c = 0;
    if (argc == 2)
    {
        while (word[c])
        {
            r = 1;
            if (word[c] >= 'a' && word[c] <= 'z')
                r += word[c] - 'a';
            else if (word[c] >= 'A' && word[c] <= 'Z')
                r += word[c] - 'A';
            while (r)
            {
                write(1, &word[c], 1);
                r--;
            }
            c++;
        }
    }
    write(1, "\n", 1);
    return (0);
}