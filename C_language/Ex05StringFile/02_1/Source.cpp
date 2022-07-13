#include <Windows.h>
#include <stdio.h>

struct Student {
	int* score;
	int size;
};

void print_user(Student* p, int count) {
	for (int i = 0; i<count; i++) {
		printf("[%d]", i);
		for (int j = 0; j<p[i].size; j++) {
			printf("%d ", p[i].score[j]);
		}
		printf("\n");
	}
	printf("\n");
}

Student* insert_user(Student* p, int* count) {
	if (count[0] == 0) {
		p = new Student[count[0] + 1];
	}
	else if (count[0] > 0) {
		Student* tmp = p;

		p = new Student[count[0] + 1];
		for (int i = 0; i<count[0]; i++) {
			p[i].score = tmp[i].score;
			p[i].size = tmp[i].size;
		}
	}

	printf("과목 수를 입력하세요 : ");
	scanf_s("%d", &p[count[0]].size);

	p[count[0]].score = new int[p[count[0]].size];

	for (int i = 0; i<p[count[0]].size; i++) {
		printf("%d번 과목 점수를 입력하세요 : ", i + 1);
		scanf_s("%d", &p[count[0]].score[i]);
	}

	count[0] += 1;

	return p;
}

void delete_user(Student** pp, int* count) {
	printf("삭제할 번호를 입력하세요 : ");
	int del_idx = 0;
	scanf_s("%d", &del_idx);

	if (count[0] == 1) {
		pp[0] = 0;
	}
	else if (count[0] > 1) {
		Student* temp = pp[0];

		pp[0] = new Student[count[0] - 1];

		int j = 0;
		for (int i = 0; i<count[0]; i++) {
			if (i != del_idx) {
				pp[0][j].score = temp[i].score;
				pp[0][j].size = temp[i].size;
				j += 1;
			}
		}

		delete[] temp[del_idx].score;
		delete[] temp;
	}

	count[0] -= 1;
}

void main() {

	Student * p = 0;
	int count = 0;

	int run = 1;
	while (run == 1) {
		print_user(p, count);

		printf("1.추가 2.삭제 3.출력");
		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 1) { p = insert_user(p, &count); }
		else if (sel == 2) { delete_user(&p, &count); }
		else if (sel == 3) { print_user(p, count); }
	}

	system("pause");
}
