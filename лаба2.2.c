#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include <math.h>

void qs(int* mas, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = mas[(left + right) / 2];
		do
		{
			while (mas[left] < middle) left++;
			while (mas[right] > middle) right--;
			if (left <= right)
			{
				int temp = mas[left];
				mas[left] = mas[right];
				mas[right] = temp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(mas, first, right);
		qs(mas, left, last);
	}
}

int main(int argc, char** argv)
{
	int i;
		system("cls");
		setlocale(LC_ALL, "RUS");
		while (1) {
			int x = 0;
			int n = 0, min = 0, max = 0, i = 0, j = 0, temp = 0, sum = 0, maximum = 0, p = 0, tsh = 0;
			int first = 0, last = 0, middle = 0, right = 0, left = 0;
			int* mas;
			int* arr;
			FILE* fo;
			fopen_s(&fo, "C:\\Users\\-\\source\\repos\\лаба2.1\\лаба2.1\\randArr.txt", "r");
			fscanf_s(fo, "%d\n", &n);
			mas = (int*)malloc(n * sizeof(int));
			arr = (int*)malloc(n * sizeof(int));
			printf("Для печати массива выберите: 1\n");
			printf("Выберите тип сортировки: 2)пузырьком\t 3)вставкой\t 4)быстрая\n");
			printf("Выберите вычисление норм вектора: 5)первая норма 6)вторая норма\t 7)бесконечная норма\t8) Гёльдерова норма\n");
			printf("Для очистки консоли выберите: 9\nДля выхода из программы выберите: 10\n");
			scanf_s("%d", &x);
			system("cls");
			for (i = 0; i < n; i++)
			{
				fscanf_s(fo, "%d\n", &arr[i]);
				mas[i] = arr[i];
			}
			clock_t start = clock();
			switch (x)
			{
			case 1:
				for (i = 0; i < n; i++)
				{
					printf("%d\n", mas[i]);
				}
				break;
			case 2:
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n - i - 1; j++)
					{
						if (mas[j] > mas[j + 1])
						{
							temp = mas[j];
							mas[j] = mas[j + 1];
							mas[j + 1] = temp;
						}
					}
				}
				for (i = 0; i < n; i++)
				{
					printf("%d\n", mas[i]);
				}
				clock_t stop = clock();
				double z = (double)(stop - start) / CLOCKS_PER_SEC;
				printf("время выполнения: %lf\n", z);
				free(mas);
				break;
			case 3:
				for (i = 0; i < n; i++)
				{
					temp = mas[i];
					j = i - 1;
					while (j >= 0 && mas[j] > temp)
					{
						mas[j + 1] = mas[j];
						j = j - 1;
					}
					mas[j + 1] = temp;
				}
				for (i = 0; i < n; i++)
				{
					printf("%d\n", mas[i]);
				}
				clock_t end = clock();
				double x = (double)(end - start) / CLOCKS_PER_SEC;
				printf("время выполнения: %lf\n", x);
				free(mas);
				break;
			case 4:
				qs(mas, 0, n - 1);
				for (i = 0; i < n; i++)
				{
					printf("%d\n", mas[i]);
				}
				clock_t konec = clock();
				double c = (double)(konec - start) / CLOCKS_PER_SEC;
				printf("время выполнения: %lf\n", c);
				free(mas);
				break;
			case 5:
				for (i = 0; i < n; i++)
				{
					sum = sum + labs(mas[i]);
				}
				printf("%d\n", sum);
				break;
			case 6:
				for (i = 0; i < n; i++)
				{
					sum = sum + sqrt(pow(mas[i], 2));
				}
				printf("%d\n", sum);
				break;
			case 7:
				for (i = 0; i < n; i++)
				{
					if (labs(mas[i]) > maximum)
					{
						maximum = labs(mas[i]);
					}
				}
				printf("%d\n", maximum);
				break;
			case 8:
				printf("введите степень:");
				scanf_s("%d", &p);
				for (i = 0; i < n; i++)
				{
					temp = pow(mas[i], p);
					tsh = pow(temp, 1.0 / p);
					sum = sum + tsh;
				}
				printf("%d\n", sum);
				break;
			case 9:
				system("cls");
				break;
			case 10:
				exit(0);
			}
			fclose(fo);
		}
		return 0;
	}