#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "magicSquare.h"

int main()
{
    int validSquare[SIZE][SIZE] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };

    int invalidSquare[SIZE][SIZE] = {
        {8, 1, 5},
        {3, 5, 7},
        {4, 9, 3}
    };

    printf("Valid Square: %s\n", isMagicSquare(validSquare) ? "True" : "False");
    printf("Invalid Square: %s\n", isMagicSquare(invalidSquare) ? "True" : "False");

    return 0;
}