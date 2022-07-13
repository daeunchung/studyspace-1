#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
# ��ȭ�� ����
1. ȸ������
2. �α���
3. �α׾ƿ�
4. ����
5. �����ϱ�
6. �������
0. ����
*/

struct Client {
	char* id;
	char* pw;
	int money;
};

struct Movie {
	int cnt;
	Client* client;	// *ȸ������
	int* seat;		// *�¼� 

	int log;

	void print_all() {
		if (log == -1) {
			printf("�α׾ƿ� ����\n");
		}
		else {
			printf("%s �α��� ��...\n", client[log].id);
		}
		for (int i = 0; i < cnt; i++) {
			printf("ID[%s], PW[%s], Money[%d]\n", client[i].id, client[i].pw, client[i].money);
		}
	}

	void init() {
		cnt = 0;
		client = 0;
		seat = 0;
		log = -1;
		seat = new int[10];
		for (int i = 0; i < 10; i++) {
			seat[i] = -1;
		}
	}

	void print_menu() {
		printf("1. ȸ������\n");
		printf("2. �α���\n");
		printf("3. �α׾ƿ�\n");
		printf("4. ����\n");
		printf("5. �����ϱ�\n");
		printf("6. �������\n");
		printf("0. ����\n");
	}
	
	void member() {				// 1. ȸ������
		char id[100] = { 0 };
		printf("ID�� �Է��ϼ��� : ");
		scanf_s("%s", &id[0]);

		char pw[100] = { 0 };
		printf("PW�� �Է��ϼ��� : ");
		scanf_s("%s", &pw[0]);

		int money = 0;
		printf("������ �ݾ��� �Է��ϼ��� : ");
		scanf_s("%d", &money);

		if (cnt == 0) {
			client = new Client[cnt + 1];
		}
		else {
			Client* tmp = client;

			client = new Client[cnt + 1];		// ȸ�������ؼ� �� �� �Ѹ� ���ϱ� cnt + 1
			for (int i = 0; i < cnt; i++) {
				client[i] = tmp[i];
			}
			delete[] tmp;
		}

		//�����ͷ� ����Ű�� ������ ������ �޸� ũ�� (��ĭ ��)��ŭ �վ �ּ� �־��ִ°ž�
		int len = strlen(id);
		client[cnt].id = new char[len + 1];		// ���ڿ��� ������ ���� \0 �ڸ� ��ĭ �����ؼ� len + 1
		strcpy(client[cnt].id, id);

		len = strlen(pw);
		client[cnt].pw = new char[len + 1];		// �����͸� �޸� ���ֱ�
		strcpy(client[cnt].pw, pw);				// ���ڿ��̸� strcpy

		client[cnt].money = money;				// int �� �׳� �־��� ������

		cnt += 1;

		save();									// ������ �������� ������ �������
	}

	void login() {				// 2. �α���
		char id[100] = { 0 };
		printf("ID�� �Է��ϼ��� : ");
		scanf_s("%s", &id[0]);

		char pw[100] = { 0 };
		printf("PW�� �Է��ϼ��� : ");
		scanf_s("%s", &pw[0]);

		for (int i = 0; i < cnt; i++) {
			if (strcmp(id, client[i].id) == 0 && strcmp(pw, client[i].pw) == 0) {
				log = i;
			}
		}

		if (log == -1) {
			printf("ID�� PW�� Ȯ�����ּ���.\n");
		}
		else {
			printf("%s��, ȯ���մϴ�.\n", client[log].id);
		}
	}

	void logout() {				// 3. �α׾ƿ�
		if (log != -1) {
			log = -1;
			printf("�α׾ƿ� �Ǿ����ϴ�.\n");
		}
	}

	void add_money() {			// 4. ����
		if (log != -1) {
			int money = 0;
			printf("������ �ݾ��� �Է��ϼ��� : ");
			scanf_s("%d", &money);

			client[log].money += money;
			printf("������ �Ϸ��Ͽ����ϴ�.\n");
		}
		save();
	}

	void print_seat() {
		printf("[ ");
		for (int i = 0; i<10; i++) {
			if (seat[i] == -1) {
				printf("[ ] ");
			}
			else {
				printf("[%s] ", client[seat[i]].id);
			}
		}
		printf("]\n");
	}

	void set_seat() {			// 5. �����ϱ�
		if (log == -1) {
			print_seat();
			int sel = 0;
			printf("�¼���ȣ�� �Է��ϼ���[1~10] : ");
			scanf("%d", &sel);
			sel -= 1;

			if (seat[sel] == -1) {
				seat[sel] = log;
				client[log].money -= 12000;
				printf("������ �Ϸ��Ͽ����ϴ�.\n");
			}
			else {
				printf("�ش� �¼��� ������ �Ϸ�Ǿ����ϴ�.\n");
			}
		}
		save();
	}

	void cancel_seat() {		// 6. �������
		int check = -1;
		if (log != -1) {
			for (int i = 0; i < 10; i++) {
				if (seat[i] == log) {
					check = i;
				}
			}
		}

		if (check == -1) {
			printf("����� �¼��� �����ϴ�.\n");
		}
		else {
			seat[check] = -1;
			printf("������ ��ҵǾ����ϴ�.\n");
		}
		save();
	}

	void load() {							// load => read => fgets 
		char data[100] = { 0 };

		FILE* f = NULL;
		fopen_s(&f, "movie.txt", "rt");
		if (f != NULL) {
			fgets(data, 100, f);

			cnt = atoi(data);

		}
	}

	void save() {							// save => write => fputs

	}

	void run() {

		init();		//	�����ֱ�
		load();		//	
		while (1) {

			print_seat();		//	�¼����� ���
			print_all();		//	id pw ������ ���
			print_menu();		//	�޴� ���

			int sel = 0;
			printf("�޴� ���� : ");
			scanf_s("%d", &sel);

			if (sel == 1) { member(); }
			else if (sel == 2) { login(); }
			else if (sel == 3) { logout(); }
			else if (sel == 4) { add_money(); }
			else if (sel == 5) { set_seat(); }
			else if (sel == 6) { cancel_seat(); }
			else if (sel == 0) {
				printf("���α׷� ����\n");
				break;
			}


		}



	}
};
