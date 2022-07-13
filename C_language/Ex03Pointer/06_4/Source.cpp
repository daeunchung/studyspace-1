#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# OMR카드[함수로 변경]

예)
omr = [1, 3, 4, 2, 5]
hgd = [1, 1, 4, 2, 3]

문제 1) 1~5 사이의 랜덤 숫자 5개 저장
정답 1) [1, 1, 4, 2, 3]

문제 2) omr과 hgd을 비교해 정답은 1, 오답은 0으로 저장해 배열 리턴
정답 2) [1, 0, 1, 1, 0]

문제 3) 문제2를 통해 리턴받은 배열로 정오표 출력
정답 3) O, X, O, O, X

문제 4) 성적 리턴
정답 4) 60점

*/

//	C는 절차지향적 언어(Procedural) 이니까 ~
// main 보다 앞에 함수 '선언'만
void print_arr(int* p, int count);
void test1(int* hgd, int count);
int* test2(int* omr, int* hgd, int count);
void test3(int* omr, int* hgd, int count);
int test4(int* omr, int* hgd, int count);

void main() {
	srand(time(0));		// 굳이 왜 써주는건지 ..

	int count = 5;

	int omr[5] = { 1, 3, 4, 2, 5 };
	int hgd[5] = { 0 };


	printf(">>>문제 1\n");
	test1(&hgd[0], count);

	print_arr(omr, count);
	print_arr(hgd, count);
	printf("\n");

	printf(">>>문제 2\n");
	int* p = test2(&omr[0], &hgd[0], count);
	print_arr(p, count);
	printf("\n");

	printf(">>>문제 3\n");
	test3(&omr[0], &hgd[0], count);
	printf("\n");

	printf(">>>문제 4\n");
	int score = test4(&omr[0], &hgd[0], count);
	printf("%d점\n", score);
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
	int* answer = new int[count];		// C에서는 컴파일 에러나고 .cpp 로 만들어야만 돌아간다
										// new 키워드 자체가 객체 생성인데 C는 객체지향언어 X
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
	int* answer = test2(&omr[0], &hgd[0], count);	// 새로운 지역변수에 test2 실행값 넣어주기

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