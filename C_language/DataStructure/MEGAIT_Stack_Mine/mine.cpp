// === [파일 이름] ===
// mine.cpp		 
//===================
#include "mine.h"

Stack* create_stack() {
	Stack * stack = new Stack();
	memset(stack, 0, sizeof(Stack));
	return stack;
}
void push(Stack * stack, Check data) {
	Node * node = new Node;
	node->data = data;
	node->next = stack->top;
	stack->top = node;
	stack->count += 1;
}

Node * pop(Stack * stack) {
	Node * del = NULL;
	if (stack->count <= 0)	return	del;
	del = stack->top;
	stack->top = del->next;
	stack->count -= 1;
	return del;
}

Node * peek(Stack * stack) {
	return stack->top;
}

Mine ** set_bomb() {
	int count = BOMB_COUNT;		// 35
	Mine** mine;
	mine = new Mine*[MAP_SIZE];	// 7
	for (int i = 0; i < MAP_SIZE; i++) {
		mine[i] = new Mine[MAP_SIZE];
		for (int n = 0; n < MAP_SIZE; n++) {
			if (count > 0) {
				mine[i][n].value = 9;
				count -= 1;
			}
			else {
				mine[i][n].value = 0;
			}
			mine[i][n].mark = 0;
		}
	}
	return mine;
}
// 폭탄 개수인 딱 35 개만 value : 9, 나머지 14개는 value : 0
// 폭탄이든 아니든 모두 mark : 0

void print_map(Mine ** mine) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int n = 0; n < MAP_SIZE; n++) {
			printf("[%d]", mine[i][n].value);
		}
		printf("\n");
	}
	printf("\n");
}

void shuffle(Mine ** map) {
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		int r1 = rand() % MAP_SIZE;
		int r2 = rand() % MAP_SIZE;
		Mine temp = map[r1][r2];
		map[r1][r2] = map[0][0];
		map[0][0] = temp;
	}
}

int check_8dir_bomb(Mine ** map, int y, int x) {
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int n = -1; n <= 1; n++) {
			int cy = y + i;
			int cx = x + n;
			if (cy >= 0 && cy < MAP_SIZE && cx >= 0 && cx < MAP_SIZE) {
				if (map[cy][cx].value == 9)
					count += 1;
			}
		}
	}
	return count;
} // 입력받은 좌표 기준으로 팔방에 폭탄이 몇개 있는지 확인하는 메서드

void count_bomb(Mine ** map) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int n = 0; n < MAP_SIZE; n++) {
			if (map[i][n].value == 0) {
				map[i][n].value = check_8dir_bomb(map, i, n);
			}
		}
	}
} // 8방에 폭탄 몇개 있는 지를 세어서 해당 좌표의 value 값에 넣어주는 메서드

void print_game(Mine ** map) {
	printf("  ");
	for (int i = 0; i < MAP_SIZE; i++) {
		printf(" %d ", i);
	}
	printf("\n");
	for (int i = 0; i < MAP_SIZE; i++) {
		printf("%d", i);
		for (int n = 0; n < MAP_SIZE; n++) {
			if (map[i][n].value == 9) {
				printf(" ♡");
			}else if (map[i][n].mark == 1) {
				printf(" ☆");
			}else if (map[i][n].value != 9) {
				printf("   ");
			}
		}
		printf("\n"); 
	}
	printf("\n");
}

void play_game(Mine ** map) {
	Stack * stack = create_stack();
	printf("인덱스 2개를 입력하세요 \n");
	int y; int x;
	scanf_s("%d", &y);
	scanf_s("%d", &x);
	if (map[y][x].value != 9 && map[y][x].mark == 0) {
		Check check;
		check.x = x;
		check.y = y;
		push(stack, check);
	}
	Node * del = pop(stack);
	while (del != NULL) {
		int y = del->data.y;
		int x = del->data.x;
		printf("%d %d\n", y, x);
		map[y][x].mark = 1;
		for (int i = -1; i <= 1; i++) {
			for (int n = -1; n <= 1; n++) {
				if (i == 0 && n == 0) continue;
				int cy = y + i;
				int cx = x + n;
				if (cy >= 0 && cy < MAP_SIZE && cy >= 0 && MAP_SIZE) {
					if (map[cy][cx].value != 9 && map[cy][cx].mark == 0) {
						Check check;
						check.x = cx;
						check.y = cy;
						push(stack, check);
					}
				}
			}
		}
		delete del;
		del = pop(stack);
	}

}