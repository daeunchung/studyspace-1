#include <Windows.h>
#include <stdio.h>

void main() {

	// 조건문 
	// 1) if  ==> 키워드
	// 2) (1) ==> 조건 ==> () 사이의 값이 1이면 실행 , 0이면 무시
	// 3) {}  ==> 실행 영역 

	if (1) {
		printf("조건문1"); printf("\n");
	}

	if (0) {
		printf("조건문2"); printf("\n");
	}

	// 변수의 생명주기
	// 변수는 { 안에서 선언되어서 } 끝날때 해제된다.
	int a = 10;
	{
		int b = 20;
	}
	printf("%d", a); printf("\n");
	//	printf("%d" , b);printf("\n"); 에러난다.

	system("pause");

	// 중첩 if 문
	// 놀이동산 입장제한 [문제]
	// 조건1) 130 이상 "입장"
	// 조건2) 120~ 130 사이면 부모님과 동반하에 입장가능
	// 조건3) 120 미만 "입장불가"
	int h;

	printf("키를 입력하시오");		printf("\n");
	scanf_s("%d", &h);

	if (h >= 130) {
		printf("입장");				printf("\n");
	}
	else if (120 <= h && h <= 130) {
		printf("부모님과 동반하에 입장가능");		printf("\n");
	}
	else if (h < 120) {
		printf("입장불가");			printf("\n");
	}
	system("pause");

	//printf("키를 입력하세요 "); printf("\n");
	//int 키 = 0;
	//scanf_s("%d", &키);

	//if (키 >= 130) {
	//	printf("입장"); printf("\n");
	//}
	//if (120 <= 키 && 키 < 130) {
	//	printf("부모님과 동반 입니까? 1)yes  2)no "); printf("\n");
	//	int ans = 0;
	//	scanf_s("%d", &ans);
	//	if (ans == 1) {
	//		printf("입장"); printf("\n");
	//	}
	//	if (ans == 2) {
	//		printf("입장불가"); printf("\n");
	//	}
	//}
	//if (키 < 120) {
	//	printf("입장불가"); printf("\n");
	//}

	//system("pause");

	// 문제1) 롯데리아 자판기
	// 1. 먼저 돈을 입력받는다. 
	// 2. 음식주문한다. 
	// 3. 결과출력  ==>(예) 돈이부족하다 , 햄버거주문 거스름돈 ??? 

	int money = 0;
	printf("돈을 입력하세요 "); printf("\n");
	scanf_s("%d", &money);

	printf("===== 롯데리아 ====="); printf("\n");
	printf("1. 햄버거  500원"); printf("\n");
	printf("2. 콜라 700원"); printf("\n");
	printf("3. 감자 1300원"); printf("\n");

	int select = 0;
	printf("번호를 입력하세요 "); printf("\n");
	scanf_s("%d", &select);
	if (select == 1) {
		if (money >= 500) {
			printf("햄버거가 주문완료되었습니다. 거스름돈: %d원", money - 500);		
			printf("\n");
		}
		else {
			printf("돈이 부족합니다."); 
			printf("\n");
		}
	}
	if (select == 2) {
		if (money >= 700) {
			printf("콜라가 주문완료되었습니다. 거스름돈: %d원", money - 700);
			printf("\n");
		}
		else {
			printf("돈이 부족합니다.");
			printf("\n");
		}
	}
	if (select == 3) {
		if (money >= 1300) {
			printf("감자가 주문완료되었습니다. 거스름돈: %d원", money - 1300);
			printf("\n");
		}
		else {
			printf("돈이 부족합니다.");
			printf("\n");
		}
	}

	system("pause");

	// 가위 바위 보 게임 만들기
	// 1.가위 2.바위 3.보 
	// p1, p2 는 가위 바위 보를 한다. 결과 출력 

	int p1; int p2; int 가위 = 1; int 바위 = 2; int 보 = 3;
	printf("p1 ==> 1.가위 2.바위 3.보 ");
	scanf_s("%d", &p1);

	printf("p2 ==> 1.가위 2.바위 3.보 ");
	scanf_s("%d", &p2);

	if (p1 == p2) {
		printf("비겼다.");
	}
	if (p1 == 가위 && p2 == 보) {
		printf("p1 승리");
	}
	if (p1 == 바위 && p2 == 가위) {
		printf("p1 승리");
	}
	if (p1 == 보 && p2 == 바위) {
		printf("p1 승리");
	}
	if (p1 == 바위 && p2 == 보) {
		printf("p2 승리");
	}
	if (p1 == 가위 && p2 == 바위) {
		printf("p2 승리");
	}
	if (p1 == 보 && p2 == 가위) {
		printf("p2 승리");
	}







}

