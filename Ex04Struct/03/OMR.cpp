#include <Windows.h>
#include <stdio.h>
#include <time.h>

/*
# OMR카드[구조체(변수) 변경]

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

struct OMR {
	int count;
	int* answer;
	int* hgd;
};

void main() {

	srand(time(0));

	OMR m = { 0 };
	m.count = 5;

	m.answer = new int[m.count];
	m.answer[0] = 1;
	m.answer[1] = 3;
	m.answer[2] = 4;
	m.answer[3] = 2;
	m.answer[4] = 5;

	m.hgd = new int[m.count];
	//m.hgd = (int)malloc(sizeof(int)*m.count);

	printf("문제1) 랜덤숫자 5개 저장\n");
	for (int i = 0; i < m.count; i++) {
		m.hgd[i] = rand() % 5 + 1;
	}
	printf("\n");

	printf("문제2) omr과 hgd을 비교해 정답은 1, 오답은 0으로 배열에 저장해 출력\n");
	//int* tmp = (int*)malloc(sizeof(int)*m.count);
	 int* tmp = new int[m.count];
	for (int i = 0; i < m.count; i++) {
		if (m.answer[i] == m.hgd[i]) {
			tmp[i] = 1;
		}
		else{
			tmp[i] = 0;
		}
	}

	printf("[ ");
	for (int i = 0; i<m.count; i++) {
		printf("%d ", tmp[i]);
	}
	printf("]\n");
	printf("\n");



	printf("문제3) 정답은 O, 오답은 X \n");
	printf("[ ");
	for (int i = 0; i<m.count; i++) {
		if (tmp[i] == 1) {
			printf(" O ");
		}
		else if (tmp[i] == 0) {
			printf(" X ");
		}
	}
	printf("]\n");
	printf("\n");


	printf("문제4) 성적출력 \n");
	int cnt = 0;
	for (int i = 0; i<m.count; i++) {
		if (tmp[i] == 1) {
			cnt += 1;
		}
	}
	int score = cnt * 20;
	printf("성적 = %d점\n", score);
	printf("\n");

	system("pause");
}
