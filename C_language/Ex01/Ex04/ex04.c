#include <Windows.h>
#include <stdio.h>

void main() {

	// ���ǹ� 
	// 1) if  ==> Ű����
	// 2) (1) ==> ���� ==> () ������ ���� 1�̸� ���� , 0�̸� ����
	// 3) {}  ==> ���� ���� 

	if (1) {
		printf("���ǹ�1"); printf("\n");
	}

	if (0) {
		printf("���ǹ�2"); printf("\n");
	}

	// ������ �����ֱ�
	// ������ { �ȿ��� ����Ǿ } ������ �����ȴ�.
	int a = 10;
	{
		int b = 20;
	}
	printf("%d", a); printf("\n");
	//	printf("%d" , b);printf("\n"); ��������.

	system("pause");

	// ��ø if ��
	// ���̵��� �������� [����]
	// ����1) 130 �̻� "����"
	// ����2) 120~ 130 ���̸� �θ�԰� �����Ͽ� ���尡��
	// ����3) 120 �̸� "����Ұ�"
	int h;

	printf("Ű�� �Է��Ͻÿ�");		printf("\n");
	scanf_s("%d", &h);

	if (h >= 130) {
		printf("����");				printf("\n");
	}
	else if (120 <= h && h <= 130) {
		printf("�θ�԰� �����Ͽ� ���尡��");		printf("\n");
	}
	else if (h < 120) {
		printf("����Ұ�");			printf("\n");
	}
	system("pause");

	//printf("Ű�� �Է��ϼ��� "); printf("\n");
	//int Ű = 0;
	//scanf_s("%d", &Ű);

	//if (Ű >= 130) {
	//	printf("����"); printf("\n");
	//}
	//if (120 <= Ű && Ű < 130) {
	//	printf("�θ�԰� ���� �Դϱ�? 1)yes  2)no "); printf("\n");
	//	int ans = 0;
	//	scanf_s("%d", &ans);
	//	if (ans == 1) {
	//		printf("����"); printf("\n");
	//	}
	//	if (ans == 2) {
	//		printf("����Ұ�"); printf("\n");
	//	}
	//}
	//if (Ű < 120) {
	//	printf("����Ұ�"); printf("\n");
	//}

	//system("pause");

	// ����1) �Ե����� ���Ǳ�
	// 1. ���� ���� �Է¹޴´�. 
	// 2. �����ֹ��Ѵ�. 
	// 3. ������  ==>(��) ���̺����ϴ� , �ܹ����ֹ� �Ž����� ??? 

	int money = 0;
	printf("���� �Է��ϼ��� "); printf("\n");
	scanf_s("%d", &money);

	printf("===== �Ե����� ====="); printf("\n");
	printf("1. �ܹ���  500��"); printf("\n");
	printf("2. �ݶ� 700��"); printf("\n");
	printf("3. ���� 1300��"); printf("\n");

	int select = 0;
	printf("��ȣ�� �Է��ϼ��� "); printf("\n");
	scanf_s("%d", &select);
	if (select == 1) {
		if (money >= 500) {
			printf("�ܹ��Ű� �ֹ��Ϸ�Ǿ����ϴ�. �Ž�����: %d��", money - 500);		
			printf("\n");
		}
		else {
			printf("���� �����մϴ�."); 
			printf("\n");
		}
	}
	if (select == 2) {
		if (money >= 700) {
			printf("�ݶ� �ֹ��Ϸ�Ǿ����ϴ�. �Ž�����: %d��", money - 700);
			printf("\n");
		}
		else {
			printf("���� �����մϴ�.");
			printf("\n");
		}
	}
	if (select == 3) {
		if (money >= 1300) {
			printf("���ڰ� �ֹ��Ϸ�Ǿ����ϴ�. �Ž�����: %d��", money - 1300);
			printf("\n");
		}
		else {
			printf("���� �����մϴ�.");
			printf("\n");
		}
	}

	system("pause");

	// ���� ���� �� ���� �����
	// 1.���� 2.���� 3.�� 
	// p1, p2 �� ���� ���� ���� �Ѵ�. ��� ��� 

	int p1; int p2; int ���� = 1; int ���� = 2; int �� = 3;
	printf("p1 ==> 1.���� 2.���� 3.�� ");
	scanf_s("%d", &p1);

	printf("p2 ==> 1.���� 2.���� 3.�� ");
	scanf_s("%d", &p2);

	if (p1 == p2) {
		printf("����.");
	}
	if (p1 == ���� && p2 == ��) {
		printf("p1 �¸�");
	}
	if (p1 == ���� && p2 == ����) {
		printf("p1 �¸�");
	}
	if (p1 == �� && p2 == ����) {
		printf("p1 �¸�");
	}
	if (p1 == ���� && p2 == ��) {
		printf("p2 �¸�");
	}
	if (p1 == ���� && p2 == ����) {
		printf("p2 �¸�");
	}
	if (p1 == �� && p2 == ����) {
		printf("p2 �¸�");
	}







}

