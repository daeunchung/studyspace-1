#define _CRT_SECURE_NO_WARNINGS
// === [파일 이름] ===
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
			printf("삽입할 인덱스를 입력하세요 >> ");
			int index; scanf_s("%d", &index);
			InsertList(list, index);
		}
		else if (sel == 3) {
			printf("점수를 수정할 과목의 인덱스를 입력하세요 >> ");
			int index; scanf_s("%d", &index);
			UpdateList(list, index);
		}
		else if (sel == 4) {
			printf("삭제할 인덱스를 입력하세요 >>");
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
