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

	printf("�й� �Է� : ");
	scanf_s("%s", s.no, 10);
	printf("%s\n", s.no);

	//char tmpno[10];
	//printf("�й� �Է� : ");
	//scanf_s("%s", tmpno, 10);
	//strcpy(s.no, tmpno);
	//printf("%s\n", tmpno);



	//for (int i = 0; i < count; i++) {
	//	//scanf_s("%s %s %lf", stu[i].no, stu[i].name, &stu[i].total);
	//	printf("%d��° �л� �й��Է� : ", (i + 1));

	//	char tmpno[20];
	//	scanf_s("%s", tmpno, 20);
	//	strcpy
	//	printf("�̸��Է� : ");
	//	scanf_s("%s", stu[i].name);
	//	printf("�����Է� : ");
	//	scanf_s("%d", &stu[i].total);
	//}

	//printf("\n");

	//printf("�л������� ���");

	//for (int i = 0; i < 3; i++) {

	//	printf("�й� : %d, �̸� :%d ����:%d \n", stu[i].no, stu[i].name, stu[i].total);
	//	printf("\n");
	//}

}