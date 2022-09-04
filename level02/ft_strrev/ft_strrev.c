/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:37:11 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 18:37:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char    *ft_strrev(char *str)
{
    int i;
    int j;
    char temp;

    i = 0;
    j = 0;
    while (str[i])
        i++;
    --i;
    while(str[j] && j < i)
    {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j++;
        i--;
    }
    return (str);
}

// int main(void)
// {
//     char src[] = "Hello world!  !";
//     char *ptr;
//     char *str;

//     ptr = ft_strrev(src);
//     printf("%s\n", ptr);
//     // str = strrev(src);
//     // printf("%s\n", str);
//     return(0);
// }