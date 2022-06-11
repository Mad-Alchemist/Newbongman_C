#include <stdio.h>

int main(void)
{

	printf("2018E7128 유병민 문제 1\n\n");
	char Hexstr[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char Result[10];
	int Radix, N0, N1, TMP, J;
	float Dec;
	
	printf("진법을 입력하시오.\n");
	scanf_s("%d", &Radix);
	printf("변환할 수를 입력하시오.\n");
	scanf_s("%f", &Dec);

	N1 = (int)Dec;
	N0 = Dec - N1;
	J = 0;
	while (N1>0) {
		TMP = N1 % Radix;
		N1 = N1 / Radix;
		Result[J] = Hexstr[TMP];
		J += 1;
	}
	for (int i = 1; i <= J; i++)
	{
		printf("%c",Result[J - i]);
	}
	J = 0;
	printf(".");
	while (J < 4) {
		N0 = N0 * (float)Radix;
		TMP = (int)N0;
		N0 = N0 - TMP;
		J += 1;
		printf("%d", TMP);
	}
	return 0;
}