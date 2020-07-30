#include <Windows.h>
#include <stdio.h>

// # 숫자이동[구조체(변수) 변경]

struct Game {
	int count;
	int* game;
	int player;
};

void main() {

	Game g = { 0 };		// 구조체 변수의 내용을 모두 0으로 초기화 하라는 뜻
						// 단 malloc 함수로 할당한 메모리에는 사용할 수 없음.
	g.count = 7;
	g.game = new int[g.count];

	// ==> 1 번 방법
	for (int i = 0; i<g.count; i++) {
		g.game[i] = 0;
	}

	// ==> 2 번 방법
	//*g.game = { 0 };

	// ==> 3 번 방법
	//memset(g.game, 0, sizeof(int)*(g.count));

	g.player = 3;
	g.game[g.player] = 3;

	while (1) {
		printf("[");
		for (int i = 0; i < g.count; i++) {
			if (g.game[i] == 3) {
				printf("옷");
			}
			else {
				printf("[ ]");
			}
		}
		printf(" ]\n");

		int move = 0;
		printf("왼쪽(1) 오른쪽(2) : ");
		scanf_s("%d", &move);

		if (move == 1) {
			if (g.player >= 1) {
				g.game[g.player] = 0;
				g.game[g.player - 1] = 3;
				g.player--;
			}
			else {
				printf("더 이상 왼쪽으로 이동할 수 없습니다.\n");

			}
		}
		else if (move == 2) {
			if (g.player < g.count - 1) {
				g.game[g.player] = 0;
				g.game[g.player + 1] = 3;
				g.player++;
			}
			else {
				printf("더 이상 오른쪽으로 이동할 수 없습니다.\n");
			}
		}
	}
	system("pause");
}
