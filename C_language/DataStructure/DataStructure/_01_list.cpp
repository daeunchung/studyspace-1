#define _CRT_SECURE_NO_WARNINGS
// === [���� �̸�] ===
// _01_list.cpp		 
//===================

#include "list.h"

void main() {
	List * list = create_list();

	int run = 1;
	while (run == 1) {
		print_data(list);
		printf("==== ��ũ�� ����Ʈ ====");
		printf("\n");
		printf("1.�߰� 2.���� 3.���� 0.����");
		printf("\n");
		int sel;  scanf("%d", &sel);

		if (sel == 0) break;
		if (sel == 1) {
			printf("���� �Է��ϼ��� >> ");
			int data; scanf_s("%d", &data);
			push_back(list, data);
		}
		else if (sel == 2) {
			printf("�ε����� �Է��ϼ��� >>");
			int index; scanf_s("%d", &index);
			remove_index(list, index);
		}
		else if (sel == 3) {
			sort_list(list);
		}
	}
}
