/*

		���� ���� �迭 -> Queue �����ϱ�

												*/
#include <stdio.h>
#include <stdlib.h>

struct DynArrayQueue
{
		int front, rear;
		int capacity;
		int* array;
};

struct DynArrayQueue* CreateDynQueue(){	// �׳� �� �Լ��� int size �ȹް� ��ĭ ���ִ°ɷ� �ʱ�ȭ�س����� no big deal

	struct DynArrayQueue* Q = malloc(sizeof(struct DynArrayQueue));
	if (!Q)	// malloc �� �ƴ��� �ȵƴ��� Ȯ���ϴ� if ��
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

	// ��κ��� ������̿� �ٸ�. ���� �߿��� �κ�
	if (Q->front > Q->rear) {
		for (int i = 0; i < Q->front; i++) {
			Q->array[i + size] = Q->array[i];
			// size �� realloc ���� old capacity �� ���Ѵ�
		}
		Q->rear = Q->rear + size;
	}
}

void EnQueue(struct DynArrayQueue* Q, int data) {
	if (IsFullQueue(Q)) 
		ResizeQueue(Q);	//  isempty isfull queuesize  �� �Ȱ��� �̺κ��� staticArray  �� �޶�
	Q->rear = (Q->rear + 1) % Q->capacity;
	Q->array[Q->rear] = data;
	if (Q->front == -1) {
		Q->front = Q->rear;
	}
}


int DeQueue(struct DynArrayQueue* Q) {

	int data = 0;	// �Ǵ� ť�� �������� �ʴ� �׸�
	if (IsEmptyQueue(Q)) {
		printf("Queue is Empty");
		return 0;
	}
	else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear) {	// data�� �ϳ��ۿ� ���ٴ� �Ҹ�(�̰� ���� empty �ɲ���)
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


//		���� ���� �迭 -> Queue �����ϱ�

/*
�������⵵(n���� ��ť ���꿡 ���Ͽ�)		O(n)

Enqueue �ð����⵵						O(1)(���)
Dequeue �ð����⵵						O(1)
QueueSize �ð����⵵						O(1)
IsEmptyQueue �ð����⵵					O(1)
IsFullQueue �ð����⵵					O(1)
DeleteQueue �ð����⵵					O(1)


DeleteQueue �� O(1) �� ���� : �ѹ��� ������ �迭 ����� �ֱ� ������
*/