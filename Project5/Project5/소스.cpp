#include <stdio.h>

int main(void) {

	printf("2018E7128 유병민 문제5\n\n");
	while (1) {
		int val = 0, arr = 0;
		int a[7];
		printf("7자리정수를입력하여주세요.\n");
		scanf_s("%d", &val);

		for (int i = 1; i <= 1000000; i *= 10)          // 반복문을통해각자릿수별숫자를배열에입력
		{
			if (i == 1000000)
				a[arr] = val / i;
			else
				a[arr] = (val % (i * 10)) / i;
			arr++;
		}

		for (int i = 0; i < 7; i++)
		{
			if ((6 - i == 4 && a[6 - i] == 1 && (a[6] == 0 && a[5] == 0)) || (6 - i == 6 && a[6 - i] == 1) || (6 - i == 5 && a[6 - i] == 1) || (6 - i == 3 && a[6 - i] == 1) || (6 - i == 2 && a[6 - i] == 1) || (6 - i == 1 && a[6 - i] == 1))
			{
				printf("");
			}
			else
			{

				switch (a[6 - i])                           // 조건문을통해각숫자출력(0은출력하지않음)
				{
				case 1:
					printf("일");
					break;
				case 2:
					printf("이");
					break;
				case 3:
					printf("삼");
					break;
				case 4:
					printf("사");
					break;
				case 5:
					printf("오");
					break;
				case 6:
					printf("육");
					break;
				case 7:
					printf("칠");
					break;
				case 8:
					printf("팔");
					break;
				case 9:
					printf("구");
					break;
				case 0:
					printf("");
					break;
				}
			}
			if (i == 0 && a[6 - i] != 0)                      // 조건문을통해각자릿수별단위출력
				printf("백");
			else if (i == 1 && a[6 - i] != 0)
				printf("십");
			else if (i == 2 && (a[6] != 0 || a[5] != 0 || a[4] != 0))      // 백만, 십만이0이아닐경우만출력
				printf("만");
			else if (i == 3 && a[6 - i] != 0)
				printf("천");
			else if (i == 4 && a[6 - i] != 0)
				printf("백");
			else if (i == 5 && a[6 - i] != 0)
				printf("십");
			else if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 && a[6] == 0)
			{
				printf("Zero");     //값이0일경우반복문탈출
				break;
			}
			else
				printf("");

		}
		printf("\n");
	}

	return 0;
}
