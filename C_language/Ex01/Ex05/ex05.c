#include <Windows.h>// system
#include <stdio.h>	// printf, scanf_s
#include <stdlib.h>	// rand
#include <time.h>	// time

void main() {

/*
	// atm [����]
	// 1.�Ա� 2.��� 
	int cash = 8000;
	int atm = 5000;
	printf("==== ATM ===="); printf("\n");
	printf("1.�Ա� 2.���"); printf("\n");
	int select;
	scanf_s("%d", &select);
	if (select == 1) {
		printf("�Ա��� �ݾ��� �Է��ϼ��� "); printf("\n");
		int money;
		scanf_s("%d", &money);
		if (money <= cash) {
			cash = cash - money;
			atm = atm + money;
		}
		if (money > cash) {
			printf("�ݾ��� �ٽ��Է��ϼ��� "); printf("\n");
		}
	}
	printf("%d %d", cash, atm); printf("\n");

	system("pause");

//		time �Լ� : time.h ������Ͽ� ����
//		1970�� 1�� 1�� 0�� (UTC) ���� ������� �帥 �ð��� �ʴ����� ��ȯ�մϴ�.

//		srand �Լ� : stdlib.h ������Ͽ� ����
//		seed ���� ���� rand�� ���� �ٲ��. ( seed �� ���� ������ ���� )

//		rand �Լ� = srand(1) ���� ȿ��	

//rand() �׳� �̷��� ����� ����Ϸ��� �ϸ� 0���� stdlib.h ���Ͽ��� �������ִ� 0x7fff������ ������ ���� ������ ����Ѵ�.
//0x7fff�� 32767�̴ϱ� 0~32767�� ���� ���̿��� ������ �����ȴٴ� ���̴�.
//�ڽ��� ���ϴ� �������� ������ �̾Ƴ����� rand()%n �̷� ������ �ڿ� ������ �� ����� �Ѵ�.
//rand()%n�� 0~n-1 ������ ������. ���� �� �پ��� ������ �����ְ� �ʹٸ�
//A + (rand() % B) + C -> A+C ~ (A+B+C)-1 �� ����
//�̷� ������ �� ���� �ִ�. �̷��� ���ٺ��� �̻��� ���� �߰��� �� �ִ�. ������ �׻� ���� ���� ���´ٴ� ���̴�.
//�̰� �����Ҹ��ĸ� ���� ��� 5���� ������ �������µ� 1 2 3 4 5�� ���Դٰ� ����. �����Ų �� ���ٰ� �ٽ� Ű�� �� �Ȱ��� 1 2 3 4 5�� ���´�.
//�� �и� �������� ���� �̾Ƴ��� �� ���ؼ� ���� �Լ���� rand �Լ��� ã�Ƽ� ��µ� �� ������ �־��� ���� ���̿��� ������ ���ڸ� �̾Ƴ� ��, �׻� �� ���� ���ٴ� ���̴�.
//�׻� ���� ����, �Ź� �ٸ� ������ �߻���Ű�� ���ؼ��� �õ� ���� �ִ� ����� �ִµ� ���⼭ srand �Լ��� ���δ�.
//�׸��� srand()�� ���ڷ� time()���� ��ȯ�Ǵ� ���� �ش�. time �Լ��� ������ time.h ������ �߰�������� �Ѵ�.
//���� srand(time(NULL)), Ȥ�� srand(time(0))�� ����. (NULL == 0)
//time(NULL)�� 1970�� 1�� 1�� ������ ����� �ð��� �� ������ ��ȯ�ϴ� �Լ��̴�.

	srand(time(0));	// �����Լ��� ���غ���
	//	1~4������ ������ ���ڰ� ���´�.

	int a = 10;
	printf("%d", a); printf("\n");

	int b = rand();
	printf("%d", b); printf("\n");

	int c = rand();
	printf("%d", c); printf("\n");

	// 0 ~ 4
	int d = rand() % 5;		// 0, 1, 2, 3, 4
	printf("%d", d); printf("\n");

	//	3 ~ 7
	int e = rand() % 5 + 3;	// 0 ~ 4 ==> 3 ~ 7
	printf("%d", e); printf("\n");

	// -4 ~ 3
	int f = rand() % 8 - 4;
	printf("%d", f); printf("\n");

	system("pause");



	//	������ [����]	srand(time(0));
	//rand();
	// ������ ���� ���� ������ �����Է��� ������ 
	
	int a = rand() % 8 + 2;  // 2�� ~ 9��
	int b = rand() % 9 + 1;  // 1~9

	printf("%d * %d = ?", a, b);
	int c;
	scanf_s("%d", &c);
	if (c == a * b) {
		printf("����");
	}
	else {
		printf("����");
	}

	system("pause");

	// if �� �ɼ� 2���� (�ܵ����Ұ���)
	// 1) else  ==> if �� ���� ���� ���δ� 

	void main() {
		int score = 60;
		if (score >= 60 && score <= 100) {
			printf("�հ�");
		}
		else {
			printf("���հ�");
		}
		printf("\n");
		printf("\n");

		printf("====== atm ======="); printf("\n");
		printf("1. �Ա� 2. ��� 3.����"); printf("\n");
		int select;
		scanf_s("%d", &select);
		if (select == 1) {
			printf("�Ա�");
		}
		if (select == 2) {
			printf("���");
		}
		if (select == 3) {
			printf("����");
		}
		else {
			printf("����");
		}

		system("pause");


		// if �� �ɼ� 2����
		// 1) else
		// 2) elseif ==> if �� ������ ������ �ʿ��Ҷ� ��� 
		//				 ���������� ���������� ������ �˻��ؼ� ���̳����� �������� ����
		//				����� ������ 1���� ���´�.
		printf("====== atm ======="); printf("\n");
		printf("1. �Ա� 2. ��� 3.����"); printf("\n");
		int select;
		scanf_s("%d", &select);
		if (select == 1) {
			printf("�Ա�");
		}
		else if (select == 2) {
			printf("���");
		}
		else if (select == 3) {
			printf("����");
		}
		else {
			printf("����");
		}
		system("pause");

*/
	
srand(time(0));
//��1) ���� ���� �� // 1�� ���� 1���� ����
int me;
printf("1.���� , 2.���� , 3.��"); printf("\n");
scanf_s("%d", &me);
int com = rand() % 3 + 1;
int ���� = 1; int ���� = 2; int �� = 3;

if (com == ���� && me == ����) {
	printf("����");
}
if (com == ���� && me == ����) {
	printf("����");
}
if (com == �� && me == ��) {
	printf("����");
}
if (com == ���� && me == ����) {
	printf("���� �̰��");
}
if (com == �� && me == ����) {
	printf("���� �̰��");
}
if (com == ���� && me == ��) {
	printf("���� �̰��");
}
if (com == ���� && me == ��) {
	printf("���� ����");
}
if (com == �� && me == ����) {
	printf("���� ����");
}
if (com == ���� && me == ����) {
	printf("���� ����");
}




// �������� // ���� 1~10���� ���������� 1)Ȧ  2)¦
int coin = rand() % 10 + 1;
printf("\n");
printf("============��������============"); printf("\n");
printf("ġƮŰ : %d", coin);
printf("\n");
printf("1)Ȧ 2)¦"); printf("\n");
int sel; scanf_s("%d", &sel);
if (sel == 1 && coin % 2 == 1) {
	printf("����");
}
else if (sel == 2 && coin % 2 == 0) {
	printf("����");
}
else {
	printf("��");
}
printf("\n");





// ���� // 1)�ܱ� 2)���� 
// �ܱ� ==> 30�ۼ�ƮȮ���� ��÷ 
printf("===========����========="); printf("\n");
printf("1.�ܱ� 2.����"); printf("\n");
sel; scanf_s("%d", &sel);
int lotto = rand() % 10;
printf("ġƮŰ : %d", lotto); printf("\n");
if (sel == 1) {
	if (lotto >= 3) {
		printf("��"); printf("\n");
	}
	else {
		printf("��÷"); printf("\n");
	}
}
system("pause");

}