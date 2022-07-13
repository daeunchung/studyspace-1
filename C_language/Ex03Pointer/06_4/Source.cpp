#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# OMRī��[�Լ��� ����]

��)
omr = [1, 3, 4, 2, 5]
hgd = [1, 1, 4, 2, 3]

���� 1) 1~5 ������ ���� ���� 5�� ����
���� 1) [1, 1, 4, 2, 3]

���� 2) omr�� hgd�� ���� ������ 1, ������ 0���� ������ �迭 ����
���� 2) [1, 0, 1, 1, 0]

���� 3) ����2�� ���� ���Ϲ��� �迭�� ����ǥ ���
���� 3) O, X, O, O, X

���� 4) ���� ����
���� 4) 60��

*/

//	C�� ���������� ���(Procedural) �̴ϱ� ~
// main ���� �տ� �Լ� '����'��
void print_arr(int* p, int count);
void test1(int* hgd, int count);
int* test2(int* omr, int* hgd, int count);
void test3(int* omr, int* hgd, int count);
int test4(int* omr, int* hgd, int count);

void main() {
	srand(time(0));		// ���� �� ���ִ°��� ..

	int count = 5;

	int omr[5] = { 1, 3, 4, 2, 5 };
	int hgd[5] = { 0 };


	printf(">>>���� 1\n");
	test1(&hgd[0], count);

	print_arr(omr, count);
	print_arr(hgd, count);
	printf("\n");

	printf(">>>���� 2\n");
	int* p = test2(&omr[0], &hgd[0], count);
	print_arr(p, count);
	printf("\n");

	printf(">>>���� 3\n");
	test3(&omr[0], &hgd[0], count);
	printf("\n");

	printf(">>>���� 4\n");
	int score = test4(&omr[0], &hgd[0], count);
	printf("%d��\n", score);
	printf("\n");

	system("pause");
}


void print_arr(int* p, int count) {
	printf("[ ");
	for (int i = 0; i < count; i++) {
		printf("%d ", p[i]);
	}
	printf("]\n");
}

void test1(int* hgd, int count) {
	for (int i = 0; i < count; i++) {
		hgd[i] = rand() % 5 + 1;
	}
}

int* test2(int* omr, int* hgd, int count) {
	int* answer = new int[count];		// C������ ������ �������� .cpp �� �����߸� ���ư���
										// new Ű���� ��ü�� ��ü �����ε� C�� ��ü������ X
	for (int i = 0; i<count; i++) {
		if (omr[i] == hgd[i]) {
			answer[i] = 1;
		}
		if (omr[i] != hgd[i]) {
			answer[i] = 0;
		}
	}
	return answer;
}

void test3(int* omr, int* hgd, int count) {
	int* answer = test2(&omr[0], &hgd[0], count);	// ���ο� ���������� test2 ���ప �־��ֱ�

													// int* answer = test2(omr, hgd, count);
	printf("[ ");
	for (int i = 0; i < count; i++) {
		if (answer[i] == 1) {
			printf("O ");
		}
		else if (answer[i] == 0) {
			printf("X ");
		}
	}
	printf("]\n");

}

int test4(int* omr, int* hgd, int count) {
	int* answer = test2(&omr[0], &hgd[0], count);
	int cnt = 0;
	for (int i = 0; i < count; i++) {
		if (answer[i] == 1) { cnt++; }
	}
	return cnt * 20;
}