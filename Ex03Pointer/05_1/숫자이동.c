#include <Windows.h>
#include <stdio.h>
int get_player(int * p, int count) {
	int player = 0;
	for (int i = 0; i < count; i++) {
		if (p[i] == 3) {
			player = i;
		}
	}
	return player;
}

void print_game(int * p, int count) {
	printf("[ ");
	for (int i = 0; i < count; i++) {
		if (p[i] == 3) {
			printf("[웃]");
		}
		else {
			printf("[ ]");
		}
	}
	printf(" ]\n");
}


int move_left(int * p, int player) {
	if (player > 0) {
		p[player - 1] = 3;
		p[player] = 0;
		player--;
	}
	return player;
}

int move_right(int *p, int player, int count) {
	if (player < count - 1 ) {
		p[player] = 0;
		p[player + 1] = 3;
		player++;
	}
	return player;
}

void run(int * p, int count) {
	int player = get_player(p, count);

	while (1) {

		print_game(p, count);
		int move = 0;
		printf("왼쪽(1), 오른쪽(2) : ");
		scanf_s("%d", &move);
		if (move == 1) {
			 player = move_left(p, player);
		}
		else if(move == 2){
			 player = move_right(p, player, count);
		}
	}
}

void main() {

	// # 숫자이동[함수로 변경]
	int count = 7;
	int game[7] = { 0, 0, 0, 3, 0, 0, 0 };

	run(&game[0], count);
	system("pause");
}
