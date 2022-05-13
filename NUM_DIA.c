#include <stdio.h>

int main(void)
{
	int input;
	while (1) {
		printf("원하는 숫자를 입력하세요.(1을 제외한 홀수만 입력 가능)\n");
		scanf_s("%d", &input);
		if (input % 2 == 0 || input == 1)
			printf("1을 제외한 홀수만 입력하세요.\n");
		else {
			int a = (input + 1) / 2;
			int b, c;
			b = a;
			c = a;
			for (int i = 0; i < a; i++)
			{
				for (int j = a - 1; j >i; j--)
					printf(" ");
				if (b == a || c == a)
				{
					printf("%d", a);
					b--;
					c++;
				}
				else
				{
					printf("%d", b);
					if (i == 0)
					{
						printf(" ");
					}
					else
					{
						for (int j = 0; j < i; j++)
							printf(" ");
						for (int j = 0; j < i; j++)
							printf(" ");
					}
					printf("%d", c);
					b--;
					c++;
				}
				for (int j = a - 1; j >i; j--)
					printf(" ");
				printf("\n");

			}
			b = 2;
			c = input - 1;
			for (int i = 1; i < a; i++)
			{
				for (int j = 0; j < i; j++)
					printf(" ");
				if (b == a || c == a)
				{
					printf("%d", a);
				}
				else
				{
					printf("%d", b);
					if (i == a)
					{
						printf(" ");
					}
					else
					{
						for (int j = 1; j < a - i; j++)
							printf(" ");
						for (int j = 1; j < a - i; j++)
							printf(" ");
					}
					printf("%d", c);
					b++;
					c--;
				}
				for (int j = 0; j < i; j++)
					printf(" ");
				printf("\n");

			}
			break;
		}
		return 0;
	}
}