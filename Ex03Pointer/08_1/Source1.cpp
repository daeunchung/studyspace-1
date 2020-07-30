#include <Windows.h>
#include <stdio.h>
#include <time.h>

void main() {

	srand(time(0));

	// 학번  국어   수학

	int** pp = 0;
	int count = 0;

	int num = 0;

	int run = 1;
	while (run) {
		printf("학번\t국어\t수학\n");
		for (int i = 0; i<count; i++) {
			printf("[%d] > %d점\t%d점\n", pp[i][0], pp[i][1], pp[i][2]);
		}

		printf("[1]추가\n");
		printf("[2]삭제\n");

		printf("메뉴 선택 : ");
		int choice = 0;
		scanf_s("%d", &choice);

		if (choice == 1) {
		}
		else if (choice == 2) {
		}
	}

	system("pause");
}
