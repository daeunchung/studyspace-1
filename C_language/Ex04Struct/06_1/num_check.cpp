#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# �ߺ����� ����[����ü(����) ����]
1~10 ������ ���� ���� 5����
arr�迭�� �ߺ����� �����ϱ�
*/

struct Number {
	int count;
	int* p;
};

void main() {

	srand(time(0));

	Number n = { 0 };

	n.count = 5;
	n.p = new int[n.count];

	for (int i = 0; i < n.count; i++) {
		n.p[i] = rand() % 10 + 1;

		int check = 1;
		for (int j = 0; j < i; j++) {
			if (n.p[j] == n.p[i]) {
				check = -1;
			}
		}
		if (check == -1) { i--; }
	}

	printf("�ߺ����ڱ���\n");
	for (int i = 0; i < n.count; i++) {
		printf("%d ", n.p[i]);
	}
	printf("\n");

	system("pause");

}
