#include <Windows.h>
#include <stdio.h>

// # ������ ����ϱ�[����ü(����) ����]

struct Store {
	int count;
	int* counts;
	int* prices;
	int money;
};

void main() {

	Store burger = { 0 };

	burger.money = 20000;
	burger.count = 3;

	burger.counts = new int[burger.count];
	//burger.counts = (int*)malloc(sizeof(int)*burger.count);

	for (int i = 0; i<burger.count; i++) {
		burger.counts[i] = 0;
	}

	burger.prices = new int[burger.count];
	//burger.prices = (int*)malloc(sizeof(int)*burger.count);
	burger.prices[0] = 8700;
	burger.prices[1] = 4200;
	burger.prices[2] = 1500;

	while (1) {

		printf("=== �Ե����� ===\n");
		printf("1.[��Ʈ]�Ұ����� : %d��\n", burger.prices[0]);
		printf("2.[��ǰ]�Ұ����� : %d��\n", burger.prices[1]);
		printf("3.�ݶ� : %d��\n", burger.prices[2]);
		printf("4.�����ϱ�\n");

		int choice = 0;
		printf("�޴� ���� : ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			burger.counts[0] += 1;
		}else if (choice == 2) {
			burger.counts[1] += 1;
		}else if (choice == 3) {
			burger.counts[2] += 1;
		}
		else if (choice == 4) {

			int total = burger.prices[0] * burger.counts[0] + burger.prices[1] * burger.counts[1] + burger.prices[2] * burger.counts[2];
			printf("total = %d\n", total);
			int charge = burger.money - total;

			if (charge >= 0) {
				printf("=== ������ ===\n");
				printf("1.[��Ʈ]�Ұ����� : %d��\n", burger.counts[0]);
				printf("2.[��ǰ]�Ұ����� : %d��\n", burger.counts[1]);
				printf("3.�ݶ� : %d��\n", burger.counts[2]);
				printf("�ѱݾ� : %d��\n", total);
				printf("�ܵ� : %d��\n", charge);
			}
			else {
				printf("������ �����մϴ�.\n");
			}

			break;

		}
	}
	system("pause");
}
