#include <Windows.h>
#include <stdio.h>
void main() {
	// ----------------------------------------   3 6 9 ���� 
	// 1~50�� ���ʴ�� ��� 
	// ����1) ���ڰ� 3 �̳� 6�̳� 9�� ���ڴ�� "¦" ���
	// ����2) ���ڰ� 3 �̳� 6�̳� 9�� 2���� "¦¦" ��� 
	// 12¦45¦78¦.....
	int n = 1;
	while (n <= 50) {
		int a = n / 10;
		int b = n % 10;
		int count = 0;
		if (a == 3 || a == 6 || a == 9) {
			count += 1;
		}
		if (b == 3 || b == 6 || b == 9) {
			count += 1;
		}
		if (count == 2) {
			printf("¦¦");
		}
		else if (count == 1) {
			printf("¦");
		}
		else {
			printf("%d", n);
		}
		n++;
	}
	printf("\n");
	system("pause");

	// ------------------------------------------   ATM   ------------------------------
/*	int db_id1 = 1111; int db_id2 = 2222;
	int db_m1 = 1000; int db_m2 = 2000;
	int log = -1; //�α׾ƿ��� -1 // �α����� �ش� ���̵� //
	int run = 1;
	while (run == 1) {
		if (log == -1) {
			printf("�α��� �ϼ��� "); printf("\n");
		}
		else {
			printf("[%d] �α����� ", log); printf("\n");
		}
		printf("====== mega atm ======="); printf("\n");
		printf("1.�α��� 2.����");
		printf("\n");
		int sel; scanf_s("%d", &sel);
		if (sel == 1) {
			printf("���̵� �Է��ϼ��� ");
			int id; scanf_s("%d", &id);
			if (id == db_id1) {
				log = id;
			}
			if (id == db_id2) {
				log = id;
			}
			while (log != -1) {
				printf("====== %d =======", log); printf("\n");
				printf("3.�ܾ���ȸ 4.��� 5.�Ա� 0.�α׾ƿ�");
				int sel1; scanf_s("%d", &sel1);
				if (sel1 == 0) {
					log = -1;
				}
			}
		}
	}

	system("pause");*/



	// ---------------------------------------------  �ý� ����
	// 1.���� ==> �������� �ӵ���ŭ �̵� 
	// 2.ȸ�� ==> �� �� �� ��  ==> 0 , 1 , 2 , 3
	// 3.�ӵ� ==> 0~3 ���̷� �̵� 
	// ������ ������ ==> �������� ������ ���� (0~10) 
	// ������ ������ ==> ��� ���� ==> 2ĭ ���� 50�� �߰� 
	int money = 0;			int x = 5; int y = 5; int path = 0;
	int speed = 0; int dir = 0;	int dx = 7; int dy = 1;	 int run = 1;
	while (run == 1) {
		system("cls"); // ȭ��Ŭ����
		printf("[����] %d", money);						printf("\n");
		printf("[����ġ] x : %d, y : %d", x, y);		 printf("\n");
		printf("[�ӵ�] %d , [����] %d ", speed, dir);	 printf("\n");
		printf("[������] dx : %d , dy : %d", dx, dy);	printf("\n");
		printf("1.���� 2.ȸ�� 3.�ӵ�����");				printf("\n");
		int sel; scanf_s("%d", &sel);
		if (sel == 1) {
			if (dir == 0) {y += speed;}
			else if (dir == 1) { x += speed; }
			else if (dir == 2) { y -= speed; }
			else if (dir == 3) { x -= speed; }
			path += speed;
		}
		else if (sel == 2) {
			printf(" 0) �� , 1) �� , 2)�� , 3)��");
			scanf_s("%d", &dir);
		}
		else if (sel == 3) {
			printf("�ӵ��� �Է��ϼ��� (0~3)");
			scanf_s("%d", &speed);
		}


		if (x == dx && y == dy) {
			printf("������ ����");
			printf("�ýÿ���� %d�� �Դϴ�", path / 2 * 50);		printf("\n");
			dx = rand() % 11;
			dy = rand() % 11;
			system("pause");
		}
	}
}
