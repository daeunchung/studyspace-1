#include <stdio.h>
#include <stdlib.h>

struct  ListNode
{
	int data;
	struct ListNode* next;
};


void InsertInLinkedList(struct ListNode** h, int data, int position) {
	int k = 1;
	struct ListNode *p, *q, *newNode;

	newNode = (ListNode*)malloc(sizeof(struct ListNode));

	if (!newNode) {	// 항상 메모리 에러를 확인해야 합니다		//혹시 그전에  메모리를 꽉차게 써서 malloc 안될수 있으니
		printf(" 메모리 에러 ");
		return;
	}

	newNode->data = data;
	p = *h;

	if (position == 1) {	// 가장 처음에 노드를 추가
		newNode->next = p;
		*h = newNode;
	}
	else {	//position-1까지 진행한다
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL) {	// 가장 끝에 노드 삽입한다
			q->next = newNode;
			newNode->next = p;
		}
		else {	// 중간에 노드를 추가한다
			q->next = newNode;
			newNode->next = p;
		}
	}
}

void DeleteNodeFromLinkedList(struct ListNode** h, int position) {
	int k = 1;
	struct ListNode *p, *q;
	if (*h == NULL) {
		printf("List Empty");
		return;
	}
	p = *h;
	if (position == 1) {	// 리스트 가장 앞에서 삭제
		//p = *h;
		*h = *h->next;
		free(p);
		return;
	}
	else {
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}

		if (p == NULL) {	// 리스트에 없는 항목을 삭제하는 경우
			printf("Position does not exist ");
		}
		else {				// 리스트 중간 또는 맨끝을 삭제하는 경우
			q->next = p->next;
			free(p);
		}
		
	}
}

void DeleteLinkedList(struct ListNode ** h) {
	struct ListNode* auxilaryNode, *iterator;
	iterator = *h;

	while (iterator) {	// 0이면 false, 0아니면 true ( 포인터든 뭐든 다 들어갈 수 있어)
		//					iter가 뒤, auxilary가 앞에꺼로 고려
		auxilaryNode = iterator->next;
		free(iterator);
		iterator = auxilaryNode;
	}
	*h = NULL;	// 호출한 함수의 진짜 '머리'노드 포인터에 영향을 주기 위해
}

void main() {

	InsertInLinkedList(&head, 10, 1);
	InsertInLinkedList(&head, 70, 4);
	InsertInLinkedList(&head, 25, 2);

	DeleteNodeFromLinkedList(&head, 1);

	DeleteLinkedList(&head);

}


//	시간 복잡도 : 최악의 경우에 노드를 리스트의 가장 끝에 추가해야함. 끝노드 찾아가려면 while문 n번 돌아 => O(n) 

//				 최악의 경우에 노드를 리스트의 맨 마지막의 노드를 삭제해야할 수도 있다.

//	공간 복잡도 : Linkedlist의 메모리는 이미 주어진거니 삽입시 필요한 변수는  
//				int k, struct ListNode *p, *q, *newNode; 이렇게 4개와 newNode 메모리 8byte => 상수배 O(1)

//				 삭제때도 마찬가지. 변수만 생성하기 때문
