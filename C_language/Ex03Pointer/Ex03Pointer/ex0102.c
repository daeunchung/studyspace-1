#include <Windows.h>
#include <stdio.h>

// # ������ == > �ּҸ� �����ϴ� ����
// 1) ���� : int* p;
// 2) ��� : p = &a;
// 3) ���� : �����ͺ����� �Ϲݺ����� �ּҸ� �����Ѵ�.
// 4) �ּ� ����ϴ� �� : ���� �տ� &�� ���̸� �ּҰ� ��µȴ�.

/*
void main() {
	int a = 0;			// 4byte
	double f = 0;		// 8byte
	char c = 0;			// 1byte
	printf("sizeof ==> %d ", sizeof(c));
	printf("\n");

	// & ���ۻ���
	printf("a�� �ּ� : %d", &a); printf("\n");

	int* p;
	char* pc;
	double* pf;
	p = &a;
	printf("p�� �� : %d", p); printf("\n");
	system("pause");

	printf("%d\n", a);
	printf("%d\n", &a);
	printf("%d\n", p);
	printf("%d\n", &p);

	p[0] = 200;
}

*/



// �Լ� 
// 1) ����
//     1. void   ==> Ű���� 
//     2. test() ==> �̸�
//     3. {}     ==> ���࿵�� 
// 2) ���
//     test();   ==> �Լ����� 

// # �Լ��� ���� (4����)
void test() {
	printf("����� test"); printf("\n");
}

void test1() {
	printf("!!");
	printf("\n");
}
void test2(int a, int b) {
	printf("%d %d", a, b); printf("\n");
}

int test3() {
	int a = 10;
	return a;
}

int test4(int a, int b) {
	int c = a + b;
	return c;
}


void odd_even(int num) {
	if (num % 2 == 1) {
		printf("Ȧ��\n");
	}
	else {
		printf("¦��\n");
	}
}

void swap(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void pswap(int* p1, int* p2) {
	int temp = p1[0];
	p1[0] = p2[0];
	p2[0] = temp;
	// int ������ �ٲ��ֱ�

	// int temp = *p1;
	// *p1 = *p2;
	// *p2 = temp;
}

void main() {
	int a = 10;
	test();
	test();
	test();
	system("pause");

	test1();
	test2(10, 20);
	int c = test3();
	printf("test3 ==> %d", c);	printf("\n");
	printf("test4 ==> %d", test4(5, 6));	printf("\n");

	// =========> ���� ! �� �Լ� ǥ������ test4(5, 6); �� printf() �Լ� �ȿ� ���°� �ƴϰ�
	//					test4(5, 6) �� �θ��°ɱ�?

	// C ���� �Լ��� �������ִ� (�������ִ�) �κ��� main �Լ����� �տ� �־�߸�
	// main ���� �Լ��� �ҷ��� ����� �� �ִ�.
	// �Լ� ����ΰ� �����(;) ���� �ڿ� ������ undefined �� ������ ���

	// # Ȧ�� �Ǵ� ¦���� ������ִ� �Լ�
	odd_even(10);
	odd_even(1);
	odd_even(15);

	// # a �� b �� ���� ��ȯ�ϴ� �Լ� (�Լ��� �Ѱ�)
	int a = 10;
	int b = 20;
	printf("%d %d", a, b);	printf("\n");
	swap(a, b);
	printf("%d %d", a, b);	printf("\n");
	pswap(&a, &b);
	printf("%d %d", a, b);	printf("\n");


	system("pause");
}
// main();

