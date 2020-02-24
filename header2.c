#include "header2.h"
#include <stdlib.h>
#include <time.h>

#pragma warning(disable : 4996)

#define SWAP(A, B) { A = A + B; B = A - B; A = A - B; } //SWAP - это макрос, который присваивает переменным значени€ друг друга


void Print(int size, long int* m) //объ€вление и инициализаци€ массива
{
	int i = 0;
  char l[20];
  printf("Print?\n");
  scanf("%s", l);
  if (l[0] == 'y')
  {
    printf("N = %d\n", size);
    for (i = 0; i < size; i++)
      printf("m[%d] = %d\n", i, m[i]);
  }
}

void ScanFile(FILE* f, int* size, long int** m) //читаем из файла размер и сам массив
{
	int i = 0, j = 0;
	//rewind(f); //перематываем файл в начало
	fscanf(f, "%d\n", size);
	*m = (long int*)malloc(*size * sizeof(long int)); //выдел€ем пам€ть под массив
	for (i = 0; i < *size; i++)
		fscanf(f, "m[%d] = %d\n", &j, &((*m)[i]));
}

void insertionsort(long int* arr, int n){ //сортировка вставками

	int i, key, j; // key - параметр, который будет вызыватьс€ дл€ преобразовани€ элементов массива до их сравнени€, j - "мусорна€" переменна€, предыдущий номер элемента, нужный дл€ того чтобы перейти к следующему 

	clock_t start, stop; // дл€ того чтобы считать врем€ программы

	start = clock(); //фиксируем начало подсчЄта внутреннего времени работы программы

	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

	stop = clock(); //фиксируем окончание подсчЄта времени работы программы

	printf("Sort required %.3lf seconds\n", (double)(stop - start) / CLK_TCK);//переводим тики в секунды и выводим с 3 знаками после зап€той
}

void quicksort(long int* arr, int first, int last) //быстра€ сортировка
{
	clock_t start, stop;

	start = clock();

	qs(arr, first, last); //создаЄм отдельную функцию, qs содержит рекурсию

	stop = clock();

	printf("Sort required %.3lf seconds\n", (double)(stop - start) / CLK_TCK);
}

void qs(long int* s_arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2];
		do
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				long int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}

void bubblesort(long int* a, int n) //сортировка пузырьком
{
	int j, nn;

	clock_t start, stop;

	start = clock();

	do {
		nn = 0;
		for (j = 1; j < n; ++j)
			if (a[j - 1] > a[j]) {
				SWAP(a[j - 1], a[j]);
				nn = j;
			}
		n = nn;
	} while (n);

	stop = clock();

	printf("Sort required %.3lf seconds\n", (double)(stop - start) / CLK_TCK);
}