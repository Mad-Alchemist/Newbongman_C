#include <stdio.h>		// ǥ�� ������� �����ϴ� ���̺귯��
#include <string.h>		// ���ڿ� ������ �����ϴ� ���̺귯��
#include <stdlib.h>		// ȭ���� ����� ���� system ����� �����ϴ� ���̺귯��
#include <windows.h>	// ȭ�鿡 ��ǥ�� �����ϴ� gotoxy �� ����� �����ϴ� ���̺귯��
#include <conio.h>		// Ű���� �Է¿� getch �� �����ϴ� ���̺귯��
#include <io.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


	FILE* fp1, * fp2;
	char fname1[20], fname2[20], sid[10];
	int N, CNT = 0, score1, score2, score3, total, average;
	char name[5][20], snum[5][20];
	int sbj1[5], sbj2[5], sbj3[5], sum[5];


char Grade(int X) {
		char grade;
		if (X >= 90) grade = 'A';
		else 	if (X >= 80) grade = 'B';
		else 	if (X >= 70) grade = 'C';
		else 	if (X >= 60) grade = 'D';
		else 	if (X <= 59) grade = 'F';
		return grade;
}

int isDir(char* s) {             //�߰� 1. ���丮 ���翩�� �˻� �Լ�
	_finddatai64_t c_file;
	int hFile, result;

	if ((hFile = _findfirsti64(s, &c_file)) == -1L)
		result = 0; // ���� �Ǵ� ���丮�� ������ 0 ��ȯ
	else if (c_file.attrib & _A_SUBDIR)
		result = 1; // ���丮�� 1 ��ȯ

	_findclose(hFile);
	return result;
}

int isFile(char* s) {			//�߰� 2. ���� ���� ���� �˻� �Լ�
	_finddatai64_t c_file;
	int hFile, result;

	if ((hFile = _findfirsti64(s, &c_file)) == -1L)
		result = 0; // ���� �Ǵ� ���丮�� ������ 0 ��ȯ
	else if (c_file.attrib & _A_SUBDIR)
		result = 0; // ���丮�� 0 ��ȯ
	else
		result = 1; // �׹��� ���� "�����ϴ� ����"�̱⿡ 1 ��ȯ

	_findclose(hFile);
	return result;
}

char& set_dir() {				//�߰� 3. ���丮 ���� �Լ�
	printf("\n���� ��θ� �Է��Ͽ� �ֽʽÿ�. \n");
	char a[256];
	while (1) {
		scanf("%s", &a);
		if (isDir(a) == 1)
		{
			break;
		}
		else
		{
			printf("�߸��� ��� �Դϴ�. �ٽ� �Է��Ͽ� �ֽʽÿ�.\n");
		}
	}
	return *a;
}

char& sav_file()				//�߰� 4. ���ϸ� ���� �Լ�
{
	printf("������ ������ �̸��� �Է��Ͽ� �ֽʽÿ�. (Ȯ���� ������)\n");
	char a[30];
	scanf("%s", &a);

	return *a;
}

char& set_file()
{
	char a[256];
	printf("������ ��ο� ���ϸ� ��ü�� �Է��Ͽ� �ֽʽÿ�.\n");
	scanf("%s", &a);
	if (isFile(a))
	{
		printf("���� ���� �Ϸ�.\n");
	}
	else
	{
		printf("���� ��θ� Ȯ���Ͽ� �ֽʽÿ�.\n");
	}
	return *a;
}

	void gotoxy(int x, int y) {
		COORD Pos = { x - 1, y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}



	// ���� ������ �Է� ó��
	int  InputData() {
		printf("���� ������ �Է�\n");
		printf("�й�\t�̸�\t����\t����\t����\n");
		for (int i = 0; i < 5; i++) {
			scanf("%s %s %d %d %d", &snum[i], &name[i], &sbj1[i], &sbj2[i], &sbj3[i]);
		}
		return 0;
	}


	// ���Ͽ� �ִ� ���� �����͸� ȭ������ ��� ó��
	int ViewData() {
		printf("���� ������ ���\n");
		printf("�й�\t\t�̸�\t����\t����\t����\t�հ�\t���\t���\n");
		printf("====================================================================================\n");
		for (int i = 0; i < 5; i++)
		{
			sum[i] = sbj1[i] + sbj2[i] + sbj3[i];
			printf("%s\t\t%s\t%d\t%d\t%d\t%d\t%d\t%c\n", snum[i], name[i], sbj1[i], sbj2[i], sbj3[i],sum[i],sum[i]/3,Grade(sum[i]/3));
		}
		return 0;
	}


	// ���Ͽ� �ִ� ���� �����͸� ���Ϸ� ���
	int  SaveReport() {
		char dty[256];                                     //��� ���� �� ���ϸ� ����
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".TXT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("���� ���� ����.\n");
		}
		else
		{
			fprintf(input, "\t\t������ ����ǥ ������ ���� (����)\n");
			fprintf(input, "========================================================================\n");
			fprintf(input, "�й�\t\t�̸�\t����\t����\t����\t�հ�\t���\t���\n");
			fprintf(input, "========================================================================\n");
			for (int i = 0; i < 5; i++)
			{
				fprintf(input,"%s\t\t%s\t%d\t%d\t%d\t%d\t%d\t%c\n", snum[i], name[i], sbj1[i], sbj2[i], sbj3[i], sum[i], sum[i] / 3, Grade(sum[i] / 3));
			}
			fclose(input);
		}

		
		return 0;
	}

	int mkdf()
	{
		char dty[256];                                     //��� ���� �� ���ϸ� ����
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".DAT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("���� ���� ����.\n");
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				fprintf(input, "%s\t\t%s\t%d\t%d\t%d\n", snum[i], name[i], sbj1[i], sbj2[i], sbj3[i]);
			}
			fclose(input);
		}


		return 0;
	}

	// ���Ͽ� �ִ� ���� �����͸� Excel ���Ϸ� ���
	int  SaveCSV() {
		// �Է� ���� ����----------------------------------------------------	
		strcpy(fname1, &set_file());              //���� ����

		if ((fp1 = fopen(fname1, "r")) == NULL)
		{
			printf("\n(!) �Է����� : \"%s\" �� �� �� �����ϴ�.", fname1);	return 0;
		}
		else
		{
			printf("\n(!) �Է����� : \"%s\" �� �������ϴ�.", fname1);
		}

		char dty[256];
		strcpy(dty, &set_dir());          //��� ����/ ���ϸ� ����
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".CSV");
		// ��� ���� ����----------------------------------------------------	
		strcpy(fname2, dty);
		if ((fp2 = fopen(fname2, "w")) == NULL)
		{
			printf("\n(!) ������� : \"%s\" �� ���� �� �����ϴ�.", fname2);	return 0;
		}
		else
		{
			printf("\n(!) ������� : \"%s\" �� ��������ϴ�.", fname2);
		}

		// ��������ǥ (�״��, CSV) ���----------------------------------------
		fprintf(fp2, "\n�������� ����ǥ �����(CSV) \n");
		fprintf(fp2, "==========,=====,=====,=====,=====,=====,=====,===== \n");
		fprintf(fp2, "�й�,�̸�,����,����,����,�հ�,���,��� \n");
		fprintf(fp2, "==========,=====,=====,=====,=====,=====,=====,===== \n");

		CNT = 0;
		while (!feof(fp1)) {
			fscanf(fp1, "%s %s %d %d %d", sid, name, &score1, &score2, &score3);
			if (feof(fp1)) { break; }

			total = score1 + score2 + score3;
			average = total / 3;

			fprintf(fp2, "%s, %s, %d, %d, %d, %d, %d, %c \n",
				sid, name, score1, score2, score3, total, average, Grade(average));
			CNT++;
		}
		printf("\n\t(!) �� %d ���� �����͸� ó���Ͽ����ϴ�. \n", CNT);

		fprintf(fp2, "==========,=====,=====,=====,=====,=====,=====,===== \n");

		// ����� ���� �ݱ�----------------------------------------------------
		fclose(fp1);	printf("\n(!) �Է������� �ݾҽ��ϴ�.");
		fclose(fp2);	printf("\n(!) ��������� �ݾҽ��ϴ�.");
		system(dty);

		return 0;
	}

	// ���Ͽ� �ִ� ���� �����͸� HTML ���Ϸ� ���
	int  SaveHTML() {
		// �Է� ���� ����
		strcpy(fname1, &set_file());

		if ((fp1 = fopen(fname1, "r")) == NULL)
		{
			fprintf(stderr, "(!) �Է����� : \"%s\" �� �� �� �����ϴ�.\n", fname1);	return 0;
		}
		else
		{
			printf("(!) �Է����� : \"%s\" �� �������ϴ�.\n", fname1);
		}

		char dty[256];
		strcpy(dty, &set_dir());          //��� ����/ ���ϸ� ����
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".HTML");
		// ��� ���� ����	
		strcpy(fname2, dty);
		if ((fp2 = fopen(fname2, "w")) == NULL)
		{
			fprintf(stderr, "(!) ������� : \"%s\" �� ���� �� �����ϴ�.\n", fname2);	return 0;
		}
		else
		{
			printf("(!) ������� : \"%s\" �� ��������ϴ�.\n", fname2);
		}

		// ��������ǥ-1 (�״��, HTML) ���----------------------------------------
		fprintf(fp2, "<!DOCTYPE html><HTML><HEAD> \n");

		fprintf(fp2, "<TITLE>�������� HTML ����ǥ</TITLE> \n");
		fprintf(fp2, "<STYLE> \n");
		fprintf(fp2, "table {border-collapse: collapse; text-align: center; width: 500px; } \n");
		fprintf(fp2, "table tr:hover {background-color: lightgreen; height:40px;} \n");
		fprintf(fp2, "</STYLE></HEAD><BODY> \n");
		fprintf(fp2, "<DIV align=center><H2>�������� ����ǥ �����(HTML)</H2></DIV> \n");
		fprintf(fp2, "<TABLE border=1 align=center> \n");
		fprintf(fp2, "<THEAD> \n");
		fprintf(fp2, "<TR><TH>�й�</TH><TH>�̸�</TH><TH>����</TH><TH>����</TH><TH>����</TH><TH>�հ�</TH><TH>���</TH><TH>���</TH></TR> \n");
		fprintf(fp2, "</THEAD><TBODY> \n");

		CNT = 0;
		int sum, kor, eng, mat,avg;
		while (!feof(fp1)) {
			fscanf(fp1, "%s %s %d %d %d", sid, name, &kor, &eng, &mat);
			if (feof(fp1)) { break; }
			sum = kor + eng + mat;	  avg = sum / 3;

			fprintf(fp2, "<TR><TD>%s</TD><TD>%s</TD><TD>%d</TD><TD>%d</TD><TD>%d</TD><TD>%d</TD><TD>%d</TD><TD>%c</TD></TR> \n",
				sid, name, kor, eng, mat, sum, avg, Grade(avg));
			CNT++;
		}
		printf("\t(!) �� %d ���� �����͸� ó���Ͽ����ϴ�. \n", CNT);
		fprintf(fp2, "</TBODY> \n");
		fprintf(fp2, "</TABLE> \n");
		fprintf(fp2, "</BODY> \n </HTML> \n");

		// ��/��� ���� �ݱ�----------------------------------------------------
		fclose(fp1);	printf("(!) �Է������� �ݾҽ��ϴ�.\n");
		fclose(fp2);	printf("(!) ��������� �ݾҽ��ϴ�.\n");
		system(dty);


		return 0;
	}
	int EditData() { 
		return 0; }
	
	int SaveReport1() { 
		struct r1
		{
			char name[20];
			char snum[20];
			int sbj1, sbj2, sbj3, sum;
		};

		struct r1 rr[5];
		for (int i = 0; i < 5; i++)
		{
			strcpy(rr[i].name, name[i]);
			strcpy(rr[i].snum, snum[i]);
			rr[i].sbj1 = sbj1[i];
			rr[i].sbj2 = sbj2[i];
			rr[i].sbj3 = sbj3[i];
			rr[i].sum = rr[i].sbj1 + rr[i].sbj2 + rr[i].sbj3;
		}
		struct r1 tmp;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (rr[i].sum > rr[j].sum)
				{
					tmp = rr[i];
					rr[i] = rr[j];
					rr[j] = tmp;
				}
			}
		}

		char dty[256];                                     //��� ���� �� ���ϸ� ����
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".TXT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("���� ���� ����.\n");
		}
		else
		{
			fprintf(input, "\t\t������ ����ǥ ������ ���� (������)\n");
			fprintf(input, "========================================================================\n");
			fprintf(input, "�й�\t\t�̸�\t����\t����\t����\t�հ�\t���\t���\t����\n");
			fprintf(input, "========================================================================\n");
			for (int i = 0; i < 5; i++)
			{
				fprintf(input, "%s\t\t%s\t%d\t%d\t%d\t%d\t%d\t%c\t%d\n", rr[i].snum, rr[i].name, rr[i].sbj1, rr[i].sbj2, rr[i].sbj3, rr[i].sum, rr[i].sum  / 3, Grade(rr[i].sum/3), i+1);
			}
			fclose(input);
		}


		return 0; 
	}

	int SaveReport2() {
		struct r1
		{
			char snum[20];
			char name[20];
			int sbj1, sbj2, sbj3, sum;
		};

		struct r1 rr[5];
		for (int i = 0; i < 5; i++)
		{
			strcpy(rr[i].snum, snum[i]);
			strcpy(rr[i].name, name[i]);
			rr[i].sbj1 = sbj1[i];
			rr[i].sbj2 = sbj2[i];
			rr[i].sbj3 = sbj3[i];
			rr[i].sum = rr[i].sbj1 + rr[i].sbj2 + rr[i].sbj3;
		}
		struct r1 tmp;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < (4-i); j++)
			{
				if (strcmp(rr[j].name,rr[j+1].name)>0)
				{
					tmp = rr[j];
					rr[j] = rr[j+1];
					rr[j+1] = tmp;
				}
			}
		}

		char dty[256];                                     //��� ���� �� ���ϸ� ����
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".TXT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("���� ���� ����.\n");
		}
		else
		{
			fprintf(input, "\t\t������ ����ǥ ������ ���� (�̸���)\n");
			fprintf(input, "========================================================================\n");
			fprintf(input, "�й�\t\t�̸�\t����\t����\t����\t�հ�\t���\t���\n");
			fprintf(input, "========================================================================\n");
			for (int i = 0; i < 5; i++)
			{
				fprintf(input, "%s\t\t%s\t%d\t%d\t%d\t%d\t%d\t%c\n", rr[i].snum, rr[i].name, rr[i].sbj1, rr[i].sbj2, rr[i].sbj3, rr[i].sum, rr[i].sum / 3, Grade(rr[i].sum / 3));
			}
			fclose(input);
		}

		return 0; 
	}

	int Option_A() {
		char dty[256];
		printf("\n");
		strcpy(dty, &set_file());              //���� ����
		FILE* input;
		if ((input = fopen(dty, "r")) == NULL)
		{
			printf("\n(!) �Է����� : \"%s\" �� �� �� �����ϴ�.", dty);	return 0;
		}
		else
		{
			printf("\n(!) �Է����� : \"%s\" �� �������ϴ�.", dty);
		}
		

		for (int i = 0; i < 5; i++)
		{
			fscanf(input, "%s %s %d %d %d", &snum[i], &name[i], &sbj1[i], &sbj2[i], &sbj3[i]);
		}
		printf("���� �ҷ����� �Ϸ�\n");

		return 0; 
	}


	int main(void) {
		while (1) {
			gotoxy(2, 2);
			printf("\n\t �������� ����ó�� �ý��� ");
			printf("\n\t =========================\n");
			printf("\n\t << �۾� ��� >>---------------------- ");
			printf("\n\t   1. ���ο� ���� ������ �����ϱ� ");
			printf("\n\t   2. ���� ������ ȭ�鿡 ǥ���ϱ� ");
			printf("\n\t   3. ���� ����ǥ ���� ����� ");
			printf("\n\t   4. ��������ǥ-1 (������) ��� ");
			printf("\n\t   5. ��������ǥ-2 (�̸���) ��� ");
			printf("\n\t   6. Web Page(HTML) �� ��� ");
			printf("\n\t   7. Excel File(CSV) �� ��� ");
			printf("\n\t   8. .DAT ���� ����� (6,7�� ��� ����� ����) ");
			printf("\n\t   9. .DAT ���� �ҷ����� ");
			printf("\n\t   0. �۾��� ");
			printf("\n\t --------------<< ��ȣ�� �����Ͻÿ� >>");
			N = _getch();

			switch (N) {
			case  '0': {printf("\nbye...\n\n");  return 0;		break; } 	// �۾� ����
			case  '1': InputData();	break;  	// ������ �Է�
			case  '2': ViewData();		break;  	// ������ Ȯ��
			case  '3': SaveReport();	break;  	// ��������ǥ ���(����ü)
			case  '4': SaveReport1();	break;  	// ��������ǥ-1 ���(�̸���)
			case  '5': SaveReport2();	break;  	// ��������ǥ-2 ���(������)
			case  '6': SaveHTML();		break;  	// Web Page(HTML) �� ���(������)
			case  '7': SaveCSV();		break;  	// Excel File(CSV) �� ���(�̸���) 
			case  '8': mkdf();		 	break;  		// �߰���� 6,7�� ��� ����� .DAT ���� �����ϱ�
			case  '9': Option_A(); 		break;  		// �߰���� .DAT ���� �ҷ�����
			}
			printf("\n\t ---------------------------<< Ȯ�� >>");
			N = _getch();
			system("cls");
		}
	}
