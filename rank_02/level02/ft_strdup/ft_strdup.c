#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strdup(char *src)
{
    int i;
    char *s1;

    i = 0;
    if (src == NULL)
        return (NULL);
    while (src[i])
        i++;
    s1 = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i])
    {
        s1[i] = src[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

// int main(void)
// {
//     char str[] = "Hello";
//     char src[] = "Hello";
//     char *ptr;

//     ptr = ft_strdup(str);
//     printf("%s\n", ptr);
//     printf("%lu\n", sizeof(str));
//     ptr = strdup(src);
//     printf("%s\n", ptr);
//     printf("%lu\n", sizeof(src));
//     return(0);
// }