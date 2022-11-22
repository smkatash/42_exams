/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:36:26 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:36:33 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i;
    size_t j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (reject[j] == s[i])
                return (i);
            j++;
        }
        ++i;

    }
    return (i);
}

// int main(void)
// {
//     char s[] = "";
//     char s1[] = "";

//     printf("%zu\n", ft_strcspn(s, s1));
//     printf("%zu\n", strcspn(s, s1));
//     return (0);
// }