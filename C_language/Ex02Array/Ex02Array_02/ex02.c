#include <Windows.h>
#include <stdio.h>

void main() {
	// ------------------------------------------- 회원가입 [문제] ------------------------------------------------
	// 현재 2명 가입중 (5명밖에 가입불가)
	//int id[] = { 7777, 4545 , 0 , 0, 0 };
	//int pw[] = { 111, 222, 0, 0, 0 };
	//int count = 2;
	// 1.회원가입 2.전체출력 (현재 가입된인원수만 출력)
	//조건1) 5명이상일경우 가입불가 처리 
	//조건2) 이미가입된 아이디로 가입불가 7777(x) , 4545(x)
	//int userid; int userpw; 
	//while (count < 5) {

	//	int check = -1;
	//	printf("가입할 아이디와 비민번호를 입력하시오\n");
	//	scanf_s("%d", &userid);
	//	scanf_s("%d", &userpw);

	//	for (int i = 0; i < 5; i++) {
	//		if (id[i] == userid) {
	//			printf("중복되는 아이디가 있습니다. 다시 입력해주세요\n\n");
	//			check = 1;
	//			break;
	//		}
	//	}

	//	if (check == -1) {
	//		id[count] = userid;
	//		pw[count] = userpw;
	//		count++;
	//	}
	//}

	//system("pause");


	//// ------------------------------------------- 영화관 예매 [문제] ------------------------------------------------
	//// 전부 0 으로 저장 
	//int t[7] = { 0 };

	//// 자리 예매 
	//// 번호 : 0 1 2 3 4 5 6
	//// 자리 : o o o o o o o
	//// 0~6번을 입력받고 자리 예매를 한다.

	//// 예)
	//// 1. 0 1 2 3 4 5 6
	//// 1. o o o o o o o
	//// 1. 예매할 좌석을 입력하세요 0
	//// 1. 0번자리가 예매되었습니다.

	//// 2. 0 1 2 3 4 5 6
	//// 2. x o o o o o o
	//// 2. 예매할 좌석을 입력하세요 0
	//// 2. 0번자리는 이미 예매한 좌석입니다 다른자리를 입력하세요.	
	//int seat;
	//while (1) {
	//	for (int i = 0; i < 7; i++) {
	//		if (t[i] == 0) { printf("o "); }
	//		else if (t[i] == 1) { printf("x "); }
	//	}
	//	printf("\n");

	//	printf("예매할 좌석을 입력하세요 [0~6]\n");
	//	scanf_s("%d", &seat);

	//	if (t[seat] == 0) {
	//		t[seat] = 1;
	//		printf("%d번 자리가 예매되었습니다\n", seat);
	//		continue;
	//	}
	//	else {
	//		printf("%d번 이미 예매한 좌석입니다 다른자리를 입력하세요.\n", seat);
	//		continue;

	//	}

	//}
	//system("pause");



	// ------------------------------------------ # 배열 컨트롤러 [문제]  ---------------------------------------------
	// 1. 추가 : 값을 입력받아 순서대로 추가하기
	// 2. 삭제 : 방번호(index)를 입력받아 값 삭제하기
	// 3. 삭제 : 값을 입력받아 값 삭제하기
	int score[5] = { 0 };
	int max = 5;
	int count = 0;

	int i = 0;
	while (i == 0) {
		printf("1.추가 2.삭제[번호] 3.삭제[값] 4.출력"); printf("\n");
		int num;
		int sel = 0;
		scanf_s("%d", &sel);
		if (sel == 1) {
			if (count < 5) {
				scanf_s("%d", &num); 
				score[count] = num;
				count++;
				printf("추가 되었습니다\n");
				continue;

			}
			else if (count == max) {
				printf("더 이상 추가할 수 없습니다\n");
				continue;
			}
		}
		else if (sel == 2) {
		
			scanf_s("%d", &num);
			for (int i = 0; i < 5; i++) {
				score[num] = 0;
				count--;
			}
		}
		else if (sel == 3) {
			scanf_s("%d", &num);
			for (int i = 0; i < 5; i++) {
				if (score[i] == num) {
					score[i] = 0;
				}
				count--;
			}
		}
		else if (sel == 4) {
			for (int i = 0; i < 5; i++) {
				printf("%d ", score[i]);
			}printf("\n");
		}
	}

	system("pause");



	/*
	------------------------------------------------- # ATM [문제] ---------------------------------------------
	[1] 로그인
	. 계좌번호와 비밀번호를 입력받아 로그인 처리
	. 로그인 후, 재 로그인 불가
	[2] 이체
	. 로그인 후, 이용가능
	[3] 로그아웃
	. 로그인 후, 이용가능
	*/


		int account[4] = { 1111, 2222, 3333, 4444 };
		int password[4] = { 1234, 2345, 3456, 4567 };
		int balance[4] = { 5000, 6000, 7000, 8000 };

		int login = -1;

		int run = 1;
		while (run == 1) {
			printf("1. 로그인");		printf("\n");
			printf("2. 이체"); 		printf("\n");
			printf("3. 로그아웃");	printf("\n");

			printf("메뉴를 선택하세요 : ");
			int sel = 0;
			scanf_s("%d", &sel);

			if (sel == 1) {}
			else if (sel == 2) {}
			else if (sel == 3) {}
		}

		system("pause");



}
