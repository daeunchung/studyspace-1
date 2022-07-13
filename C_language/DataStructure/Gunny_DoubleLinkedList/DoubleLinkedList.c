// 1. ��� ����		2. ��� ã��		3. ��� ����		4. ��� �߰�		5. �߰��� �߰�

#include <stdlib.h>
#include <stdio.h>

typedef struct listNode {
	int Data;		// data field
	struct listNode * Next;
	struct listNode * Prev;
} Node;


// ��� ����
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

// ������Ʈ ����� �ϱ� ������ ���� �����ͷ� �޾ƿ´�

// �� ���� ��� �߰����ִ� �Լ�
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



// �߰��� ��� �־��ִ� �Լ�
// (��� ��� �ڿ� ������, ������� ���� ������� ��� ) �ΰ� �Է¹ޱ�
void insertAfter(Node* Current, Node* newNode) {

	//	head ( �ϳ� ���� ����ִ� ���¿� �� ��� �߰��Ҷ� )
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
			// ���� ver ( ��� ���� �� ������)
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

	// 1. removeNode�� head�϶�
	if (*head == remove) {
		*head = (*head)->Next;
	}

	// 2. removeNode�� ������ũ�� ��尡 ������
	if (remove->Next != NULL) {
		// Daeun
		//remove->Prev->Next = remove->Next;	// Ʋ����
		// Gunny
		remove->Next->Prev = remove->Prev;
	}
	// 3. removeNode�� ������ũ�� ��尡 ������
	if (remove->Prev != NULL) {
		// Daeun
		//remove->Next->Prev = remove->Prev;	// Ʋ����
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
