#include <Windows.h>
#include <stdio.h>
#include <time.h>

void main() {
	srand(time(0));

	// �й� ���� ����

	int** pp = 0;
	int count = 0;
	int num = 0;

	int run = 1;
	while (run) {
		printf("�й�\t����\t����\n");
		for (int i = 0; i < count; i++) {
			printf("[%d] > %d��\t%d��\n", pp[i][0], pp[i][1], pp[i][2]);
		}

		printf("[1]�߰�\n");
		printf("[2]����\n");
		printf("�޴� ���� : ");
		int choice = 0;
		scanf_s("%d", &choice);

		if (choice == 1) {
			if (count == 0) {
				pp = (int**)malloc(sizeof(int*) * 1);

				pp[0] = (int*)malloc(sizeof(int) * 3);
			}
			else if (count > 0) {
				int** temp = pp;

				pp = (int**)malloc(sizeof(int*)*(count + 1));
				for (int i = 0; i < count; i++) {
					pp[i] = temp[i];
				}
				free(temp);

				pp[count] = (int*)malloc(sizeof(int) * 3);

			}
			int hakbun = 1000 + num;
			int kor = rand() % 100 + 1;
			int eng = rand() % 100 + 1;

			pp[count][0] = hakbun;
			pp[count][1] = kor;
			pp[count][2] = eng;

			count++; num++;

		}
		else if (choice == 2) {
			printf("������ �й��� �Է��ϼ��� : ");
			int del_hakbun = 0;
			scanf_s("%d", &del_hakbun);

			int del_idx = -1;
			for (int i = 0; i < count; i++) {
				if (pp[i][0] == del_hakbun) {
					del_idx = i;
				}
			}

			if (del_idx == -1) {
				printf("�ش� �й��� �������� �ʽ��ϴ�.\n");
				continue;
			}

			if (count == 1) {
				pp = 0;
				count = 0;
				num = 0;
			}
			else if (count > 1) {
				int** temp = pp;

				pp = (int**)malloc(sizeof(int*)*(count - 1));
				int j = 0;
				for (int i = 0; i < count; i++) {
					if (i != del_idx) {
						pp[j] = temp[i];
						j++;
					}
				}
				free(temp[del_idx]);		// Ű����Ʈ (�׸��׸����־����)
				free(temp);
			}
			count--;
		}
	}
	system("pause");
}