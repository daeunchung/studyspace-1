#include <Windows.h>
#include <stdio.h>
#include <time.h>

void gugudan(int* p) {
	for (int i = 0; i < 3; i++) {
		int x = rand() % 8 + 2;		// 2 ~ 9
		int y = rand() % 9 + 1;		// 1 ~ 9

		int answer = x * y;
		printf("%d  X %d = ?\n", x, y);
		int my_answer;
		scanf_s("%d", &my_answer);

		if (my_answer == answer) {
			printf("정답\n");
			p[0] += 1;
			// (*p) += 1;
		}
		else {
			printf("오답\n");
		}
	}
}

void main() {

	srand(time(0));

	// 문제) 구구단을 3문제 랜덤하게 출제하고, 정답의 개수 출력 

	int c = 0;
	gugudan(&c);

	printf("정답개수 : %d", c); printf("\n");

	system("pause");
}
