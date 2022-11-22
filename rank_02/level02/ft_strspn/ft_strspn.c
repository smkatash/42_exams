/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:37:19 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:37:21 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    char *s1;
    char *s2;
    size_t i;
    size_t j;
    size_t match;

    s1 = (char *)s;
    s2 = (char *)accept;
    i = 0;
    j = 0;
    match = 0;
    while(s2[i])
    {
        while (s1[j] == s2[i])
        {
            match++;
            j++;
            i++;
        }
        return (match);
        i++;
    }
    return (match);
}


// int main(void)
// {
//     char s[] = "iam";
//     char charset[] = "iuh";

//     printf("My: %lu\n", ft_strspn(s, charset));
//     printf("%lu\n", strspn(s, charset));
//     printf("%lu\n", strcspn(s, charset));
// }