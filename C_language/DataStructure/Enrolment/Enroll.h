#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string.h>
struct Subject {
	char * name;	// 과목명
	int point;		// 학점
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

	// 수강신청으로 바꿔보세요~!
	printf("=== 링크드 리스트 ===\n");
	printf("[1] AppendList(추가)\n");
	printf("[2] InsertList(삽입)\n");
	printf("[3] UpdateList(수정)\n");
	printf("[4] DeleteList(삭제)\n");
	printf("[5] SearchList(검색)\n");
	printf("[6] DisplayList(출력)\n");
	printf("[0] QuitList(종료)\n");

}

// [1] 추가
void AppendList(List* list) {	
	Node * node = new Node();

	printf("과목명을 입력하세요 >> ");
	char name[100] = { 0 };
	scanf_s("%s", name, 100);
	int len = strlen(name);

	node->data.name = new char[len + 1];
	strcpy_s(node->data.name, len + 1, name);

	printf("점수를 입력하세요 >> ");
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

// [2] 삽입
void InsertList(List * list, int idx) {
	int count = list->count;
	//if (count == 0) {
	//	printf("[메세지] 항목이 0개라 삽입이 불가능합니다. 먼저 추가하세요\n");
	//	return;
	//}

	Node * node = new Node();
	printf("과목명을 입력하세요 >> ");
	char name[100] = { 0 };
	scanf_s("%s", name, 100);

	int len = strlen(name);
	node->data.name = new char[len + 1];
	strcpy_s(node->data.name, len + 1, name);

	printf("점수를 입력하세요 >> ");
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

// [3] 수정
void UpdateList(List * list, int idx) {
	Node * pre = list->head;

	printf("수정할 점수를 입력하세요 >> ");
	int score;  scanf_s("%d", &score);

	for (int i = 0; i < idx; i++) {
		pre = pre->next;
	}
	pre->data.point = score;
}

// [4] 삭제
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

// [5] 검색
void SearchList(List * list) {
	int count = list->count;
	Node * pre = list->head;

	char p[100] = { 0 };
	printf("검색할 과목명을 입력하세요 >> ");
	scanf("%s", p);
	
	int len = strlen(p);
	char* pp = new char[len + 1];
	strcpy_s(pp, len + 1, p);

	for (int i = 0; i < count - 1; i++) {
		if (strcmp(pp, pre->data.name) == 0) {
			printf("해당 과목의 점수는 %d점 입니다.\n", pre->data.point);
			break;
		}
		pre = pre->next;
	}
}

// [6] 출력
void DisplayList(List * list) {
	int count = list->count;
	Node* pre = list->head;
	for (int i = 0; i < count; i++) {
		printf("%s(%d점)\n", pre->data.name, pre->data.point);
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
