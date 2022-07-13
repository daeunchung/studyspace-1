#include <Windows.h>
#include <stdio.h>

/*
# 영화관 좌석예매[함수로 변경]
*/

void print_menu() {
	printf("=== 영화관 좌석예매 ===\n");
		printf("1.예매하기\n");
		printf("1.종료하기\n");
}

int sel_menu() {
	int choice = 0;
	printf("메뉴 선택 : ");
	scanf_s("%d", &choice);
	if (2 < choice || choice < 0) {
		printf("입력오류\n");
	}
	return choice;
}
void print_seat(int * p, int count) {
	for (int i = 0; i < count; i++) {
		if (p[i] == 0) {
			printf("[X]");
		}
		else {
			printf("[O]");
		}
	}
	printf("\n");
}

int sel_seat(int * p, int count) {
	int idx = 0;
	printf("좌석선택(1~5) : ");
	scanf_s("%d", &idx);
	idx -= 1;

	int check = idx;
	if (count <= idx || idx < 0) {
		check = -1;
	}
	return check;
}



void run(int * p, int count) {

	while (1) {
		print_menu();

		int choice = sel_menu();


		if (choice == 1) {
			print_seat(p, count);
			int idx = sel_seat(p, count);

			if (idx == -1) {
				printf("입력오류\n");
				continue;
			}

			if (p[idx] == 0) {
				p[idx] = 1;
			}
			else if (p[idx] == 1) {
				printf("해당 위치는 예매할 수 없습니다.\n");
			}
			else {
				printf("입력오류\n");
			}
		}

		else if (choice == 2) {
			break;
		}
	}
}

void main() {

	int count = 5;
	int seat[5] = { 0 };

	run(&seat[0], count);

	system("pause");
}
