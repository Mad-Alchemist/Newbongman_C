#include <stdio.h>

int main(void) {

	printf("2018E7128 À¯º´¹Î ¹®Á¦3\n\n");
	int a=3, b=1, c=1 ,d=0;

	 do{
		do
		{
			a = b * 3;
			do
			{
				printf("%d * %d = %d\t", a, c, a * c);
				d++;
				a --;
			}while (d < 3);
			printf("\n");
			c++;
			d = 0;
		} while (c < 10);
		b++;
		c = 1;
	 } while (b < 4);

	return 0;
}