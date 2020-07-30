#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct Student {
	char no[10];
	char name[20];
	int total;
};

int main() {
	struct Student s;

	printf("학번 입력 : ");
	scanf_s("%s", s.no, 10);
	printf("%s\n", s.no);

	//char tmpno[10];
	//printf("학번 입력 : ");
	//scanf_s("%s", tmpno, 10);
	//strcpy(s.no, tmpno);
	//printf("%s\n", tmpno);



	//for (int i = 0; i < count; i++) {
	//	//scanf_s("%s %s %lf", stu[i].no, stu[i].name, &stu[i].total);
	//	printf("%d번째 학생 학번입력 : ", (i + 1));

	//	char tmpno[20];
	//	scanf_s("%s", tmpno, 20);
	//	strcpy
	//	printf("이름입력 : ");
	//	scanf_s("%s", stu[i].name);
	//	printf("점수입력 : ");
	//	scanf_s("%d", &stu[i].total);
	//}

	//printf("\n");

	//printf("학생정보를 출력");

	//for (int i = 0; i < 3; i++) {

	//	printf("학번 : %d, 이름 :%d 총점:%d \n", stu[i].no, stu[i].name, stu[i].total);
	//	printf("\n");
	//}

}