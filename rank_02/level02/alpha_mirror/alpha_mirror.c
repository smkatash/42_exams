#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char *s;
    int letter;
    const char alpha[] = "zyxwvutsrqponmlkjihgfedcba";

    i = 0;
    s = argv[1];
    if (argc == 2)
    {
        while (s[i])
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                letter = alpha[s[i] - 'a'];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                letter = alpha[s[i] - 'A'] - 32;
            else
                letter = s[i];
            write(1, &letter, 1);
            i++;

        }
    }
    write(1, "\n", 1);
    return (0);
}