#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
	char no[10];
	char name[20];
	int total;
};


void main() {
	struct Student s[3];
	
	for (int i = 0; i < 3; i++) {

		printf("%d���� �л� �й� �Է� : ", i+1);
		scanf_s("%s", s[i].no, 10);
		printf("�̸� �Է� : ");
		scanf_s("%s\n", s[i].name, 20);
		printf("���� �Է� : ");
		scanf_s("%d\n", &s[i].total);
	}
	printf("\n");

	printf("�л������� ���");

	for (int i = 0; i < 3; i++) {

		printf("�й�:%s, �̸�:%s ����:%d \n", s[i].no, s[i].name, s[i].total);
		printf("\n");
	}

}