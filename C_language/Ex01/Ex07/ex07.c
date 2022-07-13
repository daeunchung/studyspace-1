#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 반복문 종류 2가지 // 1)초기식 2)조건식 3)증감식 
// 1) while
// 2) for   // 증감식은;(세미콜론)이 없다.

void main() {

	//증감식 모양 4종류 
	// a = a + 1;
	// a += 1;
	// a++;
	// ++a;

	int n = 0;    // 초기식 
	while (n < 4) {  // 조건식
		printf("%d", n);
		n = n + 1;  // 증감식 
	}
	printf("\n");
	for (int i = 0; i < 4; i = i + 1) {
		printf("%d", i);
	}
	printf("\n");

	system("pause");

	//	랜덤학생점수 [문제]
	srand(time(0));
	// 1)랜덤학생점수 2)쇼핑몰 3)베스킨라빈스
	// 랜덤학생 점수 ==> 3명 의 랜덤점수 0~100점을 출력
	// 번호는 1000 ~ 1002 까지 출력 
	// 1등출력 
	int max = 0; int max_num = 0;
	for (int i = 1000; i < 1003; i++) {
		int ran = rand() % 101;
		printf("%d  :   %d", i, ran); printf("\n");
		if (max < ran) {
			max = ran;
			max_num = i;
		}
	}
	printf("1등 : %d  :  %d", max_num, max); printf("\n");

	system("pause");




	// 베스킨라빈스 31 [문제]
	// p1 , p2 는 번갈아가면서 1~3을 입력한다.
	// br 는 p1 , p2 의 값을 누적 저장한다.
	// br 가 31 을 넘어가면 게임종료 ( 넘긴쪽이 패배 : 승리자출력)
	// p1 ==> 2  ,  br ==> 2
	// p2 ==> 3  ,  br ==> 5
	// p1 ==> 1  ,  br ==> 6  .. br > 10 ==> 종료 
	int p1 = 0; int p2 = 0; int br = 0;
	int turn = 0; int run = 1;
	while (1) {
		if (turn == 0) {
			printf("[p1] 1~3을 입력하세요"); printf("\n");
			scanf_s("%d", &p1);
			br += p1; turn = 1;
		}else if (turn == 1) {
			printf("[p2] 1~3을 입력하세요"); printf("\n");
			scanf_s("%d", &p2);
			br += p2; turn = 0;
		}

		if (br >= 31) {
			if (turn == 0) {
				printf("p1승리"); printf("\n");
			}
			else if (turn == 1) {
				printf("p2승리"); printf("\n");
			}
			break;
		}
	}

	// ATM pass

}
