#include <Windows.h>
#include <stdio.h>

void test(int n);
void main() {
	//재귀함수 --> 함수를 이용해서 반복문 표현
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