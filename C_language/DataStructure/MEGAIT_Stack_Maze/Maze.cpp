#include <stdio.h>
#include <Windows.h>
#define MAP_SIZE 8
struct Maze
{
	int value; int mark;
};
struct Check
{
	int x; int y; int dir;
}; 
struct Node
{
	Check data; Node * next;
};
struct Stack
{
	int count; Node* top;
};

Stack * create_stack();
void push(Stack * stack, Check data);
Node * pop(Stack * stack);
Node * peek(Stack * stack);
Maze ** set_maze();
void print_map(Maze ** map, int py, int px);
void find_goal(Maze ** map);

Stack * create_stack() {
	Stack * stack = new Stack;
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
Node* pop(Stack * stack) {
	Node * del = NULL;
	if (stack->count <= 0) return del;
	del = stack->top;
	stack->top = del->next;
	stack->count -= 1;
	return del;
}
Node * peek(Stack * stack) {
	return stack->top;
}

Maze ** set_maze() {
	int temp[MAP_SIZE][MAP_SIZE] = {
		{ 1,1,1,1,1,1,1,1 },
		{ 1,0,1,0,1,0,0,1 },
		{ 1,0,1,0,0,0,1,1 },
		{ 1,0,1,1,1,0,1,1 },
		{ 1,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,0,1 },
		{ 1,3,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1 }
	};
	Maze** map = new Maze*[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++) {
		map[i] = new Maze[MAP_SIZE];
		for (int n = 0; n < MAP_SIZE; n++) {
			map[i][n].mark = 0;
			map[i][n].value = temp[i][n];
		}
	}
	return map;
}

void print_map(Maze** map, int py, int px) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int n = 0; n < MAP_SIZE; n++) {
			if (py == i && px == n) {
				printf("읏");
			}
			else if (map[i][n].value == 1) {
				printf("■");	// 벽
			}
			else if (map[i][n].value == 3) {
				printf("골");	// 종착지
			}
			else if (map[i][n].value == 0) {
				printf("  ");	// 통로
			}
		}
		printf("\n");
	}
}

void find_goal(Maze ** map) {
	Stack * stack = create_stack();
	int py = 1; int px = 1;
	Check check;	check.y = py;	check.x = px;	check.dir = 0;
	map[check.y][check.x].mark = 1;
	push(stack, check);
	Node* del = pop(stack);
	int run = 1;
	while (run == 1 && del != NULL) {
		Check check = del->data;
		int y = check.y;
		int x = check.x;
		int dir = check.dir;
		while (dir < 4) {
			int cy = y;
			int cx = x;
			if (dir == 0) cy = cy - 1;
			else if (dir == 1) cx = cx + 1;
			else if (dir == 2) cy = cy + 1;
			else if (dir == 3) cx = cx - 1;
			if (cy >= 0 && cy < MAP_SIZE && cx >= 0 && cx < MAP_SIZE) {	// 이동후 값이 미로 안이면
				if (map[cy][cx].value == 3) {
					run = 0;
					printf("도착\n");
					break;
				}
				if (map[cy][cx].value == 0 && map[cy][cx].mark == 0) { 
					// value == 0 : 통로(길) 이고, mark == 0 : 가보지 못했던 길, 처음 가본 길
					Sleep(1000);	// 1초 정지
					system("cls");	// 콘솔창 지우기
					print_map(map, cy, cx);
					check.dir = dir + 1;
					push(stack, check);
					map[cy][cx].mark = 1;
					Check pos;
					pos.dir = 0;
					pos.x = cx;
					pos.y = cy;
					push(stack, pos);
					break;
				}
			}
			dir += 1;
		}
		delete del;
		del = pop(stack);
	}
	printf("끝\n");
}





void main() {
	Maze** map = set_maze();
	print_map(map, 1, 1);
	find_goal(map);
}


// py px 는 기존 입력받은 이동 전의 좌표
// cy cx 는 이동 후 바뀔 새 좌표
//   0
//3 dir 1
//   2
