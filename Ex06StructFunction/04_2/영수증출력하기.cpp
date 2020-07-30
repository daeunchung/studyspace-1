#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

// # 영수증 출력하기[구조체(변수+함수) 변경]

struct Store {
	int count;
	int* counts;
	int* prices;
	int money;

	void init() {
		money = 20000;
		count = 3;							// 물건 종류 3가지
		counts = new int[count];			// 물건별 수량 배열 파주기
		for (int i = 0; i<count; i++) {		
			counts[i] = 0;					// 처음에는 전부다 0개씩
		}
		prices = new int[count];			// 물건별 가격 배열 파주기
		prices[0] = 8700;
		prices[1] = 4200;
		prices[2] = 1500;					// 물건별 가격 값 배열에 넣어주기
	}

	void print_menu() {
		printf("=== 롯데리아 ===\n");
		printf("1.[셋트]불고기버거 : %d원\n", prices[0]);
		printf("2.[단품]불고기버거 : %d원\n", prices[1]);
		printf("3.콜라 : %d원\n", prices[2]);
		printf("4.종료하기\n");
	}

	int sel_menu() {
		int choice = 0;
		printf("메뉴 선택 : ");
		scanf("%d", &choice);
		if (choice > 4 || choice < 1) {
			choice = -1;
		}
		return choice;
	}

	void choice1() {
		counts[0] += 1;
	}
	void choice2() {
		counts[1] += 1;
	}
	void choice3() {
		counts[2] += 1;
	}
	void choice4() {

		int total = prices[0] * counts[0] + prices[1] * counts[1] + prices[2] * counts[2];
		int charge = money - total;
		if (charge >= 0) {
			printf("=== 영수증 ===\n");
			printf("1.[셋트]불고기버거 : %d개\n", counts[0]);
			printf("2.[단품]불고기버거 : %d개\n", counts[1]);
			printf("3.콜라 : %d개\n", counts[2]);
			printf("총금액 : %d원\n", total);
			printf("잔돈은 %d원 입니다.\n", charge);
		}
		else if(charge < 0){
			printf("현금이 부족합니다.\n");
		}
	}

	void run() {
		init();
		while (1) {
			print_menu();
			int choice = sel_menu();

			if (choice == -1) {
				printf("입력오류\n");
				continue;
			}

			if (choice == 1) { choice1(); }
			else if (choice == 2) { choice2(); }
			else if (choice == 3) { choice3(); }
			else if (choice == 4) { choice4(); break; }
		}
	}
};

void main() {
	Store burger = { 0 };
	burger.run();
	system("pause");
}
