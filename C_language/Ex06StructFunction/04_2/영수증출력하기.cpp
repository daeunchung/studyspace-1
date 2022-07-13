#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

// # ������ ����ϱ�[����ü(����+�Լ�) ����]

struct Store {
	int count;
	int* counts;
	int* prices;
	int money;

	void init() {
		money = 20000;
		count = 3;							// ���� ���� 3����
		counts = new int[count];			// ���Ǻ� ���� �迭 ���ֱ�
		for (int i = 0; i<count; i++) {		
			counts[i] = 0;					// ó������ ���δ� 0����
		}
		prices = new int[count];			// ���Ǻ� ���� �迭 ���ֱ�
		prices[0] = 8700;
		prices[1] = 4200;
		prices[2] = 1500;					// ���Ǻ� ���� �� �迭�� �־��ֱ�
	}

	void print_menu() {
		printf("=== �Ե����� ===\n");
		printf("1.[��Ʈ]�Ұ����� : %d��\n", prices[0]);
		printf("2.[��ǰ]�Ұ����� : %d��\n", prices[1]);
		printf("3.�ݶ� : %d��\n", prices[2]);
		printf("4.�����ϱ�\n");
	}

	int sel_menu() {
		int choice = 0;
		printf("�޴� ���� : ");
		scanf("%d", &choice);
		if (choice > 4 || choice < 1) {
			choice = -1;
		}
		return choice;
	}

	void choice1() {
		counts[0] += 1;
	}
	void choice2() {
		counts[1] += 1;
	}
	void choice3() {
		counts[2] += 1;
	}
	void choice4() {

		int total = prices[0] * counts[0] + prices[1] * counts[1] + prices[2] * counts[2];
		int charge = money - total;
		if (charge >= 0) {
			printf("=== ������ ===\n");
			printf("1.[��Ʈ]�Ұ����� : %d��\n", counts[0]);
			printf("2.[��ǰ]�Ұ����� : %d��\n", counts[1]);
			printf("3.�ݶ� : %d��\n", counts[2]);
			printf("�ѱݾ� : %d��\n", total);
			printf("�ܵ��� %d�� �Դϴ�.\n", charge);
		}
		else if(charge < 0){
			printf("������ �����մϴ�.\n");
		}
	}

	void run() {
		init();
		while (1) {
			print_menu();
			int choice = sel_menu();

			if (choice == -1) {
				printf("�Է¿���\n");
				continue;
			}

			if (choice == 1) { choice1(); }
			else if (choice == 2) { choice2(); }
			else if (choice == 3) { choice3(); }
			else if (choice == 4) { choice4(); break; }
		}
	}
};

void main() {
	Store burger = { 0 };
	burger.run();
	system("pause");
}
