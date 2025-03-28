#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "magicSquare.h"

int isMagicSquare(int square[SIZE][SIZE]) 
{
    int magicSum = 15;
    int num[10] = {0}; // To track numbers 1-9

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            int value = square[i][j];
            if(value < 1 || value > 9 || num[value])
                return 0;
            num[value] = 1;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        int rowSum = 0, colSum = 0;
        for(int j = 0; j < SIZE; j++)
        {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if(rowSum != magicSum || colSum != magicSum)
            return 0;
    }

    int diag1 = square[0][0] + square[1][1] + square [2][2];
    int diag2 = square[0][2] + square[1][1] + square[2][0];
    if(diag1 != magicSum || diag2 != magicSum)
        return 0;

    return 1;
}