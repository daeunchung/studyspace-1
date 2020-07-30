#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 큐 (front 와 rear 가 각각 Top Bottom 을 포인팅 하여 입출력 순서를 제한+관리하는 자료구조)
// 단일 연결리스트로 큐 코딩

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

	newNode->data = (char*)malloc(sizeof(Data) + 1);	// null terminator, zero terminator 때문에 +1 만큼

	//insert data
	strcpy(newNode->data , Data);
	newNode->next = NULL;

	return newNode;
}

void deleteNode(Node* removeNode) {
	free(removeNode->data);
	free(removeNode);
}

// Queue 의 Top 이 누구냐 살짝 훔쳐만 보는 함수
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


// Dequeue는 Node 반환해줘야 하는데 빼줘야 할 애가 정해져 있으니(무조건 front return) index필요없고 Queue 만 넣어주면 된다
Node* Dequeue(listQueue* Queue) {

	// 1. 노드 여러개일때
	// 2. 노드가 한개일때 (front 도 rear 도 한놈일때) 
	// 3. 노드가 없을때

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


	Node* horse = Queue->Front;	// 말을 한마리 만들어서 front 를 받고는 for문 돌면서 누구있는지 알려주는 식으로 

	for (i = 0; i < (Queue->size); i++) {
		printf("%s\n", horse->data);
		horse = horse->next;
	}

	horse = Dequeue(Queue);		// a 뽑고
	horse = Dequeue(Queue);		// b 뽑고

	printf("\n--Current Queue--[size:%d]\n\n", Queue->size);
	 horse = Queue->Front;	
	for (i = 0; i < (Queue->size); i++) {
		printf("%s\n", horse->data);
		horse = horse->next;
	}
	horse = Dequeue(Queue);		// c 뽑고
	horse = Dequeue(Queue);		// d 뽑고

	deleteQueue(Queue);
	printf("\nQueue has been completely freed\n");

	return 0;
} 