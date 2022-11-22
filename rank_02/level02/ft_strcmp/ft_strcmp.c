/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:36:22 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:36:41 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[i] || s2[i] == '\0')
             return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

// int main(void)
// {  
//     char a[] = "a";
//     char b[] = "";

//     printf("%d\n", ft_strcmp(a, b));
//     printf("%d\n", strcmp(a, b));
// }