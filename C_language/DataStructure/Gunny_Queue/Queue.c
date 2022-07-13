#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ť (front �� rear �� ���� Top Bottom �� ������ �Ͽ� ����� ������ ����+�����ϴ� �ڷᱸ��)
// ���� ���Ḯ��Ʈ�� ť �ڵ�

typedef struct qNode
{
	char* data;
	struct qNode* next;

}Node;

typedef struct ListQueue
{
	Node* Front;
	Node* Rear;
	int size;
}listQueue;

void createQueue(listQueue** Queue) {

	(*Queue) = (listQueue*)malloc(sizeof(listQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->size = 0;

}

Node* createNode(char* Data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = (char*)malloc(sizeof(Data) + 1);	// null terminator, zero terminator ������ +1 ��ŭ

	//insert data
	strcpy(newNode->data , Data);
	newNode->next = NULL;

	return newNode;
}

void deleteNode(Node* removeNode) {
	free(removeNode->data);
	free(removeNode);
}

// Queue �� Top �� ������ ��¦ ���ĸ� ���� �Լ�
Node* Peek(listQueue* Queue) {
	return Queue->Front;
}

void Enqueue(listQueue* Queue, Node* newNode) {

	// if queue is empty
	if (Queue->size == 0) {
		Queue->Front = newNode;
		Queue->Rear = newNode;

	}
	// if queue is not empty - 1 or more data inside queue
	else {
		Queue->Rear->next = newNode;
		Queue->Rear = newNode;
	}
	Queue->size++;
}


// Dequeue�� Node ��ȯ����� �ϴµ� ����� �� �ְ� ������ ������(������ front return) index�ʿ���� Queue �� �־��ָ� �ȴ�
Node* Dequeue(listQueue* Queue) {

	// 1. ��� �������϶�
	// 2. ��尡 �Ѱ��϶� (front �� rear �� �ѳ��϶�) 
	// 3. ��尡 ������

	Node* tempNode = Queue->Front;
	if (Queue->size == 0) {
		printf("\ndon't call me");
		return NULL;
	}
	else if (Queue->size == 1) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
		Queue->size--;
	}
	else {
		Queue->Front = Queue->Front->next;
		Queue->size--;
	}

	return tempNode;

}

void deleteQueue(listQueue* Queue) {
	int count = Queue->size;

	while (count-- != 0) {

		Node* temp = Dequeue(Queue);
		printf("\n Dequeued node data %s\n", temp->data);
		deleteNode(temp);
	}
	free(Queue);
}




main() {
	int i;
	listQueue* Queue;

	// Queue Creation
	createQueue(&Queue);

	// Insert Nodes
	Enqueue(Queue, createNode("a"));
	Enqueue(Queue, createNode("b"));
	Enqueue(Queue, createNode("c"));
	Enqueue(Queue, createNode("d"));

	// Whos at peek?
	Node* temp1 = Peek(Queue);

	printf("%s <-- this guy is at front of the queue\n", temp1->data);

	// print current states of the queue
	printf("\n--Current Queue--[size:%d]\n\n", Queue->size);
	printf("\nfront is : [%s]\n", Queue->Front->data);
	printf("\nrear is : [%s]\n", Queue->Rear->data);


	Node* horse = Queue->Front;	// ���� �Ѹ��� ���� front �� �ް�� for�� ���鼭 �����ִ��� �˷��ִ� ������ 

	for (i = 0; i < (Queue->size); i++) {
		printf("%s\n", horse->data);
		horse = horse->next;
	}

	horse = Dequeue(Queue);		// a �̰�
	horse = Dequeue(Queue);		// b �̰�

	printf("\n--Current Queue--[size:%d]\n\n", Queue->size);
	 horse = Queue->Front;	
	for (i = 0; i < (Queue->size); i++) {
		printf("%s\n", horse->data);
		horse = horse->next;
	}
	horse = Dequeue(Queue);		// c �̰�
	horse = Dequeue(Queue);		// d �̰�

	deleteQueue(Queue);
	printf("\nQueue has been completely freed\n");

	return 0;
} 