#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 단일 연결리스트로 스택 코딩

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

// Stack 에 영혼 넣기 ( 메모리 넣어주기, 할당하기)
void createStack(listStack** Stack) {

	(*Stack) = (listStack*)malloc(sizeof(listStack));

	(*Stack)->peek = NULL;
	(*Stack)->size = 0;

}


// Node 에 영혼 넣기 (메모리 넣어주기)
Node* createNode(char* newChar) {

	//1. 노드 생성후 메모리 할당
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = (char*)malloc(strlen((newChar) + 1));

	// data에 문자열을 copy
	strcpy(newNode->data, newChar);
	newNode->next = NULL;
}

// Node 메모리 죽이기
void deleteNode(Node* removeNode) {

	free(removeNode->data);
	free(removeNode);
	// 내용 지우고 노드 지우고 둘 다 해줘야함
}

Node* Pop(listStack* Stack) {	// 내가 입력한(이 스택) 중에 가장 마지막 놈(노드) 꺼내서 반환해줘

	Node* tempNode;
	// when stack is empty
	if (Stack->size == 0) {
		printf("hey!!! stack is empty\n");
		tempNode = NULL;
	}
	// when stack is not empty
	else {
		tempNode = Stack->peek;

		// daeun 코드  // 노드에 peek을 넣어주느냐(X),  (방향이 이렇게 중요합니다_)
		//Stack->peek->next = Stack->peek;	

		//정답코드는 이거 (최상단 노드를 가리키는peek 을 다음 노드로 이동시킨다.)  peek에 노드를 넣어주느냐(O)
		Stack->peek = Stack->peek->next;

		Stack->size--;


	}
	return tempNode;

	//free(tempNode);		// deleteStack함수에서 해줍니다. 
}



// Stack 메모리 죽이기 ( Stack 속 Node들 싹 다 지우고 Stack본인도 죽이는 암살자 ㅋㅋㅋㅋ 함수)
void deleteStack(listStack* Stack) {

	// Stack 안에 Node 몇개 있는지 모르니까 일단 변수로 만들어서 받자
	int count = Stack->size;
	int i;
	Node* tempNode;

	// for문 돌면서 Node 다 죽이고
	for (i = 0; i < count; i++) {
		tempNode = Pop(Stack);	// 최상위 노드 살짝쿵 불러내서 (Pop함수에 다음놈을 새 peek로 임명해 주는 기능까지 다 들어있음)
		deleteNode(tempNode);	// 바~로 죽여버림 ㅋㅋㅋ
		//free(tempNode->data);
		//free(tempNode);
	}

	// 마지막으로 Stack 도 죽여주기
	free(Stack);
}


// ** 여기부터 중요 함수		// (이 스택에, 이 노드 넣어줘)
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
	listStack* Stack;	// Stack 껍데기 만들기

	createStack(&Stack);	// 영혼 넣어주기
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
HEAP CORRUPTION DETECTED 오류와 해결방법

출처: https://bozeury.tistory.com/entry/HEAP-CORRUPTION-DETECTED-오류와-해결방법 
이 부분의 에러는 sizeof(Test)가 sizeof(Test*)보다 크기 때문에 일어나는 오류이다.
즉, 실제로 할당된 메모리의 크기는 sizeof(Test*)이지만
해제하려고 하는 메모리의 크기는 sizeof(Test)이기 때문에 Heap 에러가 나는 것이다.
그러므로 sizeof(Test*)를 sizeof(Test)로 바꾸면 해결 될 것이다.
*/