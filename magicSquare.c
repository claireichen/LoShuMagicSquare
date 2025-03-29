#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "magicSquare.h"

int isMagicSquare(int square[SIZE][SIZE]) 
{
    int magicSum = 15;
    int num[10] = {0}; // To track numbers 1-9

    printf("=== Checking square in isMagicSquare ===\n");
    printSquare(square);

    //check if all numbers from 1 to 9 are present
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            int value = square[i][j];
            if(value < 1 || value > 9)
                return 0;
            if(num[value])
                return 0;
            num[value] = 1;
        }
    }

    //check rows and columns sums equals magic sum
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

    //check diagonals sums equals magic sum
    int diag1 = square[0][0] + square[1][1] + square [2][2];
    int diag2 = square[0][2] + square[1][1] + square[2][0];
    if(diag1 != magicSum || diag2 != magicSum)
        return 0;

    return 1;
}

void shuffle(int *arr, int size)
{
    for(int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
    }
}

void fillSquare(int square[SIZE][SIZE], int *flat)
{
    for(int i = 0; i < SIZE * SIZE; i++)
        square[i / SIZE][i % SIZE] = flat[i];
}

void printSquare(int square[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("[");
        for(int j = 0; j < SIZE; j++)
            printf("%d%c", square[i][j], (j < SIZE - 1) ? ' ' : ']');
        printf("\n");
    }
}