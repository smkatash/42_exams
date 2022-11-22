#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

// int main(void)
// {
//     int len;

//     len = ft_strlen("hello42bye42");
//     printf("%d\n", len);
//     return (0);
// }