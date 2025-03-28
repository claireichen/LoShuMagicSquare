#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#define SIZE 3

int isMagicSquare(int square[SIZE][SIZE]);
void shuffle(int *arr, int size);
void fillSquare(int square[SIZE][SIZE], int *flat);
void printSquare(int square[SIZE][SIZE]);

#endif