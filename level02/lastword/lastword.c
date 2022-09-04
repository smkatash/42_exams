/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastword.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:37:52 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:37:55 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *find_last(char *str, int len)
{
    char *s;

    s = &str[len];
    while (*s == ' ' && *s != '\0')
        s--;
    while (*s != ' ' && *s != '\0')
        s--;
    s++;
    if (*s == ' ')
        s = NULL;
    return (s);
}

int main(int argc, char **argv)
{
    char *s;
    int i;
    int len;

    if (argc == 2)
    {
        i = 0;
        len = ft_strlen(argv[1]) - 1;
        s = find_last(argv[1],len);
        if (s != NULL)
        {
            while (s[i] != '\0' && s[i] != ' ')
            {
                write(1, &s[i], 1);
                i++;
            }                  
        }
    }
    write(1, "\n", 1);
    return (0);
}