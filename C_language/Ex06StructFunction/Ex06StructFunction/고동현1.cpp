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

		printf("%d번재 학생 학번 입력 : ", i+1);
		scanf_s("%s", s[i].no, 10);
		printf("이름 입력 : ");
		scanf_s("%s\n", s[i].name, 20);
		printf("점수 입력 : ");
		scanf_s("%d\n", &s[i].total);
	}
	printf("\n");

	printf("학생정보를 출력");

	for (int i = 0; i < 3; i++) {

		printf("학번:%s, 이름:%s 총점:%d \n", s[i].no, s[i].name, s[i].total);
		printf("\n");
	}

}