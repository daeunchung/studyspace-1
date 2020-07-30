
// LinkedList 를 사용하여 구현한  Queue

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int data;
	struct ListNode* next;
};

struct Queue {
	struct ListNode* front;
	struct ListNode* rear;

};

struct Queue* CreateQueue() {
	struct Queue* Q;
	struct ListNode* temp;
	Q = malloc(sizeof(struct Queue));
	if (!Q)
		return NULL;

	temp = malloc(sizeof(struct ListNode));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

int IsEmptyQueue(struct Queue* Q) {
	// 조건이 참이면 1, 거짓이면 0 리턴
	return((Q->front) == NULL);
}

int IsFullQueue(struct Queue* Q) {
}

void EnQueue(struct Queue* Q, int data) {
	struct ListNode* newNode;
	newNode = malloc(sizeof(struct ListNode));

	if (!newNode)
		return NULL;

	newNode->data = data;
	newNode->next = NULL;
	if (Q->rear != NULL) {	// 겁나 중요함.  Q->rear 가 NULL일때 Q->rear->next 는 존재할 수 없음
		Q->rear->next = newNode;
	}
	Q->rear = newNode;
	if (Q->front == NULL) {	// front 에 아무것도 없으면 ( 지금 넣는게 처음놈이면 )
		Q->front = Q->rear;	// 존재하는 그 한놈에게 front와 rear를 모두 넣어주기 
	}

}

int Dequeue(struct Queue* Q) {
	int data = 0; //	또는 큐에 존재하지 않는 항목
	struct ListNode * temp;
	if (IsEmptyQueue(Q)) {
		printf("Queue is Empty");
		return 0;
	}
	else {
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
	}
	return data;
}

void DeleteQueue(struct Queue*Q) {
	struct ListNode* temp;

	while (Q->front) {		//	while (Q) { (X)
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
	free(Q);
}


/*
공간복잡도(n번의 인큐 연산에 대하여)		O(n)

Enqueue 시간복잡도						O(1)(평균)
Dequeue 시간복잡도						O(1)
IsEmptyQueue 시간복잡도					O(1)
DeleteQueue 시간복잡도					O(n)	

DeleteQueue 가 O(n) 인 이유 : linkedlist는 메모리가 다 중간중간 흩뿌려져있기때문에
타고타고 내려가면서 하니씩 지워줘야해서

*/