#include <stdio.h>

int main(void)
{
	int a[5];
	int tmp;
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
		printf("%d", a[i]);
	}

	return 0;
}