#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	FILE * ptrFile = fopen("Text for lab.txt", "r");
	// ������ �� ������� ��� ������
	char str[1024];
	//scanf("%s", &str);
	fgets(str, 1024, ptrFile);
	// ����� ��������, ������� ������ ������� � ������� �������
	char sep[10] = "  ";
	// ����������, � ������� ����� ���������� ��������� ������ ������
	// ������ str
	char *istr;
	printf("Your text: %s\n", str);
	printf("Result: \n");
	// ��������� ������ ����� ������
	istr = strtok(str, sep);
	// ��������� ����������� ������
	while (istr != NULL)
	{
		// ����� ��������� ���������� �����
		if ((strlen(istr) % 2) == 1) {
			printf("%s\n", istr);
		}
		// ��������� ��������� ����� ������
		istr = strtok(NULL, sep);
	}
	getch();
	return 0;
}
