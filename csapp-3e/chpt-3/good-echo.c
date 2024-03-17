#include <stdio.h>

#define BUFSIZE 64

void good_echo()
{
    char buf[BUFSIZE];
    int i;
    while (1)
    {
        if (!fgets(buf, BUFSIZE, stdin))
        {
            return;
        }
        for (i = 0; buf[i] && buf[i] != '\n'; i++)
        {
            if (putchar(buf[i]) == EOF)
            {
                return;
            }
        }
        if (buf[i] == '\n')
        {
            putchar('\n');
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    good_echo();
    return 0;
}
