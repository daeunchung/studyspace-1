#include <Windows.h>
#include <stdio.h>

/*
	# �Է¹ޱ�
	.	scanf_s(1, 2);
	.	1��(data type) : %d %f %s %c ����� ����� �� �ִ�.
	.	2��(������ ����) : [����] ���� �տ� &(���ۻ���)�� �ٿ�����Ѵ�.
*/
void main() {

	printf("����\n"); printf("\n");
	int a1;
	scanf_s("%d", &a1);	// ���ڸ� �Է��ϰ� ���͸� ���������� ����Ѵ�.
	printf("����\n"); printf("\n");

	printf("%d", a1); printf("\n");




	//	# �Է¹ޱ� [����]
	// ����1) ���� 1���� �Է¹ް� ������� (����10%����)
	float salary;
	printf("����1) ������ �Է��Ͻÿ�"); printf("\n");
	scanf_s("%f", &salary);
	printf("����: %.f��, ����: %.f��", salary, salary * 12 * 0.9);
	printf("\n");

	// ����2) ���� 2���� �Է¹ް� �ﰢ�� ������� 
	float num1;
	float num2;
	printf("����2) �ﰢ���� �غ�, ���� ���̸� �Է��Ͻÿ�"); printf("\n");
	scanf_s("%f %f", &num1, &num2);
	printf("�ﰢ���� ����: %.2f", num1 * num2 / 2);
	printf("\n");

	// ����3) ���� 2���� �Է¹ް� ���� ��ȯ 
	int num3;
	int num4;
	printf("����3) ���� 2���� �Է��Ͻÿ�"); printf("\n");
	scanf_s("%d %d", &num3, &num4);
	int t;

	t = num3;
	num3 = num4;
	num4 = t;
	printf("num3 : %d, num4 : %d", num3, num4);
	printf("\n");
	system("pause");


	// 1. ��� , ���� , �Է� 
	// 2. ������ (operator) �߿俬���� 4���� 
	//    1) ��������� ==> + - * / %
	//    2) ���Կ����� ==> int a;  a = 10;
	//                 ==> �������� ���� �������� ����(����)�Ѵ�.

	//    3) �񱳿����� ==> 6�� ==> ����� 1(��)  0(����) �����ϳ��� ��µȴ�.
	//           1.  ������ ũ��			a > b
	//           2.  ������ �۴�			a < b
	//           3.  ���� ����			a == b
	//           4.  ���� �ٸ���			a != b 
	//           5.  ������ ũ�ų� ����  a >= b
	//           6.  ������ �۰ų� ����  a <= b

	int b2 = 10;	// �����, ����� ������ �ѹ��� �Ѵ�.
	int a2 = b2;
	//	printf("b2 : %d", b2);	printf("\n");
	printf("a2 : %d", a2);		printf("\n");

	// �񱳿�����
	printf("%d", 10 == 10); printf("\n");
	printf("%d", 10 != 10); printf("\n");
	printf("%d", 10 > 10); printf("\n");
	printf("%d", 10 < 10); printf("\n");
	printf("%d", 10 >= 10); printf("\n");
	printf("%d", 10 <= 10); printf("\n");


	// �񱳿����� [����]
	//����1) ���� 1�̳������� ���ڸ� �����غ����� 
	printf("%d", 10 == 10); printf("\n");
	printf("%d", 11 != 10); printf("\n");
	printf("%d", 11 > 10); printf("\n");
	printf("%d", 10 < 11); printf("\n");
	printf("%d", 10 >= 10); printf("\n");
	printf("%d", 10 <= 10); printf("\n");

	//����2) ���� 0 �̳������� a��  b�� �����غ����� 
	int a = 10;
	int b = 10;
	printf("================================="); printf("\n");
	a = 1;
	printf("%d", a == b); printf("\n");
	a = 10;
	printf("%d", a != b); printf("\n");
	printf("%d", a > b); printf("\n");
	printf("%d", a < b); printf("\n");
	a = 9;
	printf("%d", a >= b); printf("\n");
	b = 8;
	printf("%d", a <= b); printf("\n");

	system("pause");

	//	���� [����]

	//��1) ���� 1���� �Է¹ް� 60�̻��̸� 1��� 
	int d;
	printf("����1) ���� 1�� �Է��Ͻÿ�");		printf("\n");
	scanf_s("%d", &d);
	printf("%d", d >= 60);					printf("\n");

	//��2)  �ʸ� �Է¹ް� �ð� �� �� ���  5321 ==> 
	int e;
	printf("����2) �ʸ� �Է��Ͻÿ�");			printf("\n");
	scanf_s("%d", &e);
	printf("%d�� %d��", e / 60, e % 60);		printf("\n");

	//��3) ���� 2���� �Է¹ް� �ι�° ���ڰ� ũ�� 1��� 
	int f; int g;
	printf("����3) ���� 2���� �Է��Ͻÿ�");	printf("\n");
	scanf_s("%d %d", &f, &g);
	printf("%d", f < g);					printf("\n");

	// ��4) ���ڸ� �Է¹ް� ¦���� 1��� 
	// ¦�� ==> 2�� ��� 
	// 2�� ��� ==> ����� 2�� ������ �������� 0�̸� 2�� ����̴�. 
	int h;
	printf("����4) ���� 1���� �Է��Ͻÿ�");	printf("\n");
	scanf_s("%d", &h);
	printf("%d", h % 2 == 0);				printf("\n");
	system("pause");


	// 4�������� ==> �������� ==> and , or , not  ==> ����� 1 , 0 ���� ���´�.
	// 1) and  ==>  a == b && c == d  ==> 1���� ���̰� 2���� ���̸� �� 
	// 2) or   ==>  a == b || c == d  
	// 3) not  ==> !a  

	printf("%d", 10 == 10 && 9 == 9); printf("\n");
	printf("%d", 10 != 10 && 9 == 9); printf("\n");
	printf("%d", 10 == 10 && 9 != 9); printf("\n");
	printf("%d", 10 != 10 && 9 != 9); printf("\n");
	printf("======================================"); printf("\n");

	printf("%d", 10 == 10 || 9 == 9); printf("\n");
	printf("%d", 10 != 10 || 9 == 9); printf("\n");
	printf("%d", 10 == 10 || 9 != 9); printf("\n");
	printf("%d", 10 != 10 || 9 != 9); printf("\n");

	printf("======================================"); printf("\n");
	printf("not ==> ! ==>  %d", !(10 == 10)); printf("\n");

	system("pause");

	//����1) ������ 60~100�̸� 1 ��� 
	int a0 = 80;
	int b0 = 120;
	printf("%d", 60 <= a0 && a0 <= 100);	printf("\n");
	printf("%d", 60 <= b0 && b0 <= 100);	printf("\n");

	//����2) ������ 1~59�� 1��� 
	int c0 = 40;
	printf("%d", 0 < c0 && c0 < 60);		printf("\n");

	//����3) ���ڰ� 3�� ����̸鼭 4�� ����̸� 1��� 
	int d0 = 9;
	printf("%d", (d0 % 3 == 0) && (d0 % 4 == 0));	printf("\n");

	//����4) ���� 2���� �Է¹ް� ����� 60�̻��̸� 1��� 
	// (���� : ���� ==> ����� 60�̻������� �Ѱ����̶� 50���ϰ� ������ ����)
	//  100 , 50 ==> 150 ==> 0
	//  60  , 60 ==> 120 ==> 1
	int n1; int n2;
	int tot; float average;
	printf("�� ������ �Է��Ͻÿ�");		printf("\n");

	scanf_s("%d", &n1);
	scanf_s("%d", &n2);
	tot = n1 + n2;
	average = tot / 2;

	printf("%d", average >= 60 && n1 > 50 && n2 > 50);		printf("\n");

	//����5) ���л� ==> ���������� �����̰ų� ���������� �����̸� ���л� (1)
	// 100 , 0   ==> 1
	// 99  , 99  ==> 0

	int s1; int s2;
	printf("�� ������ �Է��Ͻÿ�");		printf("\n");
	scanf_s("%d", &s1);
	scanf_s("%d", &s2);

	printf("%d", s1 == 100 || s2 == 100);		printf("\n");

	system("pause");

}