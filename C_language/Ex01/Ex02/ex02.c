#include <Windows.h>
#include <stdio.h>
// �� ������Ʈ�� main �Լ��� �ϳ����� �Ѵ�.

/*
# ���� (variable) : �����͸� �����ϴ� ����
	1) ����
	.	int a ;
	.	�޸� �����Ҵ�
	2) ���
	.	a = 10;
	.	�޸𸮿� �� ����

*/
void main() {

	//  ����(int ) : 4byte
	int a;
	a = 10; // 10�� a�� �����ض�
	printf("%d", a);	printf("\n");

	// �Ǽ�(float) : 4byte
	float b;							// ����(�޸� �����Ҵ�)
	b = 10.0;							// �޸𸮿� �� ����
	printf("%f", b);	printf("\n");

	// ����(char) : 1byte
	char c;
	c = 'a';
	printf("%c", c);	printf("\n");


	/*
		# ������ Ư¡
		1) ������ �� ���� ���� ������ �� �ִ�. (���ο� ���� ����Ǹ� ���� �� ����)
		2) ���� ������ �Ѱ��� �̸����θ� ����� �� �ִ�. (�ߺ�����Ұ�)
		3) ���� ���� �̸����� ����� �� ����. (�Ķ��۾��� �����)
		4) ���ڸ� �̸����� ������ �� ����. 7a(x), a7(o)
		5) ��ҹ��ڸ� �����Ѵ�.
		6) �����̸����� Ư������ $�� _ �� �� ��밡��
	*/

	int aa;
	aa = 10; aa = -1; aa = 0; aa = 13; aa = 3;
	printf("%d", aa);	printf("\n");
	
	int A;
	// ��) ����1) �簢���� ����
	float garo;
	garo = 7;

	float sero;
	sero = 3;

	float rect;
	rect = garo * sero;
	printf("���� %.2f, ���� %.2f, �簢�� ���� : %.2f", garo, sero, rect); 
	printf("\n");

	// ����2) ���������� 20, 43, 71���� �޾Ҵ�. ���� ��� ���. 
	float score1; float score2; float score3; float total; float avg;
	score1 = 20;
	score2 = 43;
	score3 = 71;
	total = score1 + score1 + score3;
	avg = total / 3;
	printf("���� : %.f, ��� : %.2f", total, avg);
	printf("\n");

	// ����3) 186800���� ȭ��ż��� ��� 
	// ����3) 5����(3��) 1����(3��) 5õ��(1��) 5���(1��) 1���(3��)
	int money = 186800;
	printf("5����: %d��, 1����: %d��, 5õ��: %d��, 1õ��: %d��, 5���: %d��, 1���: %d��",
		money / 50000, money % 50000 / 10000, money % 50000 % 10000 / 5000, money % 50000 % 10000 % 5000 / 1000,
		money % 50000 % 10000 % 5000 % 1000 / 500, money % 50000 % 10000 % 5000 % 1000 % 500 / 100);
	printf("\n");

	int n1 = money / 50000;
	int n2 = (money % 50000) / 10000;
	int n3 = (money % 10000) / 5000;
	int n4 = (money % 5000) / 1000;
	int n5 = (money % 1000) / 500;
	int n6 = (money % 500) / 100;

	printf("5���� = %d��\n", n1);
	printf("1���� = %d��\n", n2);
	printf("5õ�� = %d��\n", n3);
	printf("1õ�� = %d��\n", n4);
	printf("5��� = %d��\n", n5);
	printf("1��� = %d��\n", n6);

	// ����4) x�� y�� �� ��ȯ.
	int x;
	int y;

	int z; //��Ʈ

	x = 10;
	y = 20;

	z = x;
	x = y;
	y = z;
	printf("x : %d, y : %d", x, y);
	printf("\n");

	// ����5) ������ 100���̴�. �������(���� : ���� 10%����)
	float salary;
	salary = 100;

	float profit;
	profit = salary * 12 * 0.9;
	printf("���� : %.f��, ���� : %.f��", salary, profit);
	printf("\n");

	system("pause");
}