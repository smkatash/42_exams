/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:35:32 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:35:35 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int counter(char *s)
{
    int i;
    int capital;

    i = 0;
    capital = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            capital++;
        i++;
    }
    return (capital);
}


int main(int argc, char **argv)
{
    int i;
    int j;
    int len;
    int dashes;
    char *src;
    char *word;

    if (argc == 2)
    {
        src = argv[1];
        len = ft_strlen(src);
        dashes = counter(src);
        word = (char *)malloc(sizeof(char) * (len + dashes + 1));
        i = 0;
        j = 0;
        while(src[i] != '\0' || word[j] != '\0' )
        {
            if (src[i] >= 'A' && src[i] <= 'Z')
            {
                word[j] = '_';
                word[++j] = src[i] + 32;
            }
            else
                word[j] = src[i];
            i++;
            j++;
        }
        word[j] = '\0';
        i = 0;
        while(word[i])
            write(1, &word[i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}