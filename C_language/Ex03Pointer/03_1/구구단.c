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
			printf("����\n");
			p[0] += 1;
			// (*p) += 1;
		}
		else {
			printf("����\n");
		}
	}
}

void main() {

	srand(time(0));

	// ����) �������� 3���� �����ϰ� �����ϰ�, ������ ���� ��� 

	int c = 0;
	gugudan(&c);

	printf("���䰳�� : %d", c); printf("\n");

	system("pause");
}
