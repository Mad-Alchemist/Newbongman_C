#pragma warning(disable:4996)
#include <stdio.h>
void main() {
	int R, C, N = 1, T, X = 1;

	char D[10][36] = {
		"  ####     #    #  #     ######  #  ",
		"##   ##    ######  #     #    #  #  ",
		"##   ##    #    ####     #    #  #  ",
		" ####      #    #  #     ######  #  ",
		"           #########             #  ",
		"######             #     #          ",
		" #  #         ####       #          ",
		" #  #        ##  ##      #########  ",
		"             ##  ##                 ",
		"              ####                  "
	};

	while (X) {
		system("cls");
		printf("\n(!) (유병민) 움직이는 배열\n\n ");

		for (R = 0; R < 9; R++) {
			for (C = 0; C < 36; C++) { printf("%c", D[R][C]); }
			printf("\n");
		}
		printf("\n(!) (유병민) 다음작업은? ");  X = getch();

		if (X == '4') {
			printf("왼쪽으로 이동했습니다.\n");
			for (R = 0; R < 9; R++) {
				T = D[R][0];
				for (C = 0; C < 36; C++) { D[R][C] = D[R][C + 1]; }	D[R][C] = T;
			}
		}

		if (X == '6') {
			printf("오른쪽으로 이동했습니다.\n");
			for (R = 0; R < 9; R++) {
				T = D[R][35];
				for (C = 35; C > 0; C--) {
						D[R][C] = D[R][C - 1];
				}	D[R][C] = T;
			}
		}

		if (X == '8') {
			printf("위로 이동했습니다.\n");
			for (C = 0; C < 36; C++) {
				T = D[0][C];
				for (R = 0; R < 9; R++) {
					D[R][C] = D[R + 1][C];
				}   D[R][C] = T;
			}
		}

		if (X == '2') {
			printf("아래로 이동했습니다.\n");
			for (C = 0; C < 36; C++) {
				T = D[9][C];
				for (R = 9; R > 0; R--) {
					D[R][C] = D[R - 1][C];
				}   D[R][C] = T;
			}

		}
	}
}