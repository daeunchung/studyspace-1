// 1. 노드 생성		2. 노드 찾기		3. 노드 삭제		4. 노드 추가		5. 중간에 추가

#include <stdlib.h>
#include <stdio.h>

typedef struct listNode {
	int Data;		// data field
	struct listNode * Next;
	struct listNode * Prev;
} Node;


// 노드 생성
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	// variables initialization
	newNode->Data = data;
	newNode->Next = NULL;
	newNode->Prev = NULL;

	return newNode;
}

void deleteNode(Node * Node) {
	free(Node);
}

int countNode(Node* head) {
	int count = 0;
	Node* horse = head;
	while (horse != NULL) {
		horse = horse->Next;
		count++;
	}
	return count;
}

Node* getNodeAt(Node* head, int index) {
	Node* horse = head;
	int count = 0;
	while (horse != NULL) {
		if (count++ == index) {
			return horse;
		}
		horse = horse->Next;
	}
	return NULL;
}

// 업데이트 해줘야 하기 때문에 더블 포인터로 받아온다

// 맨 끝에 노드 추가해주는 함수
void addNode(Node** head, Node* newNode) {
	// no list exists
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		Node* horse = (*head);

		while (horse->Next != NULL) {
			horse = horse->Next;
		}

		horse->Next = newNode;
		newNode->Prev = horse;
	}
}



// 중간에 노드 넣어주는 함수
// (어디 노드 뒤에 낄껀지, 집어넣을 새로 만들어진 노드 ) 두개 입력받기
void insertAfter(Node* Current, Node* newNode) {

	//	head ( 하나 딸랑 들어있던 상태에 새 노드 추가할때 )
	if (Current->Prev == NULL && Current->Next == NULL) {
		Current->Next = newNode;
		newNode->Prev = Current;
	}
	//	not head
		// if tail
		if (Current->Next == NULL) {
			Current->Next = newNode;
			newNode->Prev = Current;
		}
		// in the middle of 2 nodes
		else {
			// 다은 ver ( 결과 같게 잘 나왔음)
			newNode->Next = Current->Next;
			Current->Next->Prev = newNode;
			Current->Next = newNode;
			newNode->Prev = Current;

			// Gunny ver
			//Current->Next->Prev = newNode;
			//newNode->Prev = Current;
			//newNode->Next = Current->Next;
			//Current->Next = newNode;
		}
}

void removeNode(Node** head, Node* remove) {

	// 1. removeNode가 head일때
	if (*head == remove) {
		*head = (*head)->Next;
	}

	// 2. removeNode의 다음링크에 노드가 있을때
	if (remove->Next != NULL) {
		// Daeun
		//remove->Prev->Next = remove->Next;	// 틀렸음
		// Gunny
		remove->Next->Prev = remove->Prev;
	}
	// 3. removeNode의 이전링크에 노드가 있을때
	if (remove->Prev != NULL) {
		// Daeun
		//remove->Next->Prev = remove->Prev;	// 틀렸음
		// Gunny
		remove->Prev->Next = remove->Next;
	}

	deleteNode(remove);

}


main() {
	int i = 0;
	int count = 0;


	// future head
	Node* List = NULL;
	// temporary Node
	Node* newNode = NULL;
	// current Node
	Node* Curr = NULL;

	for (i = 0; i < 5; i++) {
		newNode = createNode(i);
		addNode(&List, newNode);
	}

	count = countNode(List);
	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);
	}
	printf("---------- 5 Nodes Created ------------\n");

	newNode = createNode(99);
	Curr = getNodeAt(List, 0);
	insertAfter(Curr, newNode);

	newNode = createNode(444);
	Curr = getNodeAt(List, 4);
	insertAfter(Curr, newNode);

	count = countNode(List);
	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);
	}
	printf("---------- 2 Nodes Inserted ------------\n");


	newNode = getNodeAt(List, 1);
	removeNode(&List, newNode);

	newNode = getNodeAt(List, 0);
	removeNode(&List, newNode);

	count = countNode(List);
	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);

	}
	printf("---------- After Node with index 1 removed ------------\n");

	//return 0;

}

