#include <Windows.h>
#include <stdio.h>

/*
# �迭 �⺻����[����ü(����+�Լ�) ����]
���� 1) ��ü �� ����
���� 1) 150

���� 2) 4�� ����� ����ü�� ������ ����
���� 2) 20 40

���� 3) 4�� ����� �� ����
���� 3) 60

���� 4) (�ε�����)�� ��ü
���� 5) (������)�� ��ü
*/
struct Test{
	int* p;
	int size;
};

struct Array {

	int count;
	int* arr;

	// ����ü �����ϸ鼭 �ȿ� �迭�� ���� �־��ִ� �Լ��� �־����.
	// �� ���������� ����ü �ȿ� �Լ��� ����� ȣ���ϴ� ������ ��Ű����
	void init() {													// �� �־��ֱ�
		count = 5;
		arr = new int[count];
		for (int i = 0; i<count; i++) {
			arr[i] = (i + 1) * 10;
		}
	}

	void print_arr() {												// �� ����ϱ�
		printf("[ ");
		for (int i = 0; i < count; i++) {
			printf("%d ", arr[i]);
		}
		printf("]\n");	
	}

	int test1() {
		int total = 0;
		for (int i = 0; i < count; i++) {
			total += arr[i];
		}
		return total;
	}

	// ** ����ü�� �����Ϸ����� ��ȯŸ���� ����ü **
	Test test2() {
		int size = 0;
		for (int i = 0; i < count; i++) {		// size �� ���ϱ����� for��
			if (arr[i] % 4 == 0) {
				size += 1;
			}
		}

		Test t = { 0 };
		t.size = size;
		t.p = new int[size];

		int j = 0;
		for (int i = 0; i < count; i++) {		// ����ü Test �� �迭�� �� �־��ֱ����� for��
			if (arr[i] % 4 == 0) {
				t.p[j] = arr[i];
				j += 1;
			}
		}
		return t;
	}

	int test3() {
		int total = 0;
		for (int i = 0; i < count; i++) {
			if (arr[i] % 4 == 0) {
				total += arr[i];
			}
		}
		return total;
	}

	void test4(int idx1, int idx2) {
		int tmp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = tmp;
	}
	
	void test5(int value1, int value2) {
		int idx1 = 0;
		int idx2 = 0;
		for (int i = 0; i < count; i++) {
			if (value1 == arr[i]) { idx1 = i; }
			if (value2 == arr[i]) { idx2 = i; }
		}

		int tmp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = tmp;
	}
};

void main() {

	Array a = { 0 };
	a.init();


	printf(">>> ���� 1\n");
	int total = a.test1();
	printf("total = %d\n", total);
	printf("\n");

	printf(">>> ���� 2\n");
	Test t = a.test2();
	for (int i = 0; i < t.size; i++) {
		printf("%d ", t.p[i]);
	}
	printf("\n");
	printf("\n");

	printf(">>> ���� 3\n");
	total = a.test3();
	printf("total = %d\n", total);
	printf("\n");

	printf(">>> ���� 4\n");
	a.test4(1, 4);
	a.print_arr();
	printf("\n");

	printf(">>> ���� 5\n");
	a.test5(20, 50);
	a.print_arr();
	printf("\n");

	system("pause");
}
