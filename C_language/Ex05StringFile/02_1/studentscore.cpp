#include <Windows.h>
#include <stdio.h>

struct Student {
	int* score;	// �� ����� ������ �����ϴ� �迭�� ����Ű�� �迭�������ε�
	int size;	// ���� �� (int* score �� �Ҵ�� �迭�� int ĭ���� ���ϴµ�)
};


void print_user(Student* p, int count) {
	for (int i = 0; i < count; i++) {
		printf("[%d] ", i);
		for (int j = 0; j < p[i].size; j++) {		// p[i].size �� i�л��� ���� ����� �ε�
			printf("%d ", p[i].score[j]);
		}
		printf("\n");
	}
	printf("\n");
}

Student* insert_user(Student* p, int* count) {
	if (count[0] == 0) {				//				 int count �� == count[0] 
										//	==>  (���� count�� int��, ���� count�� int*��)
										//  �Ǽ� ���� ���� ! �Լ� �Է��� int*count �� �޾�����  " �� �Լ� �ȿ����� ������ "
										//  �ο����� ��Ÿ���� int count ���� ��Ÿ���� ���������� ������ count[0] ���� ������� 
		p = new Student[count[0] + 1];
	}
	else if (count[0] > 0) {
		Student* tmp = p;

		p = new Student[count[0] + 1];	// �����ּ� �Űܳ��� ��ĭ Ű�� �� ���� �ձ�
		for (int i = 0; i < count[0]; i++) {
			p[i].score = tmp[i].score;
			p[i].size = tmp[i].size;
		}

		//delete[] tmp; �̰� �����ڵ忡 �Ƚ����ִµ� �� �Ƚ��൵�Ǵ°ɱ�..? �ǹ��̵��
	}

	printf("���� ���� �Է� �ϼ��� : ");
	scanf_s("%d", &p[count[0]].size);

	p[count[0]].score = new int[p[count[0]].size];		// ���� ���� �� ������ŭ �迭 �����ֱ� 
	// �캯���� �޸� �Ҵ� �� �º� score(int* score�̴ϱ� �����ͺ���)�� �Ҵ���� �迭 �޸� �ּ� �Ѱ��ֱ�

	for (int i = 0; i < p[count[0]].size; i++) {
		printf("%d�� ���� ������ �Է��ϼ��� : ", i + 1);
		scanf_s("%d", &p[count[0]].score[i]);			// �տ� &���� p[count[0]].score[i] �� �ּҼ��� ���̴� 
														// �ּҿ� �־�����ϴϱ� �տ� & �ٿ�
														// ������ �� �ٽ��ѹ� �� �κ�
	}

	count[0] += 1;			// ���� �� �־��� �Ŀ� int count �� ++

	return p;
}


void delete_user(Student** pp, int* count) {
	printf("������ ��ȣ�� �Է��ϼ��� : ");
	int del_idx = 0;
	scanf_s("%d", &del_idx);
	
	if (count[0] == 1) {
		pp[0] = 0;		// �Լ��� Student** pp �� �Է¹ޱ� ������ pp[0] (*pp)�� int* p ���� ��Ÿ����
	}
	else if (count[0] > 1) {
		Student* temp = pp[0];

		pp[0] = new Student[count[0] - 1];

		int j = 0;
		for (int i = 0; i < count[0]; i++) {
			if (i != del_idx) {
				pp[0][j].score = temp[i].score;
				pp[0][j].size = temp[i].size;
				j += 1;
			}
		}

		delete[] temp[del_idx].score;
		delete[] temp;
	}
	count[0] -= 1;

}



void main() {

	Student* p = 0;
	int count = 0;	// �л� ��� ( Struct* p �� ����Ű�� Struct �� ĭ���� ��Ÿ���µ�)

	int run = 1;
	while (run == 1) {
		print_user(p, count);

		printf("1.�߰� 2.���� 3.���");
		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 1) { p = insert_user(p, &count); }
		else if (sel == 2) { delete_user(&p, &count); }		// &p �� �����ִϱ� ������ �Լ��� �Է�Ÿ���� Struct** pp �ΰ� ���� �˾ƾ߰��� ~? *^^*
		else if (sel == 3) { print_user(p, count); }
	}

	system("pause");

}