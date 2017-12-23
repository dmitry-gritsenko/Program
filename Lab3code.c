/*
Гриценко Дмитрий Андреевич
Лабораторная работа №3
Вариант №9
Задание Написать программу, которая во вводимом с клавиатуры тексте выберет слова с нечетным количеством букв и выведет их на экран. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define NUM 1024

int main()
{
	// Массив со строкой для поиска
	char line[NUM];
	//scanf("%s", &str);
	printf("The maximum text length of 10,000 characters.\n");
	printf("Enter your text: ");
	fgets(line, NUM, stdin);
	// Набор символов, которые должны входить в искомый сегмент
	char sep[] = "  ";
	// Переменная, в которую будут заноситься начальные адреса частей
	// строки str
	char *istr;
	printf("Words with an odd number of letters: \n");
	// Выделение первой части строки
	istr = strtok(line, sep);
	// Выделение последующих частей
	while (istr != NULL)
	{
		// Вывод очередной выделенной части
		if ((strlen(istr) % 2) == 1) 
			{
			printf("%s\n", istr);
			}
		// Выделение очередной части строки
		istr = strtok(NULL, sep);
	}
	getch();
	return 0;
}
