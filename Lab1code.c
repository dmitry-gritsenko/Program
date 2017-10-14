/*
Гриценко Дмитрий Андреевич
Лабораторная работа №1 
Вариант №9
Задание: Перевести дециметры в ладони и версты
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	setlocale(0, "Russian");
	float a,b,c;
	int rez = 0;

	printf("Enter the distance in decimeters   ");
	do {
		rez = scanf("%f", &a);
		if (!rez) {
			printf("Error. Incorrect data entered. Try again: ");
			while (getchar() != '\n');
		}
	} while (rez != 1);
    
	b=a / 1.852;
	 printf("\n It %f palms(ladoney)",b);
	c=a / 10668;
 	 printf(" and %f verst \n",c);
	
	system("pause");
	
	return 0;
}
