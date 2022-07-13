#include <Windows.h>
#include <stdio.h>

/*
# �迭 �⺻����[�Լ��� ����]
���� 1) ��ü �� ����
���� 1) 150

���� 3) 4�� ����� �� ����
���� 3) 60

���� 4) (�ε�����)�� ��ü
���� 5) (������)�� ��ü
*/
void print_arr(int * p, int count) {
	printf("[");
	for (int i = 0; i < count; i++) {
		printf("%d ", p[i]);
	}
	printf("]\n");
}

int test1(int * p, int count) {
	int total = 0; 
	for (int i = 0; i < count; i++) {
		total += p[i];
	}
	return total;
}

int test3(int * p, int count) {
	int total = 0;
	for (int i = 0; i < count; i++) {
		if (p[i] % 4 == 0) {
			total += p[i];
		}
	}
	return total;
}

void test4(int * p, int idx1, int idx2) {
	//int tmp = p[idx1];
	//p[idx1] = p[idx2];
	//p[idx2] = tmp;

	int temp = *(p + idx1);
	*(p + idx1) = *(p + idx2);
	*(p + idx2) = temp;
}

void test5(int * p, int count, int v1, int v2) {
	int idx1 = 0; int idx2 = 0;
	for (int i = 0; i < count; i++) {
		if (p[i] == v1) { idx1 = i; }
		if (p[i] == v2) { idx2 = i; }
	}

	int tmp = p[idx1];
	p[idx1] = p[idx2];
	p[idx2] = tmp;

}

void main() {

	int count = 5;
	int arr[5] = { 10, 20, 30, 40, 50 };

	printf(">>>���� 1\n");
	int tot = test1(&arr[0], count);
	printf("tot = %d\n", tot);
	printf("\n");

	printf(">>>���� 3\n");
	tot = test3(&arr[0], count);
	printf("tot = %d\n", tot);
	printf("\n");

	printf(">>>���� 4\n");
	test4(&arr[0], 0, 4);
	print_arr(&arr[0], count);
	printf("\n");

	printf(">>>���� 5\n");
	test5(&arr[0], count, 20, 40);
	print_arr(&arr[0], count);
	printf("\n");

	system("pause");
}
