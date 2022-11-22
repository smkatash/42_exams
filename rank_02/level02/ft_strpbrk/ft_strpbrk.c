/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:36:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:36:56 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;
    char *a;
    char *b;

    a  = (char*)s1;
    b  = (char*)s2;
    i = 0;
    while(a[i])
    {
        j = 0;
        while(b[j])
        {
            if (b[j] == a[i])
                return (&a[i]);
            j++;
        }
        i++;
    }
    return (0);
}

// int main(void)
// {
//     const char s[] = "Hezuiuio";
//     const char s1[] = "abce";
//     char *src;
//     char *ptr;

//     src = ft_strpbrk(s, s1);
//     printf("%c\n", *src);
//     // ptr = strpbrk("Hello", "");
//     // printf("%c\n", *ptr);
//     return (0);
// }