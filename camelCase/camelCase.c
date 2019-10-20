#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: ./camelCase \"argument\"\n");
        return 1;
    }
    char *c = argv[1];
    char result[strlen(argv[1])]; // Will end up taking up more space than necessary - come back and fix
    int wordStart = 0, counter = 0;
    while(*c != '\0')
    {
        if (*c == ' ')
        {
            wordStart = 1;
            c++;
        }
        else if (wordStart)
        {
            wordStart = 0;
            result[counter++] = toupper(*c);
            c++;
        }
        else
        {
            wordStart = 0;
            result[counter++] = tolower(*c);
            c++;
        }
    }
    result[counter] = '\0';
    printf("%s\n", result);
    return 0;
}