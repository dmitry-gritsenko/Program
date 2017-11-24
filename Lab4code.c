#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	FILE * ptrFile = fopen("Text for lab.txt", "r");
	// Массив со строкой для поиска
	char str[1024];
	//scanf("%s", &str);
	fgets(str, 1024, ptrFile);
	// Набор символов, которые должны входить в искомый сегмент
	char sep[10] = "  ";
	// Переменная, в которую будут заноситься начальные адреса частей
	// строки str
	char *istr;
	printf("Your text: %s\n", str);
	printf("Result: \n");
	// Выделение первой части строки
	istr = strtok(str, sep);
	// Выделение последующих частей
	while (istr != NULL)
	{
		// Вывод очередной выделенной части
		if ((strlen(istr) % 2) == 1) {
			printf("%s\n", istr);
		}
		// Выделение очередной части строки
		istr = strtok(NULL, sep);
	}
	getch();
	return 0;
}
