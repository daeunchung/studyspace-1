#include <Windows.h>
#include <stdio.h>

/*
# 영화관 좌석예매[구조체(변수) 변경]
*/

struct Movie {
	int* seat;
	int count;
};

void main() {

	Movie mega = { 0 };
	mega.count = 5;
	mega.seat = new int[mega.count];
	for (int i = 0; i<mega.count; i++) {
		mega.seat[i] = 0;
	}

	while (1) {
		printf(" === 영화관 좌석예매 === \n");
		printf("1. 예매하기 \n");
		printf("2. 종료하기 \n");

		int choice = 0;
		printf("메뉴 선택 : ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			for (int i = 0; i < mega.count; i++) {
				if (mega.seat[i] == 1) {
					printf("[X]");
				}
				else if (mega.seat[i] == 0) {
					printf("[O]");
				}
			}
			printf("\n");

			int idx = 0;
			printf("좌석번호 입력(1~5) : ");
			scanf_s("%d", &idx);

			if (mega.count < idx || idx < 1) {
				printf("입력오류\n");
				continue;	// 다시 입력 받게끔
			}

			idx -= 1;

			if (mega.seat[idx] == 0) {
				mega.seat[idx] = 1;
				printf("예매 완료.\n");

			}
			else if (mega.seat[idx] == 1) {
				printf("이미 예매된 좌석입니다.\n");
			}
		}
		else if(choice == 2){
			break;
		}
	}

	system("pause");

}
