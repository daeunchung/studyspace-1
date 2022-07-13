#include <Windows.h>
#include <stdio.h>

// # �����̵�[����ü(����) ����]

struct Game {
	int count;
	int* game;
	int player;
};

void main() {

	Game g = { 0 };		// ����ü ������ ������ ��� 0���� �ʱ�ȭ �϶�� ��
						// �� malloc �Լ��� �Ҵ��� �޸𸮿��� ����� �� ����.
	g.count = 7;
	g.game = new int[g.count];

	// ==> 1 �� ���
	for (int i = 0; i<g.count; i++) {
		g.game[i] = 0;
	}

	// ==> 2 �� ���
	//*g.game = { 0 };

	// ==> 3 �� ���
	//memset(g.game, 0, sizeof(int)*(g.count));

	g.player = 3;
	g.game[g.player] = 3;

	while (1) {
		printf("[");
		for (int i = 0; i < g.count; i++) {
			if (g.game[i] == 3) {
				printf("��");
			}
			else {
				printf("[ ]");
			}
		}
		printf(" ]\n");

		int move = 0;
		printf("����(1) ������(2) : ");
		scanf_s("%d", &move);

		if (move == 1) {
			if (g.player >= 1) {
				g.game[g.player] = 0;
				g.game[g.player - 1] = 3;
				g.player--;
			}
			else {
				printf("�� �̻� �������� �̵��� �� �����ϴ�.\n");

			}
		}
		else if (move == 2) {
			if (g.player < g.count - 1) {
				g.game[g.player] = 0;
				g.game[g.player + 1] = 3;
				g.player++;
			}
			else {
				printf("�� �̻� ���������� �̵��� �� �����ϴ�.\n");
			}
		}
	}
	system("pause");
}
