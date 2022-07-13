/* 


			static array �� �̿��� Queue


													*/

#include <stdio.h>
#include <stdlib.h>

// �ڿ����� �� �������� ���� �ڷᱸ�� : Queue

struct ArrayQueue
{
	int front, rear;
	int capacity;
	int* array;
};

struct ArrayQueue* Queue(int size)
{
	struct ArrayQueue* Q = malloc(sizeof(struct ArrayQueue));
	if (!Q) {	// Ȥ�� ������� Q ����������� ����ó�� if ��
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

int IsEmptyQueue(struct ArrayQueue * Q) { // empty �̸� front rear �Ѵ� -1�̴ϱ�
	// ������ ���̸� 1�̰� �ƴϸ� 0�� ���ϵȴ�
	return((Q->front) == -1);

	// front�� -1�ε� rear �� �ٸ������� ���� ����. �Ұ�����.
	// �׷��ϱ� front �� -1 �̸� �翬�� rear �� -1 �ϲ��� front �� -1�̸� empty��°�
}

int IsFullQueue(struct ArrayQueue* Q) {
	// ������ ���̸� 1�� ���ϵǰ� �ƴϸ� 0�� ���ϵȴ�
	return((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(struct ArrayQueue* Q) {	// rear �� ������ , ������(�ѹ��� �� ������) �̵� �� �� ����Ǵ� ����
	return(Q->capacity) + (Q->rear) - (Q->front) + 1 % Q->capacity;

	// �Ǵ� ( rear + capacity - front + 1 ) % capacity;
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

void DeleteQueue(struct ArrayQueue *Q) {
	if (Q)
		free(Q->array);
	free(Q);
}


/*
- ����
O(n)���� ��� constant time O(1) �ȿ� ���� �� �ִ� �͵� �̴�

- �Ѱ�
ť�� �ִ� ũ�Ⱑ �̸� �������� �ϰ� �ٲ� �� ����.
�� �� ť�� �׸��� ��ť�Ϸ��� �� �������� ���õ� ����(overflow)�� �߻��Ѵ�.


ť�� �����ϴµ� ���� ���ϰ� ���Ǵ� �����
	������ ���� �迭�� ������ ����
	���� ���� �迭�� ������ ����
	���� ����Ʈ ����

	�� �����迭�� ����ϴ°� -> �迭�� ���� ������ ����Ǵ� ���� ������ �⺻ �迭�� ť ������ �������ϴ�.


*/

