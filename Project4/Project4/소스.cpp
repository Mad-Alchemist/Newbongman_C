#include <stdio.h>

int main(void) {
	printf("2018E7128 유병민문제4\n\n");
	int a, b;
	int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int count[10] = { 0,0,0,0,0,0,0,0,0,0 };


	for (int i = 0; i < 12346; i++) {
		if (i == 10)
			count[0]++;
		b = i;
		while (b > 0) {
			a = b % 10;
			for (int j = 0; j < 10; j++) {
				if (a == num[j]) {
					count[j]++;
				}
			}
			b = b / 10;
		}
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		if (count[i] != 0)
			printf("%d:%d개\t", i, count[i]);
	}

	return 0;
}