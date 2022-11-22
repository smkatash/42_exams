/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:24:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:24:32 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char *s;
    char first;
    char second;
    int fir;
    int sec;

    fir = 0;
    sec = 0;
    s = argv[1];
    first = *argv[2];
    second = *argv[3];
    while(argv[2][fir])
        fir++;
    while(argv[2][sec])
        sec++;
    if (fir > 1 || sec > 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    if (argc == 4)
    {
        while (s[i] != '\0')
        {
            if (s[i] == first)
                s[i] = second;
            write(1, &s[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}