#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {
	FILE* ���� = fopen("c:\\Temp\\������.txt", "r");
	char �ڷ�[50];

	if (���� == NULL) {
		printf("���� ���� ����\n");
	}
	else {
		printf("���� ���� ����\n");
		while (feof(����) == 0) {
			fscanf(����, "%s", �ڷ�);
			printf("%s \n", �ڷ�);
		}
	}
	fclose(����);
}