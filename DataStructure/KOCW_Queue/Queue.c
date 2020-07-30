/* 


			static array 를 이용한 Queue


													*/

#include <stdio.h>
#include <stdlib.h>

// 자연현상 중 선착순을 위한 자료구조 : Queue

struct ArrayQueue
{
	int front, rear;
	int capacity;
	int* array;
};

struct ArrayQueue* Queue(int size)
{
	struct ArrayQueue* Q = malloc(sizeof(struct ArrayQueue));
	if (!Q) {	// 혹시 공간없어서 Q 못만들었을때 예외처리 if 문
		return NULL;
	}
	Q->capacity = size;
	Q->front = -1;
	Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if (!Q->array) {
		return NULL;
	}
	return Q;
}

int IsEmptyQueue(struct ArrayQueue * Q) { // empty 이면 front rear 둘다 -1이니까
	// 조건이 참이면 1이고 아니면 0리 리턴된다
	return((Q->front) == -1);

	// front가 -1인데 rear 가 다른숫자일 수는 없다. 불가능해.
	// 그러니까 front 가 -1 이면 당연히 rear 도 -1 일꺼고 front 가 -1이면 empty라는거
}

int IsFullQueue(struct ArrayQueue* Q) {
	// 조건이 참이면 1이 리턴되고 아니면 0이 리턴된다
	return((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(struct ArrayQueue* Q) {	// rear 가 정방향 , 역방향(한바퀴 다 돌고나서) 이든 둘 다 적용되는 공식
	return(Q->capacity) + (Q->rear) - (Q->front) + 1 % Q->capacity;

	// 또는 ( rear + capacity - front + 1 ) % capacity;
}

void EnQueue(struct ArrayQueue* Q, int data) {
	if (IsFullQueue(Q)) {
		printf("Queue Overflow");

	}
	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = data;
		if (Q->front == -1) {
			Q->front = Q->rear;
		}
	}
}

int DeQueue(struct ArrayQueue* Q) {
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

void DeleteQueue(struct ArrayQueue *Q) {
	if (Q)
		free(Q->array);
	free(Q);
}


/*
- 성능
O(n)없고 모두 constant time O(1) 안에 끝날 수 있는 것들 이다

- 한계
큐의 최대 크기가 미리 정해져야 하고 바뀔 수 없다.
꽉 찬 큐에 항목을 인큐하려면 이 구현에만 관련된 예외(overflow)가 발생한다.


큐를 구현하는데 가장 흔하게 사용되는 방법들
	간단한 원형 배열에 기초한 구현
	동적 원형 배열에 기초한 구현
	연결 리스트 구현

	왜 원형배열을 사용하는가 -> 배열의 앞쪽 공간이 낭비되는 현상 때문에 기본 배열은 큐 구현시 부적합하다.


*/

