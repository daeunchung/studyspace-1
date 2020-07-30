#include <Windows.h>
#include <stdio.h>

void main() {
	//	----------------------------------  숫자이동 [문제]  ------------------------------
	// 1 ==> 플레이어
	// 2 ==> 벽
	// 0 ==> 길

	// 1) 1을 누르면 왼쪽으로 이동 
	// 2) 2를 누르면 오른쪽으로이동 
	// 3) 벽은 지나가지못한다.

	int game[9] = { 2, 0, 0, 0, 0, 0, 1, 0, 2 };

	while (1) {
		int i = 0;
		while (i < 9) {
			if (game[i] == 0) {
				printf("__");
			}
			else if (game[i] == 1) {
				printf("옷");
			}
			else if (game[i] == 2) {
				printf("[]");
			}
			i = i + 1;
		}
		printf("\n");

		printf("[1.left] [2.right]를 입력하세요 : ");
		int move = 0;
		scanf("%d", &move);
		if (move == 1) {}
		else if (move == 2) {}

	}

	system("pause");

	//	----------------------------------  숫자이동(심화) [문제]  ------------------------------
	// 1 ==> 플레이어
	// 2 ==> 벽
	// 0 ==> 길

	// 1) 1을 누르면 왼쪽으로 이동 
	// 2) 2를 누르면 오른쪽으로이동 
	// 3) 벽은 지나가지못한다.
	// ----------------------------------------
	// 4) 3을 누르면 벽을 격파할 수 있다.

	int game[9] = { 0, 0, 2, 0, 2, 0, 1, 0, 2 };

	while (1) {
		int i = 0;
		while (i < 9) {
			if (game[i] == 0) {
				printf("__");
			}
			else if (game[i] == 1) {
				printf("옷");
			}
			else if (game[i] == 2) {
				printf("[]");
			}
			i = i + 1;
		}
		printf("\n");

		printf("[1.left] [2.right] [3.punch] 를 입력하세요 : ");
		int move = 0;
		scanf("%d", &move);
		if (move == 1) {}
		else if (move == 2) {}

	}

	system("pause");



	//	----------------------------------  윷놀이 [문제]  ------------------------------
	/*
	# 미니 윷놀이
	1. p1은 숫자1, p2는 숫자2로 표현한다.
	2. 숫자 1~5를 입력하면 해당 숫자만큼 오른쪽으로 이동
	3. p1과 p2는 번갈아 가면서 플레이
	4. 잡게되면 잡힌쪽의 인덱스는 -1로 변경(처음으로 되돌아간다)
	*/

	int p1arr[15] = { 0 };
	int p2arr[15] = { 0 };
	int p1 = 0;
	int p2 = 0;
	int turn = 0;

	p1arr[p1] = 1;
	p2arr[p2] = 2;
	while (1) {
		int i = 0;
		i = 0;
		while (i < 15) {
			printf("%d ", p1arr[i]);
			i += 1;
		}

		printf("\n");
		i = 0;
		while (i < 15) {
			printf("%d ", p2arr[i]);
			i += 1;
		}
		printf("\n");
		int sel;
		scanf_s("%d", &sel);

		if (turn == 0) {}
		else if (turn == 1) {}
	}

	system("pause");



	//	----------------------------------  값교체 [문제]  ------------------------------
	int arr[5] = { 10, 20, 30, 40, 50 };
	//문제1) 인덱스 2개를 입력받고 교환 
	//       1, 3   ==> 10 , 40 , 30 , 20, 50
	int i1 = 0;
	int i2 = 0;

	system("pause");


	//	----------------------------------  최대값 [문제]  ------------------------------
	// 가장 큰값 찾기

	//문제1 ) 1등 번호 출력 ==> 1004
	int num[5] = { 1001, 1002, 1003, 1004, 1005 };
	int score[5] = { 10, 140, 60, 220 , 15 };
	int max_val;
	max_val = score[0];
	//if(max_val < score[1]){
	//	max_val = score[1];
	//}
	//if(max_val < score[2]){
	//	max_val = score[2];
	//}
	//if(max_val < score[3]){
	//	max_val = score[3];
	//}
	//if(max_val < score[4]){
	//	max_val = score[4];
	//}
	int n = 0; int max_index = 0;
	while (n < 5) {
		if (max_val < score[n]) {
			max_val = score[n];
			max_index = n;
		}
		n += 1;
	}
	printf("max ===> %d", max_val); printf("\n");

	system("pause");


	//	----------------------------------  성적관리 [문제]  ------------------------------
	int num[100]; // 번호는 10000 부터 시작 
	int score[100];
	int count = 0;

	// 성적을 입력받고 추가 해보자// count 로 제어 
	// 성적을 입력받을때마다 카운트를 증가시키고 카운트 숫자만큼만 출력 한다. 

	// == 학생 점수 관리 프로그램 ==
	// 1. 추가// 2. 출력// 3. 삭제 
	while (1) {
		printf("== 학생 점수 관리 프로그램 =="); printf("\n");
		printf("1.추가 2.출력 3.삭제 "); printf("\n");
		int sel;
		scanf("%d", &sel);
		if (sel == 1) {}
		else if (sel == 2) {}
		else if (sel == 3) {}
	}

	system("pause");



}