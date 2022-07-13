#include <Windows.h>
#include <stdio.h>

/*
# 배열 기본문제[구조체(변수+함수) 변경]
문제 1) 전체 합 리턴
정답 1) 150

문제 2) 4의 배수만 구조체에 저장해 리턴
정답 2) 20 40

문제 3) 4의 배수의 합 리턴
정답 3) 60

문제 4) (인덱스로)값 교체
문제 5) (값으로)값 교체
*/
struct Test{
	int* p;
	int size;
};

struct Array {

	int count;
	int* arr;

	// 구조체 선언하면서 안에 배열속 값도 넣어주는 함수를 넣어줬네.
	// 이 문제에서는 구조체 안에 함수를 만들고 호출하는 연습을 시키나봄
	void init() {													// 값 넣어주기
		count = 5;
		arr = new int[count];
		for (int i = 0; i<count; i++) {
			arr[i] = (i + 1) * 10;
		}
	}

	void print_arr() {												// 값 출력하기
		printf("[ ");
		for (int i = 0; i < count; i++) {
			printf("%d ", arr[i]);
		}
		printf("]\n");	
	}

	int test1() {
		int total = 0;
		for (int i = 0; i < count; i++) {
			total += arr[i];
		}
		return total;
	}

	// ** 구조체에 저장하랬으니 반환타입이 구조체 **
	Test test2() {
		int size = 0;
		for (int i = 0; i < count; i++) {		// size 값 구하기위한 for문
			if (arr[i] % 4 == 0) {
				size += 1;
			}
		}

		Test t = { 0 };
		t.size = size;
		t.p = new int[size];

		int j = 0;
		for (int i = 0; i < count; i++) {		// 구조체 Test 속 배열에 값 넣어주기위한 for문
			if (arr[i] % 4 == 0) {
				t.p[j] = arr[i];
				j += 1;
			}
		}
		return t;
	}

	int test3() {
		int total = 0;
		for (int i = 0; i < count; i++) {
			if (arr[i] % 4 == 0) {
				total += arr[i];
			}
		}
		return total;
	}

	void test4(int idx1, int idx2) {
		int tmp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = tmp;
	}
	
	void test5(int value1, int value2) {
		int idx1 = 0;
		int idx2 = 0;
		for (int i = 0; i < count; i++) {
			if (value1 == arr[i]) { idx1 = i; }
			if (value2 == arr[i]) { idx2 = i; }
		}

		int tmp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = tmp;
	}
};

void main() {

	Array a = { 0 };
	a.init();


	printf(">>> 문제 1\n");
	int total = a.test1();
	printf("total = %d\n", total);
	printf("\n");

	printf(">>> 문제 2\n");
	Test t = a.test2();
	for (int i = 0; i < t.size; i++) {
		printf("%d ", t.p[i]);
	}
	printf("\n");
	printf("\n");

	printf(">>> 문제 3\n");
	total = a.test3();
	printf("total = %d\n", total);
	printf("\n");

	printf(">>> 문제 4\n");
	a.test4(1, 4);
	a.print_arr();
	printf("\n");

	printf(">>> 문제 5\n");
	a.test5(20, 50);
	a.print_arr();
	printf("\n");

	system("pause");
}
