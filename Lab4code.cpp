#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>  
#include <string.h> 
#include <conio.h>
#include <process.h>
#include <iostream>

#define NUM 1024

/*������� ������ ������
������
��� ��������
�� ��� ��������
������
Replace(str, a, b, buffer);*/

void Replace(char str[], char a[], char b[], char buffer[])
	{
		int i, j, pos = 0;
		for (i = 0; str[i]; i++)
		{	
			for (j = 0; str[i + j] && a[j]; j++)   //���������� �� � i-�� ������� ������ a
				if (str[i + j] != a[j]) break;
				if (!a[j])  //���� a[j]=0, �� �� ����� �� ����� ������ a
			{
			i += j - 1;  //� j � ��� ����� ����� a, ������� �� �������������
			for (j = 0; b[j]; j++) buffer[pos++] = b[j];  //�� ����� ����� a ������ ������ b
			}
		else
		{
			buffer[pos++] = str[i];   //������ �������� ������
		}
		buffer[pos] = NULL;  //������ ����� ������
		}
	strcpy(str, buffer);  //�������� � �������������� ������
	}
int main(void)
	{
	//setlocale(0, ""); // �������� ��������� � �������
	char * OutFileName = "Lab4_output.txt";
	FILE * InputFileName = fopen("Lab4_input.txt", "r");
	bool result = 0;
	// ������ �� ������� ��� ������
	char str[NUM];
	//scanf("%s", &str);
	fgets(str, 1024, InputFileName);
	fclose(InputFileName);
	FILE * file = fopen(OutFileName, "w+");
	// ����� ��������, ������� ������ ������� � ������� �������
	char sep[10] = "  ";
	// ����������, � ������� ����� ���������� ��������� ������ ������
	// ������ str
	char *istr;
	char buffer[NUM];
	Replace(str, ".", "", buffer);
	Replace(str, ",", "", buffer);
	//printf("%s", str);
	//printf("Result : \n");
	// ��������� ������ ����� ������
	istr = strtok(str, sep);
	// ��������� ����������� ������
	while (istr != NULL)
	{
		// ����� ��������� ���������� �����
		if ((strlen(istr) % 2) == 1) {
			//printf("%s\n", istr);
			//bool result = fputs(istr'\n', file);
			result = fprintf(file, "%s\n", istr);
		}
		// ��������� ��������� ����� ������
		istr = strtok(NULL, sep);
	}
	//if (!result) // ���� ������ ��������� �������
	//printf("������ � ���� ������� ��������!\n");// ������� ���������
	if (!file) 
	printf("��� ������� � �����!\n");
 
	fclose(file);
	getch();
	return 0;
	}
