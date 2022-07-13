#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# 중복숫자 금지[구조체(변수) 변경]
1~10 사이의 랜덤 숫자 5개를
arr배열에 중복없이 저장하기
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

	printf("중복숫자금지\n");
	for (int i = 0; i < n.count; i++) {
		printf("%d ", n.p[i]);
	}
	printf("\n");

	system("pause");

}
