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

	if (!newNode) {	// �׻� �޸� ������ Ȯ���ؾ� �մϴ�		//Ȥ�� ������  �޸𸮸� ������ �Ἥ malloc �ȵɼ� ������
		printf(" �޸� ���� ");
		return;
	}

	newNode->data = data;
	p = *h;

	if (position == 1) {	// ���� ó���� ��带 �߰�
		newNode->next = p;
		*h = newNode;
	}
	else {	//position-1���� �����Ѵ�
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL) {	// ���� ���� ��� �����Ѵ�
			q->next = newNode;
			newNode->next = p;
		}
		else {	// �߰��� ��带 �߰��Ѵ�
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
	if (position == 1) {	// ����Ʈ ���� �տ��� ����
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

		if (p == NULL) {	// ����Ʈ�� ���� �׸��� �����ϴ� ���
			printf("Position does not exist ");
		}
		else {				// ����Ʈ �߰� �Ǵ� �ǳ��� �����ϴ� ���
			q->next = p->next;
			free(p);
		}
		
	}
}

void DeleteLinkedList(struct ListNode ** h) {
	struct ListNode* auxilaryNode, *iterator;
	iterator = *h;

	while (iterator) {	// 0�̸� false, 0�ƴϸ� true ( �����͵� ���� �� �� �� �־�)
		//					iter�� ��, auxilary�� �տ����� ���
		auxilaryNode = iterator->next;
		free(iterator);
		iterator = auxilaryNode;
	}
	*h = NULL;	// ȣ���� �Լ��� ��¥ '�Ӹ�'��� �����Ϳ� ������ �ֱ� ����
}

void main() {

	InsertInLinkedList(&head, 10, 1);
	InsertInLinkedList(&head, 70, 4);
	InsertInLinkedList(&head, 25, 2);

	DeleteNodeFromLinkedList(&head, 1);

	DeleteLinkedList(&head);

}


//	�ð� ���⵵ : �־��� ��쿡 ��带 ����Ʈ�� ���� ���� �߰��ؾ���. ����� ã�ư����� while�� n�� ���� => O(n) 

//				 �־��� ��쿡 ��带 ����Ʈ�� �� �������� ��带 �����ؾ��� ���� �ִ�.

//	���� ���⵵ : Linkedlist�� �޸𸮴� �̹� �־����Ŵ� ���Խ� �ʿ��� ������  
//				int k, struct ListNode *p, *q, *newNode; �̷��� 4���� newNode �޸� 8byte => ����� O(1)

//				 �������� ��������. ������ �����ϱ� ����
