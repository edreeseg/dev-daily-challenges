#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    int size = atoi(argv[1]);
    if (argc != 2 || size < 5)
    {
        printf("Usage: ./make-a-spiral.c int\n");
        return 1;
    }
    int result[size][size];
    int x = 0,
        y = 0,
        dir = 1,
        horizontal = 1,
        boundary_x = 0,
        boundary_y = 0,
        turns = 0;
    // Iterate through our result array and set the default to 0,
    // as otherwise we will end up with garbage values polluting the result.
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = 0;
        }
    }
    // Change our x and y location as is appropriate, and check when we 
    // need to turn.
    while (turns < size)
    {
        printf("Coordinates are %i, %i\n", x, y);
        result[y][x] = 1;
        if (y == 0 + boundary_y && !horizontal && dir == -1)
        {
            horizontal = 1;
            dir *= -1;
            turns++;
        }
        else if (y == size - boundary_y - 1 && !horizontal && dir == 1)
        {
            horizontal = 1;
            boundary_y += 2;
            dir *= -1;
            turns++;
        }
        else if (x == size - boundary_x - 1 && horizontal && dir == 1)
        {
            horizontal = 0;
            turns++;
        }
        else if (y != 0 && x == 0 + boundary_x && horizontal && dir == -1)
        {
            horizontal = 0;
            boundary_x += 2;
            turns++;
        }
        // Handle movement
        if (horizontal)
        {
            x += dir;
        }
        else 
        {
            y += dir;
        }
    }
    // Iterate through once more to print the resulting spiral.
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c", result[i][j] ? '0' : '.');
        }
        printf("\n");
    }
    return 0;
}