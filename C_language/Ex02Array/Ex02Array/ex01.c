#include <Windows.h>
#include <stdio.h>
/*
# �迭(array)
[1] ����
1) int ������[����];
2) int arr[5];			���� 5���� �Ѳ����� �Ҵ�޴´�.
[2] ���
1) �迭�� 0���� ���� ������ŭ 1�� �����ϸ鼭 ���� �����ȴ�.
2) �̶� ���ȣ(index)�� ����Ѵ�.
��) arr[0] = 10;		arr[1] = 20;
3) �ݺ����� ����� ȿ�������� �̿��� �� �ִ�.
*/

void main() {

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;

	//--------------------

	int arr[5];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i<5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//--------------------
	// �迭 ����� : ó�� �ѹ��� �ۼ� ����
	int sc[5] = { 10, 20, 30, 40, 50 };
	for (int i = 0; i<5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//system("pause");

	int ar[5] = { 0 };	// 5���� ���� ��� 0���� �ʱ�ȭ
	ar[0] = 10;
	ar[1] = 20;
	ar[2] = 30;
	ar[3] = 40;
	ar[4] = 50;

	//����1) �迭�� ��ü ����� 
	//����1) 150
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += ar[i];
	}printf("%d\n", total);

	//����2) 4�� ����� ��� 
	//����2) 20 40
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 4 == 0) {
			printf("%d ", ar[i]);
		}
	}printf("\n");

	//����3) 4�� ����� �� ���
	//����3) 60
	total = 0;
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 4 == 0) {
			total += ar[i];
		}
	}printf("%d\n", total);

	//����4) 4�� ����� ���� ���
	//����4) 2
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 4 == 0) {
			cnt++;
		}
	}printf("%d\n", cnt);

	//����5) ¦���� ���� ���
	//����5) 5
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (ar[i] % 2 == 0) {
			cnt++;
		}
	}printf("%d\n", cnt);
	system("pause");



	// --------------------------------- OMR ī�� [����] ------------------------------------
	srand(time(0));

	int omr[] = { 1, 5, 3, 2, 5 }; // ��� ���
	int me[5] = { 0 };			 // �л� ���

	//����1) me�� 1~5 ������ ���� ���ڸ� 5�� ���� ��,
	//       omr�� ���Ͽ� ������� (1������ 20��)
	//����2) ������ "o", Ʋ���� "x" ��� 
	int score = 0;
	for (int i = 0; i < 5; i++) {
		me[i] = rand() % 5 + 1;

		if (omr[i] == me[i]) {
			printf("o ");
			score += 20;
		}
		else {
			printf("x ");
		}
	}
	printf("\n");
	printf("���� : %d", score);		printf("\n");

	system("pause");


	// ---------------------------- �й� �Է� [����] -------------------------------------------------
	int scores[5] = { 10 ,   20,   60 ,  40,   3 };
	int num[5] = { 1001, 1002, 1003, 1004, 1005 };

	//����1) ������ 60�� �̻��̸� �հ�. �հݻ� �� ���.
	//����1) 1��
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (scores[i] >= 60) {
			cnt++;
		}
	}printf("%d��\n", cnt);

	//����2) �й��� �Է��ϸ� ���� ��� 
	//����2) 1001 ==> 10
	int sn;
	printf("�й��� �Է��Ͻÿ�\n");
	scanf_s("%d", &sn); 
	for (int i = 0; i < 5; i++) {
		if (num[i] == sn) {
			printf("%d��\n", scores[i]);
		}
	}
	//����3) ������ �Է¹޾� ���ȣ(index) ���
	//����3) 60 ==> 1003
	int ss;
	printf("������ �Է��Ͻÿ�\n");
	scanf_s("%d", &ss);
	for (int i = 0; i < 5; i++) {
		if (scores[i] == ss) {
			printf("%d��\n", num[i]);
		}
	}

	//����4) ���� �й��� �Է��ϸ� "����"��� ���
	//����4) 1006 ==> "����"
	int y = -1;
	printf("�й��� �Է��Ͻÿ�\n");
	scanf_s("%d", &sn);
	for (int i = 0; i < 5; i++) {
		if (num[i] == sn) {
			y = 1;
		}
	}
	if (y == -1) {
		printf("���� �й� �Դϴ�");	printf("\n");
	}
	else {
		printf("�й��� �����Ѵ�.");	printf("\n");
	}

	//����5) 1���л��� �й��� ���� ���
	//����5) 1003�й�(60��)
	int max = 0; int maxsn;
	for (int i = 0; i < 5; i++) {
		if (max < scores[i]) {
			max = scores[i];
			maxsn = i;
		}
	}
	printf("1�� �л� : %d (%d��)\n", num[maxsn], scores[maxsn]);

	system("pause");





	// ----------------------------------- ��÷ ���� [����] ------------------------------------
	int lotto[] = { 3, 0, 3, 3, 3, 3, 0 };
	// ����) �� ������ ��÷���� �ƴ��� ��� 
	// ����) 3�� �������� 3���̻��̸� ��÷ 
	 y = -1;
	for (int i = 0; i < 5; i++) {
		if (lotto[i] == 3 && lotto[i + 1] == 3 && lotto[i + 2] == 3)
			y = 1;
	}

	if (y == 1) { printf("��÷");  printf("\n"); }
	else { printf("��"); printf("\n"); }
	system("pause");
}
