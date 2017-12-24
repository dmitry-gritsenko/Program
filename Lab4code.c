/*
Гриценко Дмитрий Андреевич
Лабораторная работа №4
Вариант №9
Задание Написать программу, которая во вводимом из файла тексте выберет слова с нечетным количеством букв и выведет их в другой файл. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>  
#include <string.h> 
#include <conio.h>

#define NUM 1024

void Replace(char str[], char a[], char b[], char buffer[]) {
		int pos = 0;
		for (int i = 0; str[i]; i++) {	
			for (int j = 0; str[i + j] && a[j]; j++) {   //начинается ли с i-ой позиции строка a
				if (str[i + j] != a[j]) {
					break;
				}
			}
			if (!a[j]) { //если a[j]=0, то мы дошли до конца строки a
				i += j - 1;  //в j у нас длина стоки a, которую мы перепрыгиваем
				for (j = 0; b[j]; j++) { 
					buffer[pos++] = b[j];
				}//на место стоки a ставим строку b
			}
			else {
				buffer[pos++] = str[i];   //просто копируем символ
			}
			buffer[pos] = NULL;  //ставим конец строки
		}
		strcpy(str, buffer);  //копируем в первоначальную строку
}
int main(void)
	{
	char * OutFileName = "Lab4_output.txt";
	FILE * InputFileName = fopen("Lab4_input.txt", "r");
	int result = 0;
	char str[NUM];
	fgets(str, 1024, InputFileName);
	fclose(InputFileName);
	FILE * file = fopen(OutFileName, "w+");
	char sep[10] = "  ";
	char *istr;
	char buffer[NUM];
	Replace(str, ".", "", buffer);
	Replace(str, ",", "", buffer);
	istr = strtok(str, sep);
	while (istr != NULL)
		{
		if ((strlen(istr) % 2) == 1) 
			{
			result = fprintf(file, "%s\n", istr);
			}
		// Выделение очередной части строки
		istr = strtok(NULL, sep);
		}
	if (!file) 
	printf("Нет доступа к файлу!\n");
 
	fclose(file);
	getch();
	return 0;
	}
