#include <Windows.h>
#include <stdio.h>

void test(int n);
void main() {
	//����Լ� --> �Լ��� �̿��ؼ� �ݺ��� ǥ��
	test(4);
	system("pause");
}
void test(int n) {
	printf("%d", n); printf("\n");
	if (n > 0) {
		test(n - 1);
	}
	//printf("%d", n); printf("\n");
}