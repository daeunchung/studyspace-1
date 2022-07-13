// === [파일 이름] ===
// mine.h		 
//===================
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#define MAP_SIZE 7
#define BOMB_COUNT 35

struct Mine {
	int mark;	int value;
};
struct Check {
	int x;		int y;
};
struct Node {
	Check data;	
	Node * next;
};
struct Stack {
	int count;
	Node * top;
};

Mine ** set_bomb();
void print_map(Mine ** map);
void shuffle(Mine ** map);
void count_bomb(Mine ** map);
int check_8dir_bomb(int y, int x);

void print_game(Mine ** map);
void play_game(Mine ** map);

Stack * create_stack();
void push(Stack * stack, Check data);
Node * pop(Stack * stack);
Node * peek(Stack * stack);
