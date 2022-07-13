#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
# ���� ��Ʈ�ѷ�[����ü(����+�Լ�) ����]
*/

struct Vector {
	int* arr;
	int cnt;

	void print_menu() {
		printf("1.�߰��ϱ�\n");
		printf("2.�����ϱ�\n");
		printf("3.�����ϱ�\n");
		printf("4.�����ϱ�\n");
		printf("5.�����ϱ�\n");
		printf("6.�ε��ϱ�\n");
		printf("0.�����ϱ�\n");
	}

	void init() {
		arr = 0;
		cnt = 0;
	}

	void show_all() {
		if (cnt != 0) {
			for (int i = 0; i < cnt; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
	}

	void add() {		// 1.
		int add_num = 0;
		printf("�߰��� ���� �Է� : ");
		scanf_s("%d", &add_num);

		if (cnt == 0) {
			arr = new int[cnt + 1];
		}
		else if (cnt > 0) {
			int* tmp = arr;
			arr = new int[cnt + 1];

			for (int i = 0; i < cnt; i++) {
				arr[i] = tmp[i];
			}
			delete[] tmp;
		}
		arr[cnt] = add_num;
		cnt += 1;
	}

	void del() {		// 2.
		int del_num = 0;
		printf("������ ���� �Է� : ");
		scanf_s("%d", &del_num);

		int check = -1;
		for (int i = 0; i < cnt; i++) {
			if (arr[i] == del_num) {
				check = i;
			}
		}
		if (check == -1) {
			printf("�Է��Ͻ� ���� �������� �ʽ��ϴ�.\n");
			return;		// ��ȯ���� void�ϱ� �Լ������� ������
		}

		if (cnt == 1) {
			arr = 0;
		}
		else if (cnt > 1) {
			int* tmp = arr;
			arr = new int[cnt - 1];

			int j = 0;
			for (int i = 0; i < cnt; i++) {
				if (i != check) {
					arr[j] = tmp[i];
					j += 1;
				}
			}
			delete[] tmp;
		}
		cnt -= 1;
	}

	void insert() {		// 3.
		int insert_idx = 0;
		printf("������ ��ġ�� �Է� : ");
		scanf_s("%d", &insert_idx);

		if (cnt < insert_idx || insert_idx < 0) {
			printf("�ش� ��ġ���� ������ �� �����ϴ�.\n");
			return;
		}

		int insert_num = 0; 
		printf("������ ���� �Է� : ");
		scanf_s("%d", &insert_num);

		if (cnt == 0) {
			arr = new int[cnt + 1];
		}
		else if (cnt > 0) {
			int* tmp = arr;
			arr = new int[cnt + 1];
			
			int j = 0;
			for (int i = 0; i < cnt + 1; i++) {
				if (i != insert_idx) {
					arr[i] = tmp[j];
					j += 1;
				}
			}
			delete[] tmp;
		}
		arr[insert_idx] = insert_num;
		cnt += 1;
	}

	void sort() {		// 4.
		for (int i = 0; i < cnt; i++) {
			int max_num = arr[i];
			int max_idx = i;
			for (int j = i; j < cnt; j++) {
				if (max_num < arr[j]) {
					max_num = arr[j];
					max_idx = j;
				}
			}
			int tmp = arr[i];
			arr[i] = arr[max_idx];
			arr[max_idx] = tmp;
		}
	}

	void save() {		// 5. ���ڿ� -> ���� (����)		WRITE TEXT => fputs
		char data[100] = { 0 };
		//{ cnt,arr[0]/arr[1]/.../arr[count-1] }

		_itoa_s(cnt, data, 10);
		strcat(data, ",");

		for (int i = 0; i < cnt; i++) {
			char tmp[100] = { 0 };
			_itoa_s(arr[i], tmp, 10);
			strcat(data, tmp);
			if (i != cnt - 1) {
				strcat(data, "/");
			}
		}
		printf(data);

		FILE * f = NULL;
		fopen_s(&f, "ex11.txt", "wt");
		fputs(data, f);
		fclose(f);
		printf("������ �Ϸ��Ͽ����ϴ�.\n");

	}

	void load() {		// 6. ���� -> ���ڿ� (�ҷ�����)		READ TEXT => fgets
		char data[100] = { 0 };

		FILE * f = NULL;
		fopen_s(&f, "ex11.txt", "rt");
		if (f != NULL) {
			fgets(data, 100, f);
			fclose(f);

			char* front = { 0 };
			char* end = { 0 };

			front = strtok_s(data, ",", &end); 
			cnt = atoi(front);

			arr = new int[cnt];
			for (int i = 0; i < cnt; i++) {
				front = strtok_s(end, "/", &end);
				arr[i] = atoi(front);
			}
		}
	}

	void run() {
		init();
		while (1) {

			show_all();
			print_menu();

			int choice = 0;
			printf("�޴� ���� : ");
			scanf_s("%d", &choice);

			if (choice == 1) { add(); }
			else if (choice == 2) { del(); }
			else if (choice == 3) { insert(); }
			else if (choice == 4) { sort(); }
			else if (choice == 5) { save(); }
			else if (choice == 6) { load(); }
			else if (choice == 0) { 
				printf("���α׷� ����\n");	break;
			}
		}
	}
};

void main() {

	Vector v = { 0 };
	v.run();
	system("pause");

}
