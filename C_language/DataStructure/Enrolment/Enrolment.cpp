#define _CRT_SECURE_NO_WARNINGS
// === [���� �̸�] ===
// Enrollment.cpp		 
//===================

#include "Enroll.h"

void main() {
	List * list = create_list();

	int run = 1;
	while (run == 1) {
		print_menu();
		int sel;  scanf("%d", &sel);

		if (sel == 0) break;
		if (sel == 1) {
			AppendList(list);
		}
		else if (sel == 2) {
			printf("������ �ε����� �Է��ϼ��� >> ");
			int index; scanf_s("%d", &index);
			InsertList(list, index);
		}
		else if (sel == 3) {
			printf("������ ������ ������ �ε����� �Է��ϼ��� >> ");
			int index; scanf_s("%d", &index);
			UpdateList(list, index);
		}
		else if (sel == 4) {
			printf("������ �ε����� �Է��ϼ��� >>");
			int index; scanf_s("%d", &index);
			DeleteList(list, index);
		}
		else if (sel == 5) {
			SearchList(list);
		}
		else if (sel == 6) {
			DisplayList(list);
		}
	}
}
