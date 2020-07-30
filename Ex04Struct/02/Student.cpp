#include <Windows.h>
#include <stdio.h>

/*
# 학생 성적관리 프로그램[구조체(변수) 변경]

예)
학번 = [1001, 1002, 1003, 1004, 1005]
성적 = [  60,  100,   73,    3,   81]

문제 1) 1~100 사이의 랜덤 숫자 5개 저장
정답 1) [60, 100, 73, 3, 81]

문제 2) 전교생의 정보 출력

문제 3) 전교생의 총점 출력
정답 3) 총점(317점)

문제 4) 전교생의 평균 출력
정답 4) 평균(63.4점)

문제 5) 합격생(성적 75점이상)의 학번과 성적 출력
정답 5) 1002학번(100점), 1005학번(81점)

문제 6) 1등 학생의 학번과 성적 출력
정답 6) 1002학번(100점)

문제 7) 학번을 입력받아 성적 출력
문제 8) 성적을 입력받아 학번 출력

문제 9) 학번을 입력받아 학생정보(학번과 성적) 삭제
조건 9) 없는 학번 입력 시, 예외처리

문제 10) 성적순으로 내림차순 정렬

*/

struct Student {
	int hakbun;
	int score;
};

struct Control {
	Student* p;
	int count;
};

void main() {

	Control c = { 0 };

	c.count = 5;
	c.p = new Student[5];

	for (int i = 0; i<c.count; i++) {
		c.p[i].hakbun = 1001 + i;

	}

	printf(">>>문제 1\n");
	for (int i = 0; i < c.count; i++) {
		c.p[i].score = rand() % 100 + 1;
	}
	printf("\n");
	
	printf(">>>문제 2\n");
	for (int i = 0; i < c.count; i++) {
		printf("%d학번(%d점) ", c.p[i].hakbun, c.p[i].score);
	}
	printf("\n");


	printf(">>>문제 3\n");
	int total = 0;
	for (int i = 0; i < c.count; i++) {
		total = c.p[i].score;
	}
	printf("총점 : %d점\n", total);
	printf("\n");


	printf(">>>문제 4\n");
	float avg = total / (float)c.count;
	printf("평균 : %.1f점\n", avg);
	printf("\n");


	printf(">>>문제 5\n");
	for (int i = 0; i < c.count; i++) {
		if (c.p[i].score >= 75) {
			printf("%d학번(%d점) ", c.p[i].hakbun, c.p[i].score);
		}
	}
	printf("\n");


	printf(">>>문제 6\n");
	int max = 0; int max_idx;

	for (int i = 0; i < c.count; i++) {
		if (max < c.p[i].score ) {
			max = c.p[i].score;
			max_idx = i;
		}
	}
	printf("%d학번(%d점) ", c.p[max_idx].hakbun, max );
	printf("\n");


	printf(">>>문제 7\n");
	printf("학번 입력 : ");
	int sNum = 0; int sIdx = -1;
	scanf_s("%d", &sNum);
	for (int i = 0; i < c.count; i++) {
		if (c.p[i].hakbun == sNum ) {
			sIdx = i;
			printf("%d학번(%d점) ", c.p[sIdx].hakbun, c.p[sIdx].score);
			break;
		}
	}

	if (sIdx == -1) {
		printf("해당 학번이 존재하지 않습니다.\n");
	}
	printf("\n");
	



	printf(">>>문제 8\n");
	printf("성적 입력 : ");
	int sScore = 0;  
	sIdx = -1;
	scanf_s("%d", &sScore);
	for (int i = 0; i < c.count; i++) {
		if (c.p[i].score == sScore) {
			sIdx = i;
			printf("%d학번(%d점) ", c.p[sIdx].hakbun, c.p[sIdx].score);
			break;
		}
	}

	if (sIdx == -1) {
		printf("해당 점수를 가진 학생이 존재하지 않습니다.\n");
	}
	printf("\n");


	printf(">>>문제 9\n");
	printf("삭제할 학생의 학번 입력 : ");
	int del = 0;
	scanf_s("%d", &del);

	int delete_idx = -1;
	for (int i = 0; i < c.count; i++) {
		if (del == c.p[i].hakbun) {
			delete_idx = i;
		}
	}

	if (delete_idx == -1) {
		printf("학번을 잘못 입력하셨습니다.\n");
	}
	else {
		// [3]포인터와함수 [08]학생관리에서 처럼 배열 칸수 증감하면서 방을 파주지 않고 그냥 size[5] 짜리 배열크기 유지하면서 주소값만 옮겨주네

		// 의문. ! main시작부에 
		// c.p = new Student[c.count]; 
		// c.count = 5; 는 불가능한걸까 ? 

		for (int i = delete_idx; i < c.count - 1; i++) {
			c.p[i].hakbun = c.p[i + 1].hakbun;
			c.p[i].score = c.p[i + 1].score;
		}
		c.count--;
	}
	for (int i = 0; i<c.count; i++) {
		printf("%d학번(%d점) ", c.p[i].hakbun, c.p[i].score);
	}
	printf("\n");
	printf("\n");


	
	// 문제 10 ) 성적순으로 내림차순 정렬

	// 2차원배열 내림차순 정렬 생각해보면됌 : 나(i) 보다 뒤에있는 놈들 중 나(i) 보다 값이 큰놈들을 앞쪽으로
	printf(">>>문제 10\n");

	//for (int i = 0; i < c.count; i++) {
	//	for (int j = i; j < c.count; j++) {
	//		if (c.p[i].score < c.p[j].score) {

	//			int* tmp = (int*)malloc(sizeof(Student) * 1);
	//			// 구조체 struct 의 주소를 담는 포인터주소를 하나 파서 그 방을 통해서 
	//			// i 와 j 의 구조체 주소자체를 교환하는 식으로 짜고싶..은데 잘안되네 ㅍ,ㅍ ㅠㅠ..
	//		    tmp = c.p[i];
	//			c.p[i] = c.p[j];
	//			c.p[j] = tmp;
	//		}
	//	}
	//}

	for (int i = 0; i < c.count; i++) {
		int max_score = c.p[i].score;
		int max_idx = i;
		for (int j = i; j < c.count; j++) {
			if (max_score < c.p[j].score) {
				max_score = c.p[i].score;
				max_idx = j;
			}
		}

		int tmp = c.p[i].score;
		c.p[i].score = c.p[max_idx].score;
		c.p[max_idx].score = tmp;

		 tmp = c.p[i].hakbun;
		c.p[i].hakbun = c.p[max_idx].hakbun;
		c.p[max_idx].hakbun = tmp;
	}

	for (int i = 0; i < c.count; i++) {
		printf("%d학번(%d점) ", c.p[i].hakbun, c.p[i].score);
	}

	printf("\n");
	printf("\n");


	system("pause");

}
