#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "magicSquare.h"

int main()
{
    //random square
    srand(time(NULL));
    int square[SIZE][SIZE];
    int flat[9], count = 0;

    for(int i = 0; i < 9; i++) 
    {
        flat[i] = i + 1;
    }

    do
    {
        shuffle(flat, 9);
        fillSquare(square, flat);
        count++;
    }while (!isMagicSquare(square));

    printf("Found a magic square after %d attempts:\n", count);
    printSquare(square);

    //test cases
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