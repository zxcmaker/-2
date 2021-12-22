#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	while (1)
	{
		int max = 0, min = 0, n = 0, i = 0, err = 0, x = 0;
		float temp = 0, maxRand = RAND_MAX;
		int* randArr;
		int* mas;
		int* arr;
		FILE* arrFile;
		FILE* fo;
		fopen_s(&fo, "C:\\Users\\-\\source\\repos\\лаба2.1\\лаба2.1\\zxc.txt", "r");
		fscanf_s(fo, "%d\n", &n);
		mas = (int*)malloc(n * sizeof(int));
		arr = (int*)malloc(n * sizeof(int));
		printf("Выберите вид создания файла:\n 1)случайная генерация\n 2)ввод с клавиатуры\n 3)чтение из файла\n\n 4)очистка консоли\n 5)выход из программы\n");
		scanf_s("%d", &x);
		for (i = 0; i < n; i++)
		{
			fscanf_s(fo, "%d\n", &arr[i]);
			mas[i] = arr[i];
		}
		switch (x)
		{
		case 1:
			err = fopen_s(&arrFile, "randArr.txt", "w");
			if (err) {
				printf("file read/create error...");
				return 1;
			}
			srand(time(NULL));
			do {
				printf("enter the number of numbers\t");
				scanf_s("%d", &n);
				printf("enter maximum number\t");
				scanf_s("%d", &max);
				printf("enter minimum number\t");
				scanf_s("%d", &min);
				if (max < min) {
					system("cls");
					printf("Error: maximum less than minimum\n");
				}
			} while (max < min);
			fprintf(arrFile, "%d\n", n);
			system("cls");
			randArr = (int*)malloc(n * sizeof(int));
			for (i = 0; i < n; i++) {
				temp = rand();
				randArr[i] = min + (int)((temp / maxRand) * (float)(max - min));
				fprintf(arrFile, "%d\n", randArr[i]);
				printf("%d\n", randArr[i]);
			}
			break;
		case 2:
			err = fopen_s(&arrFile, "randArr.txt", "w");
			if (err) {
				printf("file read/create error...");
				return 1;
			}
			printf("enter the number of numbers\t");
			scanf_s("%d", &n);
			fprintf(arrFile, "%d\n", n);
			system("cls");
			randArr = (int*)malloc(n * sizeof(int));
			for (i = 0; i < n; i++)
			{
				scanf_s("%d", &randArr[i]);
			}
			system("cls");
			for (i = 0; i < n; i++)
			{
				fprintf(arrFile, "%d\n", randArr[i]);
				printf("%d\n", randArr[i]);
			}
			break;
		case 3:
			err = fopen_s(&arrFile, "randArr.txt", "w");
			if (err) {
				printf("file read/create error...");
				return 1;
			}
			fprintf(arrFile, "%d\n", n);
			system("cls");
			randArr = (int*)malloc(n * sizeof(int));
			for (i = 0; i < n; i++)
			{
				randArr[i] = mas[i];
			}
			for (i = 0; i < n; i++)
			{
				fprintf(arrFile, "%d\n", randArr[i]);
				printf("%d\n", randArr[i]);
			}
				break;
		case 4:
			system("cls");
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}