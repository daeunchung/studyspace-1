#include <stdio.h>
#include <Windows.h>
#define SIZE 10
struct Map {
	int x;	int y;	int dir;
};
struct NodeQueue {
	Map data;	NodeQueue* next;
};
struct Queue {
	int count;	NodeQueue* front;	NodeQueue* rear;
};
Queue* CreateQueue() {
	Queue* q = new Queue;
	memset(q, 0, sizeof(Queue));
	return q;
}
void InQueue(Queue* q, Map data) {
	NodeQueue* node = new NodeQueue;
	node->data = data;
	if (q->count == 0) {
		q->front = node;
		q->rear = node;
	}
	else {
		q->rear->next = node;
		q->rear = node;
	}
	q->count += 1;
}
NodeQueue* DeQueue(Queue* q) {
	if (q->count <= 0) return 0;
	NodeQueue* del = q->front;
	q->front = del->next;
	if (q->front == 0) { // q->count == 1일때
		q->rear = 0;
	}
	q->count -= 1;
	return del;
}

int** MazeMake() {
	int mazeTemp[SIZE][SIZE] = {
		{ 1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,0,0,0,0,1,1,1 },
		{ 1,0,1,0,1,0,0,1,0,1 },
		{ 1,0,1,0,1,0,0,1,0,1 },
		{ 1,0,1,0,1,0,0,0,0,1 },
		{ 1,0,1,0,1,0,0,1,0,1 },
		{ 1,0,0,0,1,1,1,1,0,1 },
		{ 1,0,1,1,1,1,0,1,0,1 },
		{ 1,0,0,0,3,1,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1 }
	};
	int** maze = new int*[SIZE]; 
	for (int i = 0; i < SIZE; i++) {
		maze[i] = new int[SIZE];
		for (int n = 0; n < SIZE; n++) {
			maze[i][n] = mazeTemp[i][n];
		}
	}
	return maze;
}

void PrintMaze(int** maze, int x, int y) {
	for (int i = 0; i < SIZE; i++) {
		for (int n = 0; n < SIZE; n++) {
			if (x == n && y == i) {
				printf("읏");
			}
			else if (maze[i][n] == 1) {
				printf("■");
			}
			else if (maze[i][n] == 3) {
				printf("☆");
			}
			else if (maze[i][n] == 0) {
				printf("  ");
			}
		}
		printf("\n");
	}
}

void FindMaze(int ** maze) {
	Map start;
	start.x = 1;
	start.y = 1;
	start.dir = 0;
	Queue* q = CreateQueue();
	InQueue(q, start);							// In(1 1 0)
	int mark[SIZE][SIZE];
	memset(mark, 0, sizeof(mark));
	mark[start.y][start.x] = 1;					// Mark(1)
	int run = 1;
	while (q->count > 0 && run == 1) {			// Queue에 든게 있고, 종착지 도착 X 일때
		NodeQueue* del = DeQueue(q);			// Dequeue head의 (x, y, dir)
		Map temp = del->data;
		int x = temp.x;
		int y = temp.y;
		int dir = temp.dir;
		while (dir < 4) {
			int cy = y;
			int cx = x;
			if (dir == 0) cy = cy - 1;
			else if (dir == 1) cx = cx + 1;
			else if (dir == 2) cy = cy + 1;
			else if (dir == 3) cx = cx - 1;		// Dequeue 한 head의 dir 에 따라서 cy, cx 값 변경(player 이동)

			if (cy >= 0 && cy < SIZE && cx >= 0 && cx < SIZE) {
				if (maze[cy][cx] == 3) {
					// 이동 후에 다음 칸이 종착지 일때
					system("cls");
					PrintMaze(maze, cx, cy);
					Sleep(400);
					mark[cy][cx] = 1;
					run = 0;
					break;

				}else if (maze[cy][cx] == 0 && mark[cy][cx] == 0) {
					// 이동 후에 다음 칸이 통로구간인데 Inqueue된 적이 없을때 (안가본 통로일때)
					system("cls");
					PrintMaze(maze, cx, cy);
					Sleep(400);
					mark[cy][cx] = 1;
					temp.dir = dir + 1;
					InQueue(q, temp);			// 해당 좌표에 dir++ 인것을 Inqueue 해주고
					Map node;
					node.x = cx;
					node.y = cy;
					node.dir = 0;
					InQueue(q, node);			// 해당 좌표에 dir 0인것을 Inqueue 해준다
					break;
				}
			}
			dir += 1;
		}
	}
	printf("q->count : %d\n", q->count);
}


void main() {
	int** maze = MazeMake();
	PrintMaze(maze, 1, 1);
	FindMaze(maze);
	printf("종료\n");
}

//for (int i = 0; i < SIZE; i++) {
//	for (int n = 0; n < SIZE; n++) {
//		printf("%d", mark[i][n]);
//	}
//	printf("\n");
//}


/*Map map;
map.x = 10;
Queue* q = CreateQueue();
InQueue(q, map);
map.x = 11;
InQueue(q, map);
NodeQueue* del = DeQueue(q);
printf("%d", del->data.x); printf("\n");
del = DeQueue(q);
printf("%d", del->data.x); printf("\n");*/
