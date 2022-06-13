#include <stdio.h>		// 표준 입출력을 지원하는 라이브러리
#include <string.h>		// 문자열 연산을 지원하는 라이브러리
#include <stdlib.h>		// 화면을 지우기 위한 system 명령을 지원하는 라이브러리
#include <windows.h>	// 화면에 좌표를 지정하는 gotoxy 용 명령을 지원하는 라이브러리
#include <conio.h>		// 키보드 입력용 getch 를 지원하는 라이브러리
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

int isDir(char* s) {             //추가 1. 디렉토리 존재여부 검사 함수
	_finddatai64_t c_file;
	int hFile, result;

	if ((hFile = _findfirsti64(s, &c_file)) == -1L)
		result = 0; // 파일 또는 디렉토리가 없으면 0 반환
	else if (c_file.attrib & _A_SUBDIR)
		result = 1; // 디렉토리면 1 반환

	_findclose(hFile);
	return result;
}

int isFile(char* s) {			//추가 2. 파일 존재 여부 검사 함수
	_finddatai64_t c_file;
	int hFile, result;

	if ((hFile = _findfirsti64(s, &c_file)) == -1L)
		result = 0; // 파일 또는 디렉토리가 없으면 0 반환
	else if (c_file.attrib & _A_SUBDIR)
		result = 0; // 디렉토리면 0 반환
	else
		result = 1; // 그밖의 경우는 "존재하는 파일"이기에 1 반환

	_findclose(hFile);
	return result;
}

char& set_dir() {				//추가 3. 디렉토리 지정 함수
	printf("\n저장 경로를 입력하여 주십시오. \n");
	char a[256];
	while (1) {
		scanf("%s", &a);
		if (isDir(a) == 1)
		{
			break;
		}
		else
		{
			printf("잘못된 경로 입니다. 다시 입력하여 주십시오.\n");
		}
	}
	return *a;
}

char& sav_file()				//추가 4. 파일명 지정 함수
{
	printf("저장할 파일의 이름을 입력하여 주십시오. (확장자 미포함)\n");
	char a[30];
	scanf("%s", &a);

	return *a;
}

char& set_file()
{
	char a[256];
	printf("파일의 경로와 파일명 전체를 입력하여 주십시오.\n");
	scanf("%s", &a);
	if (isFile(a))
	{
		printf("파일 지정 완료.\n");
	}
	else
	{
		printf("파일 경로를 확인하여 주십시오.\n");
	}
	return *a;
}

	void gotoxy(int x, int y) {
		COORD Pos = { x - 1, y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}



	// 성적 데이터 입력 처리
	int  InputData() {
		printf("성적 데이터 입력\n");
		printf("학번\t이름\t국어\t영어\t수학\n");
		for (int i = 0; i < 5; i++) {
			scanf("%s %s %d %d %d", &snum[i], &name[i], &sbj1[i], &sbj2[i], &sbj3[i]);
		}
		return 0;
	}


	// 파일에 있는 성적 데이터를 화면으로 출력 처리
	int ViewData() {
		printf("성적 데이터 출력\n");
		printf("학번\t\t이름\t국어\t영어\t수학\t합계\t평균\t등급\n");
		printf("====================================================================================\n");
		for (int i = 0; i < 5; i++)
		{
			sum[i] = sbj1[i] + sbj2[i] + sbj3[i];
			printf("%s\t\t%s\t%d\t%d\t%d\t%d\t%d\t%c\n", snum[i], name[i], sbj1[i], sbj2[i], sbj3[i],sum[i],sum[i]/3,Grade(sum[i]/3));
		}
		return 0;
	}


	// 파일에 있는 성적 데이터를 파일로 출력
	int  SaveReport() {
		char dty[256];                                     //경로 지정 및 파일명 지정
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".TXT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("파일 개방 실패.\n");
		}
		else
		{
			fprintf(input, "\t\t유병민 성적표 데이터 파일 (원본)\n");
			fprintf(input, "========================================================================\n");
			fprintf(input, "학번\t\t이름\t국어\t영어\t수학\t합계\t평균\t등급\n");
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
		char dty[256];                                     //경로 지정 및 파일명 지정
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".DAT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("파일 개방 실패.\n");
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

	// 파일에 있는 성적 데이터를 Excel 파일로 출력
	int  SaveCSV() {
		// 입력 파일 열기----------------------------------------------------	
		strcpy(fname1, &set_file());              //파일 지정

		if ((fp1 = fopen(fname1, "r")) == NULL)
		{
			printf("\n(!) 입력파일 : \"%s\" 을 열 수 없습니다.", fname1);	return 0;
		}
		else
		{
			printf("\n(!) 입력파일 : \"%s\" 을 열었습니다.", fname1);
		}

		char dty[256];
		strcpy(dty, &set_dir());          //경로 지정/ 파일명 설정
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".CSV");
		// 출력 파일 열기----------------------------------------------------	
		strcpy(fname2, dty);
		if ((fp2 = fopen(fname2, "w")) == NULL)
		{
			printf("\n(!) 출력파일 : \"%s\" 을 만들 수 없습니다.", fname2);	return 0;
		}
		else
		{
			printf("\n(!) 출력파일 : \"%s\" 을 만들었습니다.", fname2);
		}

		// 성적집계표 (그대로, CSV) 출력----------------------------------------
		fprintf(fp2, "\n유병민의 성적표 만들기(CSV) \n");
		fprintf(fp2, "==========,=====,=====,=====,=====,=====,=====,===== \n");
		fprintf(fp2, "학번,이름,국어,영어,수학,합계,평균,등급 \n");
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
		printf("\n\t(!) 총 %d 건의 데이터를 처리하였습니다. \n", CNT);

		fprintf(fp2, "==========,=====,=====,=====,=====,=====,=====,===== \n");

		// 입출력 파일 닫기----------------------------------------------------
		fclose(fp1);	printf("\n(!) 입력파일을 닫았습니다.");
		fclose(fp2);	printf("\n(!) 출력파일을 닫았습니다.");
		system(dty);

		return 0;
	}

	// 파일에 있는 성적 데이터를 HTML 파일로 출력
	int  SaveHTML() {
		// 입력 파일 열기
		strcpy(fname1, &set_file());

		if ((fp1 = fopen(fname1, "r")) == NULL)
		{
			fprintf(stderr, "(!) 입력파일 : \"%s\" 을 열 수 없습니다.\n", fname1);	return 0;
		}
		else
		{
			printf("(!) 입력파일 : \"%s\" 을 열었습니다.\n", fname1);
		}

		char dty[256];
		strcpy(dty, &set_dir());          //경로 지정/ 파일명 설정
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".HTML");
		// 출력 파일 열기	
		strcpy(fname2, dty);
		if ((fp2 = fopen(fname2, "w")) == NULL)
		{
			fprintf(stderr, "(!) 출력파일 : \"%s\" 을 만들 수 없습니다.\n", fname2);	return 0;
		}
		else
		{
			printf("(!) 출력파일 : \"%s\" 을 만들었습니다.\n", fname2);
		}

		// 성적집계표-1 (그대로, HTML) 출력----------------------------------------
		fprintf(fp2, "<!DOCTYPE html><HTML><HEAD> \n");

		fprintf(fp2, "<TITLE>유병민의 HTML 성적표</TITLE> \n");
		fprintf(fp2, "<STYLE> \n");
		fprintf(fp2, "table {border-collapse: collapse; text-align: center; width: 500px; } \n");
		fprintf(fp2, "table tr:hover {background-color: lightgreen; height:40px;} \n");
		fprintf(fp2, "</STYLE></HEAD><BODY> \n");
		fprintf(fp2, "<DIV align=center><H2>유병민의 성적표 만들기(HTML)</H2></DIV> \n");
		fprintf(fp2, "<TABLE border=1 align=center> \n");
		fprintf(fp2, "<THEAD> \n");
		fprintf(fp2, "<TR><TH>학번</TH><TH>이름</TH><TH>국어</TH><TH>영어</TH><TH>수학</TH><TH>합계</TH><TH>평균</TH><TH>등급</TH></TR> \n");
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
		printf("\t(!) 총 %d 건의 데이터를 처리하였습니다. \n", CNT);
		fprintf(fp2, "</TBODY> \n");
		fprintf(fp2, "</TABLE> \n");
		fprintf(fp2, "</BODY> \n </HTML> \n");

		// 입/출력 파일 닫기----------------------------------------------------
		fclose(fp1);	printf("(!) 입력파일을 닫았습니다.\n");
		fclose(fp2);	printf("(!) 출력파일을 닫았습니다.\n");
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

		char dty[256];                                     //경로 지정 및 파일명 지정
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".TXT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("파일 개방 실패.\n");
		}
		else
		{
			fprintf(input, "\t\t유병민 성적표 데이터 파일 (성적순)\n");
			fprintf(input, "========================================================================\n");
			fprintf(input, "학번\t\t이름\t국어\t영어\t수학\t합계\t평균\t등급\t석차\n");
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

		char dty[256];                                     //경로 지정 및 파일명 지정
		strcpy(dty, &set_dir());
		strcat(dty, "\\");
		strcat(dty, &sav_file());
		strcat(dty, ".TXT");
		FILE* input = fopen(dty, "w");
		if (input == NULL)
		{
			printf("파일 개방 실패.\n");
		}
		else
		{
			fprintf(input, "\t\t유병민 성적표 데이터 파일 (이름순)\n");
			fprintf(input, "========================================================================\n");
			fprintf(input, "학번\t\t이름\t국어\t영어\t수학\t합계\t평균\t등급\n");
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
		strcpy(dty, &set_file());              //파일 지정
		FILE* input;
		if ((input = fopen(dty, "r")) == NULL)
		{
			printf("\n(!) 입력파일 : \"%s\" 을 열 수 없습니다.", dty);	return 0;
		}
		else
		{
			printf("\n(!) 입력파일 : \"%s\" 을 열었습니다.", dty);
		}
		

		for (int i = 0; i < 5; i++)
		{
			fscanf(input, "%s %s %d %d %d", &snum[i], &name[i], &sbj1[i], &sbj2[i], &sbj3[i]);
		}
		printf("파일 불러오기 완료\n");

		return 0; 
	}


	int main(void) {
		while (1) {
			gotoxy(2, 2);
			printf("\n\t 유병민의 성적처리 시스템 ");
			printf("\n\t =========================\n");
			printf("\n\t << 작업 목록 >>---------------------- ");
			printf("\n\t   1. 새로운 성적 데이터 저장하기 ");
			printf("\n\t   2. 성적 데이터 화면에 표시하기 ");
			printf("\n\t   3. 성적 집계표 파일 만들기 ");
			printf("\n\t   4. 성적집계표-1 (성적순) 출력 ");
			printf("\n\t   5. 성적집계표-2 (이름순) 출력 ");
			printf("\n\t   6. Web Page(HTML) 로 출력 ");
			printf("\n\t   7. Excel File(CSV) 로 출력 ");
			printf("\n\t   8. .DAT 파일 만들기 (6,7번 기능 수행용 파일) ");
			printf("\n\t   9. .DAT 파일 불러오기 ");
			printf("\n\t   0. 작업끝 ");
			printf("\n\t --------------<< 번호를 선택하시오 >>");
			N = _getch();

			switch (N) {
			case  '0': {printf("\nbye...\n\n");  return 0;		break; } 	// 작업 종료
			case  '1': InputData();	break;  	// 데이터 입력
			case  '2': ViewData();		break;  	// 데이터 확인
			case  '3': SaveReport();	break;  	// 성적집계표 출력(굴림체)
			case  '4': SaveReport1();	break;  	// 성적집계표-1 출력(이름순)
			case  '5': SaveReport2();	break;  	// 성적집계표-2 출력(성적순)
			case  '6': SaveHTML();		break;  	// Web Page(HTML) 로 출력(성적순)
			case  '7': SaveCSV();		break;  	// Excel File(CSV) 로 출력(이름순) 
			case  '8': mkdf();		 	break;  		// 추가기능 6,7번 기능 수행용 .DAT 파일 생성하기
			case  '9': Option_A(); 		break;  		// 추가기능 .DAT 파일 불러오기
			}
			printf("\n\t ---------------------------<< 확인 >>");
			N = _getch();
			system("cls");
		}
	}
