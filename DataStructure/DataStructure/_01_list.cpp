#define _CRT_SECURE_NO_WARNINGS
// === [파일 이름] ===
// _01_list.cpp		 
//===================

#include "list.h"

void main() {
	List * list = create_list();

	int run = 1;
	while (run == 1) {
		print_data(list);
		printf("==== 링크드 리스트 ====");
		printf("\n");
		printf("1.추가 2.삭제 3.정렬 0.종료");
		printf("\n");
		int sel;  scanf("%d", &sel);

		if (sel == 0) break;
		if (sel == 1) {
			printf("값을 입력하세요 >> ");
			int data; scanf_s("%d", &data);
			push_back(list, data);
		}
		else if (sel == 2) {
			printf("인덱스를 입력하세요 >>");
			int index; scanf_s("%d", &index);
			remove_index(list, index);
		}
		else if (sel == 3) {
			sort_list(list);
		}
	}
}
