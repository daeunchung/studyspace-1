#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# OMRī��[����ü(����) ����]

��)
omr = [1, 3, 4, 2, 5]
hgd = [1, 1, 4, 2, 3]

���� 1) 1~5 ������ ���� ���� 5�� ����
���� 1) [1, 1, 4, 2, 3]

���� 2) omr�� hgd�� ���� ������ 1, ������ 0���� �迭�� ������ ���
���� 2) [1, 0, 1, 1, 0]

���� 3) ����2�� ���� ����� �迭�� ����ǥ ���
���� 3) O, X, O, O, X

���� 4) ���� ���
���� 4) 60��

*/

struct OMR {
	int count;
	int* answer;
	int* hgd;
};

void main() {

	srand(time(0));

	OMR m = { 0 };
	m.count = 5;

	m.answer = new int[m.count];
	m.answer[0] = 1;
	m.answer[1] = 3;
	m.answer[2] = 4;
	m.answer[3] = 2;
	m.answer[4] = 5;

	m.hgd = new int[m.count];
	//m.hgd = (int)malloc(sizeof(int)*m.count);

	printf("����1) �������� 5�� ����\n");
	for (int i = 0; i < m.count; i++) {
		m.hgd[i] = rand() % 5 + 1;
	}
	printf("\n");

	printf("����2) omr�� hgd�� ���� ������ 1, ������ 0���� �迭�� ������ ���\n");
	//int* tmp = (int*)malloc(sizeof(int)*m.count);
	 int* tmp = new int[m.count];
	for (int i = 0; i < m.count; i++) {
		if (m.answer[i] == m.hgd[i]) {
			tmp[i] = 1;
		}
		else{
			tmp[i] = 0;
		}
	}

	printf("[ ");
	for (int i = 0; i<m.count; i++) {
		printf("%d ", tmp[i]);
	}
	printf("]\n");
	printf("\n");



	printf("����3) ������ O, ������ X \n");
	printf("[ ");
	for (int i = 0; i<m.count; i++) {
		if (tmp[i] == 1) {
			printf(" O ");
		}
		else if (tmp[i] == 0) {
			printf(" X ");
		}
	}
	printf("]\n");
	printf("\n");


	printf("����4) ������� \n");
	int cnt = 0;
	for (int i = 0; i<m.count; i++) {
		if (tmp[i] == 1) {
			cnt += 1;
		}
	}
	int score = cnt * 20;
	printf("���� = %d��\n", score);
	printf("\n");

	system("pause");
}
