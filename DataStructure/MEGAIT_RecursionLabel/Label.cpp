#include <Windows.h>
#include<stdio.h>
void Label(int maze[10][10], int y, int x, int label) {
	if (maze[y][x] == 1) {
		maze[y][x] = label;
		Label(maze, y + 1, x, label);
		Label(maze, y, x + 1, label);
		Label(maze, y - 1, x, label);
		Label(maze, y, x - 1, label);
	}
}
void Print(int maze[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int n = 0; n < 10; n++) {
			if (maze[i][n] == 0) {
				printf(". ");
			}
			else {
				printf("%d ", maze[i][n]);
			}
		}
		printf("\n");
	}
}

void main() {
	int maze[10][10] = {
		{ 1,1,1,1,1,1,0,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,1,1,1,0,1,1,1 },
		{ 1,0,0,0,0,0,0,1,0,1 },
		{ 1,0,1,1,0,1,0,1,0,1 },
		{ 1,1,1,1,0,1,0,1,0,0 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,1,1,1,1,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1 }
	};
	int label = 9;
	for (int i = 0; i < 10; i++) {
		for (int n = 0; n <10; n++) {
			if (maze[i][n] == 1) {
				Label(maze, i, n, label);
				label -= 1;
				Print(maze);	printf("\n");
				Sleep(1000);
			}
		}
	}
	//Print(maze);
	system("pause");
}
