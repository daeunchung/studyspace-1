#include <Windows.h>
#include <stdio.h>

void test(int **pp) {
	pp[0] = new int[3];
	/*	���� ������ pp�� : ������������ �ּҰ�
		pp[0] �� : ���������� ���� ���빰 ( ���������Ͱ� ����Ű�� �ּ� )

									(int a = 10; int* p = &a; int* pp = &p; �϶� a�� �ּ�)	*/
}

void main() {
	int* p = new int[3];		// �迭�� �ּҸ� ������ p�� ����
	int* p1 = 0;
	int ** pp = &p1; 

	pp[0] = new int[3];			// �迭�� �ּҸ� ������ pp�� ����Ű�� �ּ�
	pp[0][0] = 10;
	p1[0] = 200;
	printf("%d\n", pp[0][0]);

	// -------------------------------

	int* p2 = 0;
	test(&p2);
	delete[] p2;

	system("pause");
}