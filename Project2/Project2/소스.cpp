#include <stdio.h>

int main(void)
{
	printf("2018E7128 유병민 문제2\n\n");
	int a[5];
	int tmp;
	printf("5개의 정수를 입력하시오.\n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &a[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i] < a[j]) {

				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d\t", a[i]);
	}

	return 0;
}