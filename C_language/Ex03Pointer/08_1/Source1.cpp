#include <Windows.h>
#include <stdio.h>
#include <time.h>

void main() {

	srand(time(0));

	// �й�  ����   ����

	int** pp = 0;
	int count = 0;

	int num = 0;

	int run = 1;
	while (run) {
		printf("�й�\t����\t����\n");
		for (int i = 0; i<count; i++) {
			printf("[%d] > %d��\t%d��\n", pp[i][0], pp[i][1], pp[i][2]);
		}

		printf("[1]�߰�\n");
		printf("[2]����\n");

		printf("�޴� ���� : ");
		int choice = 0;
		scanf_s("%d", &choice);

		if (choice == 1) {
		}
		else if (choice == 2) {
		}
	}

	system("pause");
}
