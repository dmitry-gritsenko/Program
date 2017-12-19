/*
�������� ������� ���������
������������ ������ �5
������� 9
�������: �������� ���������, ������� ���������� � ���������� � ���� ���������
�������� ��������� �������� �������. � �������� ����������� ����� ���������
������������ ������ ���������. � ��������� �����������:
�) ���������� ������������� ������� �������� ������ �����������;
�) ����� ��������� � �������� ��������� ���������� ��������;
�) ����� �� ����� ����������� ������� ��������;
�) ������������ ������� �������� �� ��������� ���� (��������), ��������
����������� �� �����������.
������� �������: ��������� �����������: ���, ����� ����������, ����� �����������, ����
��������, �������, ��������� ����������� �����.
*/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <locale>

/*��������� �����*/
#define	MAX_LENGTH_NAME									50
#define	MAX_LENGTH_NUMBER_CUR							20
#define	MAX_LENGTH_NUMBER_TECHNICALCERTIFICATION		40
#define LENGTH_DATE										12
#define	MAX_LENGTH_PHONE								20
#define	MAX_LENGTH_OFFICEGIBDD							60

/*���� � ����� ��� ������*/
#define WAY_FILE						"StructFile.txt"

struct car {
	char	name[MAX_LENGTH_NAME];
	char	NumberCur[MAX_LENGTH_NUMBER_CUR];
	char	NumberTechnicalCertificate[MAX_LENGTH_NUMBER_TECHNICALCERTIFICATION];
	char	date[LENGTH_DATE];
	char	phone[MAX_LENGTH_PHONE];
	char	OfficeGIBDD[MAX_LENGTH_OFFICEGIBDD];
};

/*���*/
void main() {
	setlocale(0, "rus");
	int request = 0;
	printf("�������� ��� �������:\n");
	EnterRequest();
}

/*�������*/

/*�����*/
void EntryFile(FILE *file, struct car Auto);
void EnterNumberOrSymbol(char *word, int max_length);
void RepeatRequest(int exist_file);
void ChoiceFunction(int request);
void EnterOfficeGIBDD(char *word);
void EnterPhone(char *word);
void EnterName(char *word);
void EnterDate(char *word);
void FormStructText();
void EnterRequest();
void FormRequest();
void FormStruct();

int StringLength(char *StringText);
int PositionTub(char *word);
int �hoiceRequest(int max);

/*1 ������*/
void EnterWord(char *word, int max_length, int *length);
void EnterStruct(struct car *Auto);
void EnterStructs();

int EnterCountStructs();

/*2 ������*/
void PassingFile(int request, char *search_text);
void StringCopy(char *new_text, char *text);
void SearchText();

int SearchPunct(char *text_file, int request, char *search_text);

/*3 ������*/
void OutputStruct();

/*4 ������*/
void SwapStructs(struct car &Auto1, struct car &Auto2);
void AddStruct(struct car *Auto, char *text);
void ClearStruct(struct car *Auto);
void AddStructs(FILE *StructFile);
void SortingFile();

int StringLength(char *StringText) {
	int i;
	for (i = 0; StringText[i]; i++);
	return i;
}

void FormRequest() {
	printf("1)�������� ��������� � ����\n");
	printf("2)����� ��������� � �����\n");
	printf("3)����� ������� �� �����\n");
	printf("4)���������� ������ � �����\n");
	printf("5)���������� ������ ���������\n");
}

int �hoiceRequest(int max) {
	int	request = 0;
	bool	error = true;

	do {
		scanf("%d", &request);

		if (getchar() != '\n') {
			printf("������ �����. ��������� �������: ");
			while (getchar() != '\n');
		}
		else (request < 1 || request > max) ? printf("������. ������ ������ �����������. ��������� �������: ") : error = false;

	} while (error);

	return request;
}

void ChoiceFunction(int request) {
	switch (request) {
	case 1:
		EnterStructs();
		break;
	case 2:
		SearchText();
		break;
	case 3:
		OutputStruct();
		break;
	case 4:
		SortingFile();
		break;
	default:
		exit(0);
	}
}

void EnterStructs() {
	int count = 0;

	printf("������� ���������� ��������: ");
	count = EnterCountStructs();

	struct car *Auto = (struct car *)malloc(sizeof(struct car *) * count);

	FormStruct();

	FILE *StructFile = fopen(WAY_FILE, "a");
	if (StructFile == NULL) {
		fclose(StructFile);
		StructFile = fopen(WAY_FILE, "w");
	}

	for (int i = 0; i < count; i++) {
		printf("���� %d ���������:\n", i + 1);
		EnterStruct(&Auto[i]);
		EntryFile(StructFile, Auto[i]);
	}
	fclose(StructFile);
}

void RepeatRequest(int exist_file) {
	exist_file ? printf("����� ��� ������?(1-��; 2-���)\n") : printf("���� �� ������. ����� ������������� ������ �������?(1-��; 2-���)\n");
	printf("����: ");
	int request = �hoiceRequest(2);
	request == 1 ? EnterRequest() : "";
}

void EnterRequest() {
	FormRequest();
	printf("����: ");
	int request = �hoiceRequest(5);
	ChoiceFunction(request);
	RepeatRequest(1);
}

void EntryFile(FILE *file, struct car Auto) {
	fprintf(file, "%s\t", Auto.name);
	fprintf(file, "%s\t", Auto.NumberCur);
	fprintf(file, "%s\t", Auto.NumberTechnicalCertificate);
	fprintf(file, "%s\t", Auto.date);
	fprintf(file, "%s\t", Auto.phone);
	fprintf(file, "%s\n\0", Auto.OfficeGIBDD);
	fclose(file);
}

int EnterCountStructs() {
	int	count = 0;
	bool	error = true;

	do {
		scanf("%d", &count);

		if (getchar() != '\n') {
			printf("������ �����. ��������� �������: ");
			while (getchar() != '\n');
		}
		else (count < 1) ? printf("������. ���������� ��������� ������������. ��������� �������: ") : error = false;

	} while (error);

	return count;
}

void FormStruct() {
	printf("������� ��������� � �����:\n");
	FormStructText();
}

void FormStructText() {
	printf("\t1)���(��� ���������)\n");
	printf("\t2)����� ����������\n");
	printf("\t3)����� �����������\n");
	printf("\t4)���� ��������(� ���� ��:��:����)\n");
	printf("\t5)�������\n");
	printf("\t6)��������� ����������� �����\n");
}

void EnterStruct(struct car *Auto) {
	printf("\t������� ���: ");
	EnterName(Auto->name);

	printf("\t������� ����� ����������: ");
	EnterNumberOrSymbol(Auto->NumberCur, MAX_LENGTH_NUMBER_CUR);

	printf("\t������� ����� �����������: ");
	EnterNumberOrSymbol(Auto->NumberTechnicalCertificate, MAX_LENGTH_NUMBER_TECHNICALCERTIFICATION);

	printf("\t������� ���� ��������: ");
	EnterDate(Auto->date);

	printf("\t������� ����� ��������: ");
	EnterPhone(Auto->phone);

	printf("\t������� ��������� ����������� �����: ");
	EnterOfficeGIBDD(Auto->OfficeGIBDD);
}

void EnterName(char *word) {
	int length = 0;
	EnterWord(word, MAX_LENGTH_NAME, &length);

	for (int i = 0; i < length; i++) {
		if (!(CHECK_NAME)) {
			printf("\t������ ����� �����. ��������� �������: ");
			EnterName(word);
			break;
		}
	}
}

void EnterNumberOrSymbol(char *word, int max_length) {
	int length = 0;
	EnterWord(word, max_length, &length);

	for (int i = 0; i < length; i++) {
		if (!(CODE_NUMBER_OR_SYMBOL)) {
			printf("\t������ �����. ��������� �������: ");
			EnterNumberOrSymbol(word, max_length);
			break;
		}
	}
}

void EnterDate(char *word) {
	int length = 0;
	EnterWord(word, LENGTH_DATE, &length);

	if (!(CHECK_CODE_DATE)) {
		printf("\t������ ����� ����. ��������� �������: ");
		EnterDate(word);
	}
}

void EnterPhone(char *word) {
	int	length = 0,
		brace_left = 0,
		brace_right = 0;

	EnterWord(word, MAX_LENGTH_PHONE, &length);
	if (!(word[0] == '+' || ((int)word[0] >= 48 && (int)word[0] <= 57))) {
		printf("\t������ ����� ������ ��������. ��������� �������: ");
		EnterPhone(word);
	}
	for (int i = 1; i < length; i++) {
		if (word[i] == '(') brace_left++;
		else if (word[i] == ')')brace_right++;
		else if (!(CODE_NUMBER_SYMBOL || word[i] == '(' || word[i] == ')' || word[i] == ' ' || FINISH_SYMBOL) ||
			(word[i] == ')' && brace_left == 0)) {
			printf("\t������ ����� ������ ��������. ��������� �������: ");
			EnterPhone(word);
			break;
		}

		if (brace_left > 1 || brace_right > 1) {
			printf("\t������ ����� ������ ��������. ��������� �������: ");
			EnterPhone(word);
			break;
		}
	}
}

void EnterOfficeGIBDD(char *word) {
	int length = 0;
	EnterWord(word, MAX_LENGTH_OFFICEGIBDD, &length);

	for (int i = 0; i < length; i++) {
		if (!(CHECK_OFFICE_GIBDD)) {
			printf("\t������ ����� ��������� ����������� �����. ��������� �������: ");
			EnterOfficeGIBDD(word);
			break;
		}
	}
}

void EnterWord(char *word, int max_length, int *length) {
	for (int i = 0; i < max_length; i++)
		word[i] = '\0';

	fgets(word, max_length, stdin);

	*length = StringLength(word);

	word[*length - 1] = '\0';

}

/*2 ������*/
void SearchText() {
	printf("����� ��������� ��������� � ���� ����� �������?(1-�� 2-���)\n");
	printf("����: ");
	int request = �hoiceRequest(2);
	if (request == 1)
		EnterStructs();
	printf("�������� �������� ������:\n");
	FormStructText();
	printf("����: ");

	request = �hoiceRequest(6);

	printf("������� ����� ��� ������: ");
	char search_text[MAX_LENGTH_OFFICEGIBDD] = "";
	switch (request) {
	case 1:
		EnterName(search_text);
		break;
	case 2:
		EnterNumberOrSymbol(search_text, MAX_LENGTH_NUMBER_CUR);
		break;
	case 3:
		EnterNumberOrSymbol(search_text, MAX_LENGTH_NUMBER_TECHNICALCERTIFICATION);
		break;
	case 4:
		EnterDate(search_text);
		break;
	case 5:
		EnterPhone(search_text);
		break;
	case 6:
		EnterOfficeGIBDD(search_text);
		break;
	}

	PassingFile(request, search_text);
}

void PassingFile(int request, char *search_text) {
	FILE *StructFile = fopen(WAY_FILE, "r");
	if (StructFile == NULL) {
		fclose(StructFile);
		RepeatRequest(0);
	}
	else {
		char	text_file[MAX_LENGTH_STRING] = "",
			buf_text_file[MAX_LENGTH_STRING] = "";
		int	coincidence = 0,
			count = 0;

		while (fgets(text_file, MAX_LENGTH_STRING, StructFile) != NULL) {
			text_file[StringLength(text_file) - 1] = '\0';

			StringCopy(buf_text_file, text_file);
			coincidence = SearchPunct(text_file, request, search_text);

			if (coincidence) {
				printf("%s\n", buf_text_file);
				count++;
			}
		}

		if (!count) printf("���������� �� �������!\n");
	}

	fclose(StructFile);
}

void StringCopy(char *new_text, char *text) {
	for (int i = 0; i < MAX_LENGTH_STRING; i++)
		new_text[i] = '\0';

	int length = StringLength(text);
	for (int i = 0; i < length; i++)
		new_text[i] = text[i];
}

int SearchPunct(char *text_file, int request, char *search_text) {
	int	length = StringLength(text_file),
		position_tub = 0,
		coincidence = 1;

	for (int i = 0; i < (request - 1); i++) {
		position_tub = PositionTub(text_file);
		text_file = text_file + position_tub + 1;
	}
	if (StringLength(search_text) == PositionTub(text_file))
		for (int i = 0; text_file[i] != '\n' || text_file[i] != '\0' || text_file[i] != '\t'; i++) {
			if ((text_file[i] == '\n' || text_file[i] == '\0' || text_file[i] == '\t') && i > 0) {
				break;
			}

			if (text_file[i] != search_text[i] ||
				((search_text[i] == '\n' || search_text[i] == '\0') && i < StringLength(search_text))) {
				coincidence = 0;
				break;
			}

		}
	else coincidence = 0;

	if (coincidence)  return 1; else return 0;
}

int PositionTub(char *word) {
	int length = StringLength(word);

	for (int i = 0; i < length; i++)
		if (word[i] == '\t')
			return i;

	return NULL;
}

/*3 ������*/
void OutputStruct() {
	FILE *StructFile = fopen(WAY_FILE, "r");
	if (StructFile == NULL) {
		RepeatRequest(0);
	}
	else {
		char text_file[MAX_LENGTH_STRING] = "";
		while (fgets(text_file, MAX_LENGTH_STRING, StructFile) != NULL)
			printf("%s\n", text_file);

		fclose(StructFile);
	}
	fclose(StructFile);
}

/*4 ������*/
void SortingFile() {
	FILE *StructFile = fopen(WAY_FILE, "r");
	if (StructFile == NULL) {
		fclose(StructFile);
		RepeatRequest(0);
	}
	else {
		AddStructs(StructFile);
		//fclose(StructFile);
	}
	fclose(StructFile);
}

void AddStructs(FILE *StructFile) {
	char	text_file[MAX_LENGTH_STRING] = "";
	int	count = 0,
		max_length_name = 0;

	while (fgets(text_file, MAX_LENGTH_STRING, StructFile) != NULL) count++;

	struct car *Auto = (struct car *)calloc(count + 1, sizeof(struct car *));
	rewind(StructFile);

	for (int i = 0; i < count; i++) {
		fgets(text_file, MAX_LENGTH_STRING, StructFile);
		AddStruct(&Auto[i], text_file);
	}
	for (int i = 0; i < count; i++)
		if (StringLength(Auto[i].name) > max_length_name) max_length_name = StringLength(Auto[i].name);

	for (int k = 0; k < max_length_name; k++)
		for (int i = 0; i < count; i++) {
			for (int j = i + 1; j < count; j++) {
				if (Auto[i].name[k] && Auto[j].name[k]) {
					if (!k)
						if (((int)Auto[i].name[0] >(int)Auto[j].name[0]))
							SwapStructs(Auto[i], Auto[j]);

					if (((int)Auto[i].name[k] >(int)Auto[j].name[k]) &&
						((int)Auto[i].name[k - 1] == (int)Auto[j].name[k - 1]))
						SwapStructs(Auto[i], Auto[j]);
				}
			}
		}

	for (int i = 0; i < count; i++)
		EntryFile(StructFile, Auto[i]);
	fclose(StructFile);
}

void SwapStructs(struct car &Auto1, struct car &Auto2) {
	struct car tmp;
	tmp = Auto2;
	Auto2 = Auto1;
	Auto1 = tmp;
}

void AddStruct(struct car *Auto, char *text) {
	int position_tub = 0;

	ClearStruct(Auto);

	for (int i = 0; i < 6; i++) {
		position_tub = PositionTub(text);

		switch (i) {
		case 0:
			for (int i = 0; i < position_tub; i++)
				Auto->name[i] = text[i];
			break;
		case 1:
			for (int i = 0; i < position_tub; i++)
				Auto->NumberCur[i] = text[i];
			break;
		case 2:
			for (int i = 0; i < position_tub; i++)
				Auto->NumberTechnicalCertificate[i] = text[i];
			break;
		case 3:
			for (int i = 0; i < position_tub; i++)
				Auto->date[i] = text[i];
			break;
		case 4:
			for (int i = 0; i < position_tub; i++)
				Auto->phone[i] = text[i];
			break;
		case 5:
			for (int i = 0; i < position_tub; i++)
				Auto->OfficeGIBDD[i] = text[i];
			break;
		}

		text = text + position_tub + 1;
	}
}

void ClearStruct(struct car *Auto) {
	for (int i = 0; i < MAX_LENGTH_NAME; i++)
		Auto->name[i] = '\0';
	for (int i = 0; i < MAX_LENGTH_NUMBER_CUR; i++)
		Auto->NumberCur[i] = '\0';
	for (int i = 0; i < MAX_LENGTH_NUMBER_TECHNICALCERTIFICATION; i++)
		Auto->NumberTechnicalCertificate[i] = '\0';
	for (int i = 0; i < LENGTH_DATE; i++)
		Auto->date[i] = '\0';
	for (int i = 0; i < MAX_LENGTH_PHONE; i++)
		Auto->phone[i] = '\0';
	for (int i = 0; i < MAX_LENGTH_OFFICEGIBDD; i++)
		Auto->OfficeGIBDD[i] = '\0';
}
