#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string.h>
struct Subject {
	char * name;	// �����
	int point;		// ����
};

struct Node {
	Subject data;
	Node * next;
};

struct List
{
	int count;
	Node * head;
};

List* create_list() {
	List * list = new List();
	memset(list, 0, sizeof(list));
	return list;
}

void print_menu() {

	// ������û���� �ٲ㺸����~!
	printf("=== ��ũ�� ����Ʈ ===\n");
	printf("[1] AppendList(�߰�)\n");
	printf("[2] InsertList(����)\n");
	printf("[3] UpdateList(����)\n");
	printf("[4] DeleteList(����)\n");
	printf("[5] SearchList(�˻�)\n");
	printf("[6] DisplayList(���)\n");
	printf("[0] QuitList(����)\n");

}

// [1] �߰�
void AppendList(List* list) {	
	Node * node = new Node();

	printf("������� �Է��ϼ��� >> ");
	char name[100] = { 0 };
	scanf_s("%s", name, 100);
	int len = strlen(name);

	node->data.name = new char[len + 1];
	strcpy_s(node->data.name, len + 1, name);

	printf("������ �Է��ϼ��� >> ");
	scanf_s("%d", &node->data.point);

	int count = list->count;
	Node * pre = list->head;

	if (count == 0) {
		list->head = node;
	}
	else if (count > 0) {
		for (int i = 0; i < count - 1; i++) {
			pre = pre->next;
		}
		pre->next = node;
	}
	list->count += 1;
}

// [2] ����
void InsertList(List * list, int idx) {
	int count = list->count;
	//if (count == 0) {
	//	printf("[�޼���] �׸��� 0���� ������ �Ұ����մϴ�. ���� �߰��ϼ���\n");
	//	return;
	//}

	Node * node = new Node();
	printf("������� �Է��ϼ��� >> ");
	char name[100] = { 0 };
	scanf_s("%s", name, 100);

	int len = strlen(name);
	node->data.name = new char[len + 1];
	strcpy_s(node->data.name, len + 1, name);

	printf("������ �Է��ϼ��� >> ");
	scanf_s("%d", &node->data.point);

	Node * pre = list->head;
	if (count > 0) {

		if (idx == 0) {
			node->next = pre;
			list->head = node;
		}
		else if (idx >= 1) {
			if (idx > 1) {
				for (int i = 0; i < idx - 1; i++) {
					pre = pre->next;
				}
			}
			node->next = pre->next;
			pre->next = node;
		}


	}
	list->count += 1;
}

// [3] ����
void UpdateList(List * list, int idx) {
	Node * pre = list->head;

	printf("������ ������ �Է��ϼ��� >> ");
	int score;  scanf_s("%d", &score);

	for (int i = 0; i < idx; i++) {
		pre = pre->next;
	}
	pre->data.point = score;
}

// [4] ����
void DeleteList(List * list, int index) {
	if (list->count <= 0) return;
	if (index >= list->count) return;
	Node * pre = list->head;
	Node * del = 0;

	if (index == 0) {
		del = pre;
		list->head = pre->next;
	}
	else if (index > 0) {
		for (int i = 0; i < index - 1; i++) {
			pre = pre->next;
		}
		del = pre->next;
		pre->next = del->next;
	}
	list->count -= 1;
	delete del;
}

// [5] �˻�
void SearchList(List * list) {
	int count = list->count;
	Node * pre = list->head;

	char p[100] = { 0 };
	printf("�˻��� ������� �Է��ϼ��� >> ");
	scanf("%s", p);
	
	int len = strlen(p);
	char* pp = new char[len + 1];
	strcpy_s(pp, len + 1, p);

	for (int i = 0; i < count - 1; i++) {
		if (strcmp(pp, pre->data.name) == 0) {
			printf("�ش� ������ ������ %d�� �Դϴ�.\n", pre->data.point);
			break;
		}
		pre = pre->next;
	}
}

// [6] ���
void DisplayList(List * list) {
	int count = list->count;
	Node* pre = list->head;
	for (int i = 0; i < count; i++) {
		printf("%s(%d��)\n", pre->data.name, pre->data.point);
		pre = pre->next;
	}
}

//void run() {
//
//	print_menu();
//
//}
//
//void main() {
//
//	run();
//
//	system("pause");
//}
