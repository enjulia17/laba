#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	int n = 0, i = 0;
	long int* arr;
	FILE* f;

	char line[10];//массив, который хранит ввод с клавиатуры

	if (argc < 2)
	{
		printf("Error\n");
		return 1;
	}

	srand(time(NULL)); //инициализация для rand() в зависимости от времени

	f = fopen(argv[1], "r");//открытие в режиме чтения
	ScanFile(f, &n, &arr);//считываем данные из файла

	while (1) {
		printf("Enter bubble, insertion, quick or exit: ");//меню программы для пользователя
		scanf("%s", line); //считываем строчку до конца

		switch (line[0]) {//берем первый символ строки  и сравниваем его с символами, расположенными в следующих контейнерах:
		case 'b'://если введен символ b, то будет выполнена сортировка пузырьком
			bubblesort(arr, n); //выполнили сортировку
      Print (n, arr);
			free(arr); //освободили память
			ScanFile(f, &n, &arr); //прочитали и заполнили массив
			break;
		case 'i'://если введен символ i, то будет выполнена сортировка вставками
			insertionsort(arr, n);
      Print(n, arr);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'q'://если введен символ q, то будет выполнена быстрая сортировка
			quicksort(arr, 0, n - 1);
      Print(n, arr);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'e'://если введен символ e, то будет выполнен выход из программы
			printf("Exit");
			fclose(f);
			free(arr);
			return 0;
		default: //если введены другие символы, то элементы не будут найдены
			printf("Not found\n");
		}
	}
}