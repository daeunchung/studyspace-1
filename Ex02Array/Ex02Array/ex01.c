#include <Windows.h>
#include <stdio.h>
/*
# 배열(array)
[1] 선언
1) int 변수명[개수];
2) int arr[5];			변수 5개를 한꺼번에 할당받는다.
[2] 사용
1) 배열은 0부터 방의 개수만큼 1씩 증가하면서 방이 생성된다.
2) 이때 방번호(index)를 사용한다.
예) arr[0] = 10;		arr[1] = 20;
3) 반복문을 사용해 효과적으로 이용할 수 있다.
*/

void main() {

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;

	//--------------------

	int arr[5];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i<5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//--------------------
	// 배열 축약형 : 처음 한번만 작성 가능
	int sc[5] = { 10, 20, 30, 40, 50 };
	for (int i = 0; i<5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//system("pause");

	int ar[5] = { 0 };	// 5개의 방을 모두 0으로 초기화
	ar[0] = 10;
	ar[1] = 20;
	ar[2] = 30;
	ar[3] = 40;
	ar[4] = 50;

	//문제1) 배열의 전체 합출력 
	//정답1) 150
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += ar[i];
	}printf("%d\n", total);

	//문제2) 4의 배수만 출력 
	//정답2) 20 40
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 4 == 0) {
			printf("%d ", ar[i]);
		}
	}printf("\n");

	//문제3) 4의 배수의 합 출력
	//정답3) 60
	total = 0;
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 4 == 0) {
			total += ar[i];
		}
	}printf("%d\n", total);

	//문제4) 4의 배수의 개수 출력
	//정답4) 2
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 4 == 0) {
			cnt++;
		}
	}printf("%d\n", cnt);

	//문제5) 짝수의 개수 출력
	//정답5) 5
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 2 == 0) {
			cnt++;
		}
	}printf("%d\n", cnt);
	system("pause");



	// --------------------------------- OMR 카드 [문제] ------------------------------------
	srand(time(0));

	int omr[] = { 1, 5, 3, 2, 5 }; // 모범 답안
	int me[5] = { 0 };			 // 학생 답안

	//문제1) me에 1~5 사이의 랜덤 숫자를 5개 저장 후,
	//       omr과 비교하여 점수출력 (1문제당 20점)
	//문제2) 맞으면 "o", 틀리면 "x" 출력 
	int score = 0;
	for (int i = 0; i < 5; i++) {
		me[i] = rand() % 5 + 1;

		if (omr[i] == me[i]) {
			printf("o ");
			score += 20;
		}
		else {
			printf("x ");
		}
	}
	printf("\n");
	printf("점수 : %d", score);		printf("\n");

	system("pause");


	// ---------------------------- 학번 입력 [문제] -------------------------------------------------
	int scores[5] = { 10 ,   20,   60 ,  40,   3 };
	int num[5] = { 1001, 1002, 1003, 1004, 1005 };

	//문제1) 성적이 60점 이상이면 합격. 합격생 수 출력.
	//정답1) 1명
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (scores[i] >= 60) {
			cnt++;
		}
	}printf("%d명\n", cnt);

	//문제2) 학번을 입력하면 점수 출력 
	//정답2) 1001 ==> 10
	int sn;
	printf("학번을 입력하시오\n");
	scanf_s("%d", &sn); 
	for (int i = 0; i < 5; i++) {
		if (num[i] == sn) {
			printf("%d점\n", scores[i]);
		}
	}
	//문제3) 성적을 입력받아 방번호(index) 출력
	//정답3) 60 ==> 1003
	int ss;
	printf("성적을 입력하시오\n");
	scanf_s("%d", &ss);
	for (int i = 0; i < 5; i++) {
		if (scores[i] == ss) {
			printf("%d번\n", num[i]);
		}
	}

	//문제4) 없는 학번을 입력하면 "없다"라고 출력
	//정답4) 1006 ==> "없다"
	int y = -1;
	printf("학번을 입력하시오\n");
	scanf_s("%d", &sn);
	for (int i = 0; i < 5; i++) {
		if (num[i] == sn) {
			y = 1;
		}
	}
	if (y == -1) {
		printf("없는 학번 입니다");	printf("\n");
	}
	else {
		printf("학번이 존재한다.");	printf("\n");
	}

	//문제5) 1등학생의 학번과 성적 출력
	//정답5) 1003학번(60점)
	int max = 0; int maxsn;
	for (int i = 0; i < 5; i++) {
		if (max < scores[i]) {
			max = scores[i];
			maxsn = i;
		}
	}
	printf("1등 학생 : %d (%d점)\n", num[maxsn], scores[maxsn]);

	system("pause");





	// ----------------------------------- 당첨 복권 [문제] ------------------------------------
	int lotto[] = { 3, 0, 3, 3, 3, 3, 0 };
	// 문제) 위 복권이 당첨인지 아닌지 출력 
	// 조건) 3이 연속으로 3개이상이면 당첨 
	 y = -1;
	for (int i = 0; i < 5; i++) {
		if (lotto[i] == 3 && lotto[i + 1] == 3 && lotto[i + 2] == 3)
			y = 1;
	}

	if (y == 1) { printf("당첨");  printf("\n"); }
	else { printf("꽝"); printf("\n"); }
	system("pause");
}
