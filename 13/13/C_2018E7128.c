#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {
	FILE* 파일 = fopen("c:\\Temp\\구구단.txt", "r");
	char 자료[50];

	if (파일 == NULL) {
		printf("파일 열기 실패\n");
	}
	else {
		printf("파일 열기 성공\n");
		while (feof(파일) == 0) {
			fscanf(파일, "%s", 자료);
			printf("%s \n", 자료);
		}
	}
	fclose(파일);
}