#include <stdio.h>
#include <Windows.h>
// ���⼺�� �ִ� Directed Graph �� Adjacency List�� ǥ���� �ڵ��ΰǰ� 

struct Node {
	int data;
	Node * next;
};
struct List {
	int count; Node head;
};
struct Graph {
	int count; List **pp_list;
};
List * CreateList() {
	List * list = new List;
	memset(list, 0, sizeof(List));
	return list;
}
void AddData(List * list, int pos, int data) {
	Node * node = new Node;
	node->data = data;
	Node * pre = &list->head;
	for (int i = 0; i < pos; i++) {
		pre = pre->next;
	}
	node->next = pre->next;
	pre->next = node;
	list->count += 1;
}
int GetData(List * list, int pos) {
	Node * pre = 
}
