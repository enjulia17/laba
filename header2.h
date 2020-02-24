#ifndef _HEADER2_H_ //объ€вление всех функций программы
#define _HEADER2_H_
#include <stdio.h>

void Print(int size, long int* m);
void ScanFile(FILE* f, int* size, long int** m);
void insertionsort(long int* arr, int n);
void quicksort(long int* arr, int first, int last);
void qs(long int* s_arr, int first, int last);
void bubblesort(long int* a, int n);

#endif