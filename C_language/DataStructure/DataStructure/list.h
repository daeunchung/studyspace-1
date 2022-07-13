// === [파일 이름] ===

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
		printf("출력 : %d", pre->data);
		printf("\n");
		pre = pre->next;
	}
}

// 1. 추가
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
		}// for문 다 돌면 마지막 pre가 마지막 노드를 가리키고 있다
		pre->next = node;
	}
	list->count += 1;
}

// 2. 삭제
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

// 3. 정렬
void sort_list(List * list) {
	int count = list->count;
	Node * head = list->head;	// List의 가장 첫노드를 head로

	for (int i = 0; i < count; i++) {
		int max = head->data;	// List의 가장 첫노드 값을 max로
		Node * temp = head;		// List의 가장 첫노드 주소를 temp로
		Node * max_node = temp;	// List의 가장 첫노드 주소를 max_node로
		for (int n = i; n < count; n++) {
			if (temp->data < max) {	// 다음노드가 현재 최대값보다 작으면
				max = head->data;
				max_node = temp;
			}
			temp = temp->next;	// temp가 다음노드주소로 변경
		}

		int data;
		data = max_node->data;
		max_node->data = head->data;
		head->data = data;
		head = head->next;
	}
}