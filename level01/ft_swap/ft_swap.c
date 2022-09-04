#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// int main(void)
// {
//     int a;
//     int b;

//     a = 5;
//     b = 2;
//     ft_swap(&a, &b);
//     printf("A: %d and B: %d\n", a, b);
//     return (0);
// }