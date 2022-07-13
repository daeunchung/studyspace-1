#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Shape
{
	int rect[4][4];
};
struct Node
{
	Shape shape[4];
};
struct Player
{
	int x;
	int y;
	int index;
	Node node;
};
struct Board
{
	int ** map;
};
#define WIDTH 10
#define HEIGHT 20
Board* SetBoard();
Player * SetPlayer();
void PrintBoard(Board* board);
//void SetNode();
Node GetRanNode();
void Update(Board* board, Player * p);
void InputKey(Player * p);
void removeBefore(Board* board, Player * p);

void main() {
	srand(time(0));
	Board * board = SetBoard();
	Player * p = SetPlayer();
	Update(board, p);
	while (1) {
		system("cls");
		PrintBoard(board);
		removeBefore(board, p);
		InputKey(p);
		Update(board, p);
	}
}
Board* SetBoard() {			// 보드한판 (10x20) 셋팅
	Board * board = new Board;
	board->map = new int *[HEIGHT];
	for (int i = 0; i < HEIGHT; i++) {
		board->map[i] = new int[WIDTH];
		for (int n = 0; n < WIDTH; n++) {
			board->map[i][n] = 0;
		}
	}
	return board;
}
Player * SetPlayer() {		// 개별적으로 노는 노드한개 (4x4) 셋팅
	Player * p = new Player;
	p->node = GetRanNode();
	p->y = 1;	p->x = 3;
	p->index = 0;
	return p;
}
void PrintBoard(Board* board) {
	int ** pp = board->map;
	for (int i = 0; i < HEIGHT; i++) {
		for (int n = 0; n < WIDTH; n++) {
			if(pp[i][n] == 0)
				printf("□");
			else 
				printf("■");
		}
		printf("\n");
	}
}
//void SetNode() {
//
//}
Node GetRanNode() {
	int s1[4][4][4] = {
		{
			{ 1,0,0,0 },
			{ 1,0,0,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 }
		},
		{
			{ 0,0,0,0 },
			{ 1,1,1,0 },
			{ 1,0,0,0 },
			{ 0,0,0,0 }
		},
		{
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 0,0,1,0 },
			{ 0,0,1,0 }
		},
		{
			{ 0,0,0,0 },
			{ 0,0,1,0 },
			{ 1,1,1,0 },
			{ 0,0,0,0 }
		},
	};

	int s2[4][4][4] = {
		{
			{ 0,1,0,0 },
			{ 1,1,1,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{
			{ 0,1,0,0 },
			{ 0,1,1,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
		{
			{ 0,0,0,0 },
			{ 1,1,1,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
		{
			{ 0,1,0,0 },
			{ 1,1,0,0 },
			{ 0,1,0,0 },
			{ 0,0,0,0 }
		},
	};

	int ran = rand() % 2;
	Node node;
	if (ran == 0) {
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < 4; i++) {
				for (int n = 0; n < 4; n++) {
					node.shape[k].rect[i][n] = s1[k][i][n];
				}
			}
		}
	}else if (ran == 1) {
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < 4; i++) {
				for (int n = 0; n < 4; n++) {
					node.shape[k].rect[i][n] = s2[k][i][n];
				}
			}
		}
	}
	return node;
}
void Update(Board* board, Player * p) {
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			int index = p->index;
			int by = p->y + i;
			int bx = p->x + n;
			if (0 == p->node.shape[index].rect[i][n]) {
				board->map[by][bx] = 0;
			}
			else if (1 == p->node.shape[index].rect[i][n]) {
				board->map[by][bx] = 1;
			}
		}
	}
}
void InputKey(Player * p) {
	int sel;
	printf("[1.left] [2.right] [3.up] [4.down] [5.switch]"); printf("\n");
	scanf_s("%d", &sel);
	if (sel == 1) {
		p->x -= 1;
	}
	else if (sel == 2) {
		p->x += 1;
	}
	else if (sel == 3) {
		p->y -= 1;
	}
	else if (sel == 4) {
		p->y += 1;
	}
	else if (sel == 5) {
		p->index += 1;
		if (p->index > 3) {
			p->index = 0;
		}
	}
}
void removeBefore(Board* board, Player * p) {
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			int index = p->index;
			int by = p->y + i;
			int bx = p->x + n;
			if (1 == p->node.shape[index].rect[i][n]) {
				board->map[by][bx] = 0;
			}
		}
	}
}
