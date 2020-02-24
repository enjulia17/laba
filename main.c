#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	int n = 0, i = 0;
	long int* arr;
	FILE* f;

	char line[10];//������, ������� ������ ���� � ����������

	if (argc < 2)
	{
		printf("Error\n");
		return 1;
	}

	srand(time(NULL)); //������������� ��� rand() � ����������� �� �������

	f = fopen(argv[1], "r");//�������� � ������ ������
	ScanFile(f, &n, &arr);//��������� ������ �� �����

	while (1) {
		printf("Enter bubble, insertion, quick or exit: ");//���� ��������� ��� ������������
		scanf("%s", line); //��������� ������� �� �����

		switch (line[0]) {//����� ������ ������ ������  � ���������� ��� � ���������, �������������� � ��������� �����������:
		case 'b'://���� ������ ������ b, �� ����� ��������� ���������� ���������
			bubblesort(arr, n); //��������� ����������
      Print (n, arr);
			free(arr); //���������� ������
			ScanFile(f, &n, &arr); //��������� � ��������� ������
			break;
		case 'i'://���� ������ ������ i, �� ����� ��������� ���������� ���������
			insertionsort(arr, n);
      Print(n, arr);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'q'://���� ������ ������ q, �� ����� ��������� ������� ����������
			quicksort(arr, 0, n - 1);
      Print(n, arr);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'e'://���� ������ ������ e, �� ����� �������� ����� �� ���������
			printf("Exit");
			fclose(f);
			free(arr);
			return 0;
		default: //���� ������� ������ �������, �� �������� �� ����� �������
			printf("Not found\n");
		}
	}
}