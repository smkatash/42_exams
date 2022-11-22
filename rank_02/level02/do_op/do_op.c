#include "do_op.h"

int main(int argc, char **argv)
{
    int first;
    int second;
    int sign;
    int result;

    if (argc == 4)
    {
        first = atoi(argv[1]);
        second = atoi(argv[3]);
        sign = *argv[2];
        if (sign == '*')
            result = first * second;
        else if (sign == '/')
            result = first / second;
        else if (sign == '+')
            result = first + second;
        else if (sign == '-')
            result = first + second;
        else if (sign == '%')
            result = first % second;
        printf("%d\n", result);
    }
    else
        write(1, "\n", 1);
    return (0);
}
