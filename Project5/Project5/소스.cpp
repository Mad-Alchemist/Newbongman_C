#include <stdio.h>

int main(void) {

	printf("2018E7128 ������ ����5\n\n");
	while (1) {
		int val = 0, arr = 0;
		int a[7];
		printf("7�ڸ��������Է��Ͽ��ּ���.\n");
		scanf_s("%d", &val);

		for (int i = 1; i <= 1000000; i *= 10)          // �ݺ��������ذ��ڸ��������ڸ��迭���Է�
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

				switch (a[6 - i])                           // ���ǹ������ذ��������(0�������������)
				{
				case 1:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("��");
					break;
				case 7:
					printf("ĥ");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
				case 0:
					printf("");
					break;
				}
			}
			if (i == 0 && a[6 - i] != 0)                      // ���ǹ������ذ��ڸ������������
				printf("��");
			else if (i == 1 && a[6 - i] != 0)
				printf("��");
			else if (i == 2 && (a[6] != 0 || a[5] != 0 || a[4] != 0))      // �鸸, �ʸ���0�̾ƴҰ�츸���
				printf("��");
			else if (i == 3 && a[6 - i] != 0)
				printf("õ");
			else if (i == 4 && a[6 - i] != 0)
				printf("��");
			else if (i == 5 && a[6 - i] != 0)
				printf("��");
			else if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 && a[6] == 0)
			{
				printf("Zero");     //����0�ϰ��ݺ���Ż��
				break;
			}
			else
				printf("");

		}
		printf("\n");
	}

	return 0;
}
