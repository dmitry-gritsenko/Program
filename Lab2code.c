/*
Гриценко Дмитрий Андреевич
Лабораторная работа №2
Вариант №9
Задание Написать программу, которая выводит на экран только простые числа. 
Массив и его длина вводятся пользователем.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_LENGTH 100
#define MIN_LENGTH 3

int main()
{
	int i;
    int j;
    bool are_simple=0;
	int array[MAX_LENGTH];
	int length;
	int check;
	printf("Enter the length of the array: ");
	while (!scanf("%d", &length) || (length > MAX_LENGTH) || (length < MIN_LENGTH))
	{ 
		printf("Input error. The array length cannot be less than 3 and more than 100, and should not be letters. \n Try to enter: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
	for (check = 0; check < length; check++)
	{
		printf("Enter the value array[%d]:", check);
		while (!scanf("%d", &array[check]))
		{
			printf("Input error. \n Try to enter: array[%d]: ", check);
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
	for (i = 0; i < array[MAX_LENGTH]; i++) { 
	if ((array[i]) <= 3 && (array[i]) > 1) { 
	printf("%d\n", array[i]);
	are_simple=1;
	}
	   else { 
	    for (j = 2; j < (array[i]); j++) { 
	     if (array[i] % j == 0) {
	     break;
		 }    
	     if (j == (array[i]) - 1) { 
	     printf("%d\n", array[i]);
	     are_simple=1; } 
        } 
	   } 
	}
	if (are_simple==0) {
	printf("No prime numbers."); }
	_getch();
	return 0;
} 
