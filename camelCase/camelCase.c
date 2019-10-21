#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./camelCase \"argument\"\n");
        return 1;
    }
    char *c = argv[1];
    int len = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] != ' ')
        {
            len++;
        }
    }
    char result[len + 1];
    int wordStart = 0, counter = 0;
    while(*c != '\0')
    {
        if (*c == ' ')
        {
            wordStart = 1;
        }
        else if (wordStart)
        {
            wordStart = 0;
            result[counter++] = toupper(*c);
        }
        else
        {
            wordStart = 0;
            result[counter++] = tolower(*c);
        }
        c++;
    }
    result[counter] = '\0';
    printf("%s\n", result);
    return 0;
}