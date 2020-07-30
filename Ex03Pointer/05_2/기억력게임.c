#include <windows.h>
#include <stdio.h>
#include <time.h>

// # 기억력 게임[함수로 변경]

// c는 함수가 main보다 앞쪽에서 눈도장 찍어줘야만 main 에서 호출 가능
void print_card(int* p, int size);
void shuffle_card(int* p, int size);
int input_idx();
int check_game(int* front, int* back, int cnt);
void run(int* front, int* back, int size);


void main() {

	srand(time(0));			// 난수 출력 함수

	int size = 10;
	int front[10] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 };
	int back[10] = { 0 };

	run(&front[0], &back[0], size);

	system("pause");
}

void print_card(int* p, int size) {
	printf("[ ");
	for (int i = 0; i < size; i++) {
		printf(" %d ", p[i]);
	}
	printf("]\n");

}
void shuffle_card(int* p, int size) {
	for (int i = 0; i < 1000; i++) {
		int r_num = rand() % size;		// 0~9 난수 
		int tmp = p[0];
		p[0] = p[r_num];
		p[r_num] = tmp;
	}
}

int input_idx() {
	int idx = 0;
	printf("입력[1~10] : ");
	scanf_s("%d", &idx);
	idx--;
	return idx;
}

int check_game(int* front, int* back, int cnt) {
	int idx1 = input_idx();
	int idx2 = input_idx();

	if (front[idx1] == front[idx2]) {
		back[idx1] = front[idx1];
		back[idx2] = front[idx2];
		cnt++;
	}
	return cnt;
}

void run(int* front, int* back, int size) {
	shuffle_card(front, size);

	int cnt = 0;
	while (1) {

		print_card(front, size);			//print_card(&front[0], size);	
		print_card(back, size);				//print_card(&back[0], size);		

		cnt = check_game(front, back, cnt);
		if (cnt == 5) {
			break;
		}
	}
}