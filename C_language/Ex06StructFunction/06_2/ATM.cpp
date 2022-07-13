#include <Windows.h>
#include <stdio.h>


/*
# ATM[����ü(����+�Լ�) ����]
1. ȸ������
2. �α���				: �α��ΰ� ���ÿ� ���� �޴��� �̵��ϱ�
3. ����
------------------
1. �Ա�
2. ���
3. ��ü
4. Ż��					: �α׾ƿ��� �Բ� �ڷΰ���
5. �α׾ƿ�				: �α׾ƿ��� �Բ� �ڷΰ���
*/

struct Client {
	int accs;
	int moneys;
};

struct ATM {
	int count;
	int login;
	Client* c;

	void show_info() {
		for (int i = 0; i < count; i++) {
			printf("%d : %d��\n", c[i].accs, c[i].moneys);
		}
		printf("\n");
	}

	void print_menu() {
		printf("1.�α���\n");
		printf("2.�α׾ƿ�\n");
		printf("3.��ü�ϱ�\n");
		printf("4.ȸ������\n");
		printf("5.Ż���ϱ�\n");
		printf("6.�����ϱ�\n");
	}

	void init() {
		count = 3;
		login = -1;
		c = new Client[count];

		c[0].accs = 1111;	c[0].moneys = 1000;
		c[1].accs = 2222;	c[1].moneys = 2000;
		c[2].accs = 3333;	c[2].moneys = 3000;

	}

	int login_check() {
		int acc = 0;
		printf("���¹�ȣ�� �Է��ϼ��� : ");
		scanf_s("%d", &acc);

		int check = -1;
		for (int i = 0; i < count; i++) {
			if (c[i].accs == acc) {
				check = i;
			}
		}
		return check;
	}

	void login_member() {
		login = login_check();
		if (login == -1) {
			printf("���¹�ȣ�� Ȯ�����ּ���. \n");
		}
		else {
			printf("%d��, ȯ���մϴ�.\n", c[login].accs);
		}
	}

	void logout() {
		if (login == -1) {
			printf("�α��� ��, �̿밡���մϴ�.\n");
		}
		else {
			login = -1;
			printf("�α׾ƿ� �Ǿ����ϴ�.\n");
		}
	}

	int check_acc() {
		int acc = 0;
		printf("��ü�� ���¹�ȣ�� �Է��ϼ��� : ");
		scanf_s("%d", &acc);

		int check = -1;
		for (int i = 0; i < count; i++) {
			if (c[i].accs == acc) {
				check = i;
			}
		}
		return check;
	}

	int check_money(int money) {
		int check = -1;
		if (c[login].moneys >= money) {
			check = 1;
		}
		return check;
	}

	void trans_money() {
		if (login == -1) {
			printf("�α��� �� �̿밡���մϴ�\n");
			return;
		}
		int acc = check_acc();
		if (acc == -1) {
			printf("���¹�ȣ�� Ȯ�����ּ���.\n");
		}
		else {
			int money = 0;
			printf("��ü�� �ݾ��� �Է��ϼ���.\n");
			scanf_s("%d", &money);
			int check = check_money(money);

			if (check == -1) {
				printf("�����ܾ��� �����մϴ�.\n");
			}
			else {
				c[acc].moneys += money;
				c[login].moneys -= money;
				printf("��ü�� �Ϸ��Ͽ����ϴ�.\n");
			}
		}
	}

	int check_member(int acc) {
		int check = 1;
		for (int i = 0; i < count; i++) {
			if (c[i].accs == acc) {
				check = -1;
			}
		}
		return check;
	}

	void set_member() {
		int acc = 0;
		printf("������ ���¹�ȣ�� �Է��ϼ��� : ");
		scanf_s("%d", &acc);

		int check = check_member(acc);
		if (check == -1) {
			printf("�̹� �����ϴ� ���¹�ȣ �Դϴ�.\n");
		}
		else {
			c[count].accs = acc;
			c[count].moneys = 1000;					// ����ȸ���� ���¿� 1000���� �־��ֳ��� 
			count += 1;
			printf("ȸ�������� �����մϴ�.\n");
		}
	}

	void del_member() {
		if (login == -1) {
			printf("�α��� ��, �̿밡���մϴ�.\n");
		}
		else {
			for (int i = login; i < count-1; i++) {
				c[i] = c[i + 1];
			}
			count -= 1;
			login = -1;
			printf("Ż��Ǿ����ϴ�.\n");
		}
	}

	void run() {
		init();					// ���� ���ְ� ���¹�ȣ & �ܾ� �־��ֱ�
		while (1) {
			show_info();		// ���� �� �ܾ� ����� �����ְ�
			print_menu();		// �޴� ���

			// 1.�α���	2.�α׾ƿ�	3.��ü	4.ȸ������	5.Ż��	6.����

			int choice = 0;
			printf("�޴� ���� : ");	
			scanf_s("%d", &choice);		

			if (choice == 1) {	login_member();	}
			else if (choice == 2) { logout();	}
			else if (choice == 3) { trans_money();	}
			else if (choice == 4) { set_member();	}
			else if (choice == 5) {	del_member();	}
			else if (choice == 6) {
				printf("���α׷� ����\n");
				break;
			}
		}
	 }
};

void main() {
	ATM bank = { 0 };

	bank.run();
	system("pause");

}
