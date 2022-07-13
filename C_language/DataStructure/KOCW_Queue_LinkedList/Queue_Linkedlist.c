
// LinkedList �� ����Ͽ� ������  Queue

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
	// ������ ���̸� 1, �����̸� 0 ����
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
	if (Q->rear != NULL) {	// �̳� �߿���.  Q->rear �� NULL�϶� Q->rear->next �� ������ �� ����
		Q->rear->next = newNode;
	}
	Q->rear = newNode;
	if (Q->front == NULL) {	// front �� �ƹ��͵� ������ ( ���� �ִ°� ó�����̸� )
		Q->front = Q->rear;	// �����ϴ� �� �ѳ𿡰� front�� rear�� ��� �־��ֱ� 
	}

}

int Dequeue(struct Queue* Q) {
	int data = 0; //	�Ǵ� ť�� �������� �ʴ� �׸�
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
�������⵵(n���� ��ť ���꿡 ���Ͽ�)		O(n)

Enqueue �ð����⵵						O(1)(���)
Dequeue �ð����⵵						O(1)
IsEmptyQueue �ð����⵵					O(1)
DeleteQueue �ð����⵵					O(n)	

DeleteQueue �� O(n) �� ���� : linkedlist�� �޸𸮰� �� �߰��߰� ��ѷ����ֱ⶧����
Ÿ��Ÿ�� �������鼭 �ϴϾ� ��������ؼ�

*/