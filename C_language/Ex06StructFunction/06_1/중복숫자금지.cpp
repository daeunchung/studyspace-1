#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# �ߺ����� ����[����ü(����+�Լ�) ����]
1~10 ������ ���� ���� 5����
arr�迭�� �ߺ����� �����ϱ�
*/

struct Number {
	int count;
	int* p;

	void set_num() {
		for (int i = 0; i < count; i++) {
			int r = rand() % 10 + 1;
			p[i] = r;

			int check = 1;
			// ������ �տ� ��� �߿� ���� ��� ���� ���� �ִ��� Ȯ���սô�.
			for (int j = 0; j < i; j++) {
				if (p[j] == p[i]) {
					check = -1;
				}
			}
			if (check == -1) { i -= 1; }	// for�� ���� ���� ~
		}
	}

	void init() {			// �����ֱ� �Լ�
		count = 5;
		p = new int[count];
	}

	void print_arr() {
		for (int i = 0; i < count; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
	}

	void run() {
		init();
		set_num();
		print_arr();
	}
};

void main() {

	srand(time(0));			// �� �� �ٸ��� ������ ~
	Number n = { 0 };
	n.run();
	system("pause");

}
