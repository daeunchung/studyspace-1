#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# OMRī��[����ü(����+�Լ�) ����]

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
// �ҷ� ���� �Լ����� ��� ������ ����ִ� ����ü struct OMR  ���ο� ��������� �������� !! ����ü �Ѱ��� �̹�����

struct OMR {
	int count;
	int* answer;
	int* hgd;

	void init() {
		count = 5;
		answer = new int[count];
		answer[0] = 1;
		answer[1] = 3;
		answer[2] = 4;
		answer[3] = 2;
		answer[4] = 5;
	}

	void print_arr(int* p) {
		printf("[ ");
		for (int i = 0; i<count; i++) {
			printf("%d ", p[i]);
		}
		printf("]\n");
	}

	void test1() {
		hgd = new int[count];			// �� ���� ���ְ�
		for (int i = 0; i < count; i++) {
			hgd[i] = rand() % 5 + 1;
		}
		print_arr(hgd);
	}

	int* test2() {
		int* tmp = new int[count];
		for (int i = 0; i < count; i++) {
			if (hgd[i] == answer[i]) {
				tmp[i] = 1;
			}
			else if (hgd[i] != answer[i]) {
				tmp[i] = 0;
			}
		}
		return tmp;
	}

	void test3() {
		int* tmp = test2();
		printf("[ ");
		for (int i = 0; i < count; i++) {
			if (tmp[i] == 1) { printf(" O "); }
			else if (tmp[i] == 0) { printf(" X "); }
		}
		printf("]\n");
	}

	int test4() {
		int* tmp = test2();
		int cnt = 0;
		for (int i = 0; i < count; i++) {
			if (tmp[i] == 1) {
				cnt += 1;
			}
		}
		int score = cnt * 20;
		return score;
	}


};

void main() {
	srand(time(0));
	OMR m = { 0 };
	m.init();

	//omr = [1, 3, 4, 2, 5]
	//hgd = [1, 1, 4, 2, 3]

	//���� 1) 1~5 ������ ���� ���� 5�� ����
	//���� 1)[1, 1, 4, 2, 3]
	printf(">>>���� 1\n");
	m.test1();
	printf("\n");

	//���� 2) omr�� hgd�� ���� ������ 1, ������ 0���� �迭�� ������ ���
	//���� 2)[1, 0, 1, 1, 0]
	printf(">>>���� 2\n");
	int* tmp = m.test2();
	m.print_arr(tmp);
	printf("\n");

	//���� 3) ����2�� ���� ����� �迭�� ����ǥ ���
	//���� 3) O, X, O, O, X
	printf(">>>���� 3\n");
	m.test3();
	printf("\n");

	//���� 4) ���� ���
	//���� 4) 60��
	printf(">>>���� 4\n");
	int score = m.test4();
	printf("���� = %d��\n", score);
	printf("\n");


	system("pause");
}
