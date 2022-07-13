// === [���� �̸�] ===

//	list.h
// ===================

#include <stdio.h>
#include <Windows.h>
struct Node {
	int data;
	Node * next;
};

struct  List
{
	int count;
	Node * head;
};

List* create_list() {
	List* list = new List();
	memset(list, 0, sizeof(list));
	return list;
}

void print_data(List * list) {
	int count = list->count;
	Node * pre = list->head;
	for (int i = 0; i < count; i++) {
		printf("��� : %d", pre->data);
		printf("\n");
		pre = pre->next;
	}
}

// 1. �߰�
void push_back(List* list, int data) {
	Node* node = new Node;
	node->data = data;
	node->next = 0;
	int count = list->count;
	Node* pre = list->head;
	if (count == 0) {
		list->head = node;
	}
	else if (count > 0) {
		for (int i = 0; i < count - 1; i++) {
			pre = pre->next;
		}// for�� �� ���� ������ pre�� ������ ��带 ����Ű�� �ִ�
		pre->next = node;
	}
	list->count += 1;
}

// 2. ����
void remove_index(List * list, int pos) {
	if (list->count <= 0) return;
	if (pos >= list->count) return;
	Node* pre = list->head;
	Node* del = 0;
	if (pos == 0) {
		del = pre;
		list->head = del->next;
	}
	else if (pos > 0) {
		for (int i = 0; i < pos - 1; i++) {
			pre = pre->next;
		}
		del = pre->next;
		pre->next = del->next;
	}
	list->count -= 1;
	delete del;
}

// 3. ����
void sort_list(List * list) {
	int count = list->count;
	Node * head = list->head;	// List�� ���� ù��带 head��

	for (int i = 0; i < count; i++) {
		int max = head->data;	// List�� ���� ù��� ���� max��
		Node * temp = head;		// List�� ���� ù��� �ּҸ� temp��
		Node * max_node = temp;	// List�� ���� ù��� �ּҸ� max_node��
		for (int n = i; n < count; n++) {
			if (temp->data < max) {	// ������尡 ���� �ִ밪���� ������
				max = head->data;
				max_node = temp;
			}
			temp = temp->next;	// temp�� ��������ּҷ� ����
		}

		int data;
		data = max_node->data;
		max_node->data = head->data;
		head->data = data;
		head = head->next;
	}
}