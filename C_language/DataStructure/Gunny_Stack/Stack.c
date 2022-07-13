#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// ���� ���Ḯ��Ʈ�� ���� �ڵ�

typedef struct sNode
{
	char* data;
	struct sNode* next;

}Node;

typedef struct listStack
{
	Node* peek;
	int size;
}listStack;

// Stack �� ��ȥ �ֱ� ( �޸� �־��ֱ�, �Ҵ��ϱ�)
void createStack(listStack** Stack) {

	(*Stack) = (listStack*)malloc(sizeof(listStack));

	(*Stack)->peek = NULL;
	(*Stack)->size = 0;

}


// Node �� ��ȥ �ֱ� (�޸� �־��ֱ�)
Node* createNode(char* newChar) {

	//1. ��� ������ �޸� �Ҵ�
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = (char*)malloc(strlen((newChar) + 1));

	// data�� ���ڿ��� copy
	strcpy(newNode->data, newChar);
	newNode->next = NULL;
}

// Node �޸� ���̱�
void deleteNode(Node* removeNode) {

	free(removeNode->data);
	free(removeNode);
	// ���� ����� ��� ����� �� �� �������
}

Node* Pop(listStack* Stack) {	// ���� �Է���(�� ����) �߿� ���� ������ ��(���) ������ ��ȯ����

	Node* tempNode;
	// when stack is empty
	if (Stack->size == 0) {
		printf("hey!!! stack is empty\n");
		tempNode = NULL;
	}
	// when stack is not empty
	else {
		tempNode = Stack->peek;

		// daeun �ڵ�  // ��忡 peek�� �־��ִ���(X),  (������ �̷��� �߿��մϴ�_)
		//Stack->peek->next = Stack->peek;	

		//�����ڵ�� �̰� (�ֻ�� ��带 ����Ű��peek �� ���� ���� �̵���Ų��.)  peek�� ��带 �־��ִ���(O)
		Stack->peek = Stack->peek->next;

		Stack->size--;


	}
	return tempNode;

	//free(tempNode);		// deleteStack�Լ����� ���ݴϴ�. 
}



// Stack �޸� ���̱� ( Stack �� Node�� �� �� ����� Stack���ε� ���̴� �ϻ��� �������� �Լ�)
void deleteStack(listStack* Stack) {

	// Stack �ȿ� Node � �ִ��� �𸣴ϱ� �ϴ� ������ ���� ����
	int count = Stack->size;
	int i;
	Node* tempNode;

	// for�� ���鼭 Node �� ���̰�
	for (i = 0; i < count; i++) {
		tempNode = Pop(Stack);	// �ֻ��� ��� ��¦�� �ҷ����� (Pop�Լ��� �������� �� peek�� �Ӹ��� �ִ� ��ɱ��� �� �������)
		deleteNode(tempNode);	// ��~�� �׿����� ������
		//free(tempNode->data);
		//free(tempNode);
	}

	// ���������� Stack �� �׿��ֱ�
	free(Stack);
}


// ** ������� �߿� �Լ�		// (�� ���ÿ�, �� ��� �־���)
void Push(listStack* Stack, Node* newNode) {

	// when stack is empty ( peek == NULL || size == 0 )
	if (Stack->size == 0) {
		Stack->peek = newNode;
	}
	// when stack is not empty
	else {
		newNode->next = Stack->peek;
		Stack->peek = newNode;
	}
	Stack->size++;
}






main() {
	int i;
	listStack* Stack;	// Stack ������ �����

	createStack(&Stack);	// ��ȥ �־��ֱ�
	Push(Stack, createNode("a"));
	Push(Stack, createNode("b"));
	Push(Stack, createNode("c"));
	Push(Stack, createNode("d"));

	printf("abcd pushed\n");

	printf("\n -- Current Stack -- [size : %d]\n\n", Stack->size);
	Node* horse = Stack->peek;
	for (i = 0; i < Stack->size; i++) {
		printf("%s\n", horse->data);
		horse = horse->next;
	}

	horse = Pop(Stack);
	horse = Pop(Stack);

	printf("\n -- Current Stack -- [size : %d]\n\n", Stack->size);
	 horse = Stack->peek;
	for (i = 0; i < Stack->size; i++) {
		printf("%s\n", horse->data);
		horse = horse->next;
	}

	deleteStack(Stack);
	printf("\nStack has been completely freed\n");
}


/*
HEAP CORRUPTION DETECTED ������ �ذ���

��ó: https://bozeury.tistory.com/entry/HEAP-CORRUPTION-DETECTED-������-�ذ��� 
�� �κ��� ������ sizeof(Test)�� sizeof(Test*)���� ũ�� ������ �Ͼ�� �����̴�.
��, ������ �Ҵ�� �޸��� ũ��� sizeof(Test*)������
�����Ϸ��� �ϴ� �޸��� ũ��� sizeof(Test)�̱� ������ Heap ������ ���� ���̴�.
�׷��Ƿ� sizeof(Test*)�� sizeof(Test)�� �ٲٸ� �ذ� �� ���̴�.
*/