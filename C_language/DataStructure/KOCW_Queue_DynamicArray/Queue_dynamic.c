/*

		동적 원형 배열 -> Queue 구현하기

												*/
#include <stdio.h>
#include <stdlib.h>

struct DynArrayQueue
{
		int front, rear;
		int capacity;
		int* array;
};

struct DynArrayQueue* CreateDynQueue(){	// 그냥 이 함수는 int size 안받고 한칸 터주는걸로 초기화해놓은거 no big deal

	struct DynArrayQueue* Q = malloc(sizeof(struct DynArrayQueue));
	if (!Q)	// malloc 잘 됐는지 안됐는지 확인하는 if 문
		return NULL;
	
	Q->capacity = 1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if (!Q->array) {
		return NULL;
	}

	return Q;
	
}

int IsEmptyQueue(struct DynArrayQueue * Q) {
	return((Q->front) == -1);
}

int IsFullQueue(struct DynArrayQueue* Q) {
	return((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(struct DynArrayQueue* Q) {
	return(Q->capacity) + (Q->rear) - (Q->front) + 1 % Q->capacity;
}


void ResizeQueue(struct DynArrayQueue *Q) {
	int size = Q->capacity;
	Q->capacity = Q->capacity * 2;
	Q->array = realloc(Q->array, Q->capacity* sizeof(int));

	if (!Q->array) {
		printf("Memory Error");
		return;
	}

	// 요부분이 정적어레이와 다름. 아주 중요한 부분
	if (Q->front > Q->rear) {
		for (int i = 0; i < Q->front; i++) {
			Q->array[i + size] = Q->array[i];
			// size 는 realloc 전의 old capacity 를 말한다
		}
		Q->rear = Q->rear + size;
	}
}

void EnQueue(struct DynArrayQueue* Q, int data) {
	if (IsFullQueue(Q)) 
		ResizeQueue(Q);	//  isempty isfull queuesize  다 똑같고 이부분은 staticArray  와 달라
	Q->rear = (Q->rear + 1) % Q->capacity;
	Q->array[Q->rear] = data;
	if (Q->front == -1) {
		Q->front = Q->rear;
	}
}


int DeQueue(struct DynArrayQueue* Q) {

	int data = 0;	// 또는 큐에 존재하지 않는 항목
	if (IsEmptyQueue(Q)) {
		printf("Queue is Empty");
		return 0;
	}
	else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear) {	// data가 하나밖에 없다는 소리(이거 빼면 empty 될꺼임)
			Q->front = -1;
			Q->rear = -1;
		}
		else {
			Q->front = (Q->front + 1) % Q->capacity;
		}
		return data;
	}
}

void DeleteQueue(struct DynArrayQueue *Q) {
	if (Q)
		free(Q->array);
	free(Q);
}


//		동적 원형 배열 -> Queue 구현하기

/*
공간복잡도(n번의 인큐 연산에 대하여)		O(n)

Enqueue 시간복잡도						O(1)(평균)
Dequeue 시간복잡도						O(1)
QueueSize 시간복잡도						O(1)
IsEmptyQueue 시간복잡도					O(1)
IsFullQueue 시간복잡도					O(1)
DeleteQueue 시간복잡도					O(1)


DeleteQueue 가 O(1) 인 이유 : 한번에 통으로 배열 지울수 있기 때문에
*/