#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# OMR카드[구조체(변수+함수) 변경]

예)
omr = [1, 3, 4, 2, 5]
hgd = [1, 1, 4, 2, 3]

문제 1) 1~5 사이의 랜덤 숫자 5개 저장
정답 1) [1, 1, 4, 2, 3]

문제 2) omr과 hgd을 비교해 정답은 1, 오답은 0으로 배열에 저장해 출력
정답 2) [1, 0, 1, 1, 0]

문제 3) 문제2를 통해 저장된 배열로 정오표 출력
정답 3) O, X, O, O, X

문제 4) 성적 출력
정답 4) 60점

*/
// 불러 쓰는 함수들이 모두 변수를 담고있는 구조체 struct OMR  내부에 들어있음을 유의하자 !! 구조체 한개임 이문제는

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
		hgd = new int[count];			// 방 먼저 파주고
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

	//문제 1) 1~5 사이의 랜덤 숫자 5개 저장
	//정답 1)[1, 1, 4, 2, 3]
	printf(">>>문제 1\n");
	m.test1();
	printf("\n");

	//문제 2) omr과 hgd을 비교해 정답은 1, 오답은 0으로 배열에 저장해 출력
	//정답 2)[1, 0, 1, 1, 0]
	printf(">>>문제 2\n");
	int* tmp = m.test2();
	m.print_arr(tmp);
	printf("\n");

	//문제 3) 문제2를 통해 저장된 배열로 정오표 출력
	//정답 3) O, X, O, O, X
	printf(">>>문제 3\n");
	m.test3();
	printf("\n");

	//문제 4) 성적 출력
	//정답 4) 60점
	printf(">>>문제 4\n");
	int score = m.test4();
	printf("성적 = %d점\n", score);
	printf("\n");


	system("pause");
}
