#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# 중복숫자 금지[구조체(변수+함수) 변경]
1~10 사이의 랜덤 숫자 5개를
arr배열에 중복없이 저장하기
*/

struct Number {
	int count;
	int* p;

	void set_num() {
		for (int i = 0; i < count; i++) {
			int r = rand() % 10 + 1;
			p[i] = r;

			int check = 1;
			// 나보다 앞에 놈들 중에 내가 방금 받은 수가 있는지 확인합시다.
			for (int j = 0; j < i; j++) {
				if (p[j] == p[i]) {
					check = -1;
				}
			}
			if (check == -1) { i -= 1; }	// for문 증가 빠꾸 ~
		}
	}

	void init() {			// 방터주기 함수
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

	srand(time(0));			// 매 초 다른값 나오라 ~
	Number n = { 0 };
	n.run();
	system("pause");

}
