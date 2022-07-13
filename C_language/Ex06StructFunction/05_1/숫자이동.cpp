#include <Windows.h>
#include <stdio.h>

// # 숫자이동[구조체(변수+함수) 변경]

struct Game {
	int count;
	int* game;
	int player;

	void init() {
		count = 7;
		player = 3;
		game = new int[count];
		for (int i = 0; i<count; i++) {
			game[i] = 0;
		}
		game[player] = 3;
	}

	void print_game() {
		printf("[   ");
		for (int i = 0; i < count; i++) {
			if (game[i] == 0) {
				printf("[ ]");
			}
			else if (game[i] == 3) {
				printf("옷");
			}
		}
		printf("   ]\n");
	}

	void move_left() {
		if (player - 1 >= 0) {
			game[player] = 0;
			game[player - 1] = 3;
			player -= 1;
		}
		else {
			printf("더이상 좌로 이동할 수 없습니다.\n");
		}


	}
	void move_right() {
		if (player < count - 1) {
			game[player] = 0;
			game[player + 1] = 3;
			player += 1;
		}
		else {
			printf("더이상 우로 이동할 수 없습니다.\n");
		}
	}

	void run() {
		init();
		while (1) {
			print_game();
			int move = 0;
			printf("왼쪽(1), 오른쪽(2) : ");
			scanf_s("%d", &move);
			if (move == 1) { move_left(); }
			else if (move == 2) { move_right(); }
		}
	}
};

void main() {
	Game g = { 0 };
	g.run();
	system("pause");
}
