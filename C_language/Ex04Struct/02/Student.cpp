#include <Windows.h>
#include <stdio.h>

/*
# �л� �������� ���α׷�[����ü(����) ����]

��)
�й� = [1001, 1002, 1003, 1004, 1005]
���� = [  60,  100,   73,    3,   81]

���� 1) 1~100 ������ ���� ���� 5�� ����
���� 1) [60, 100, 73, 3, 81]

���� 2) �������� ���� ���

���� 3) �������� ���� ���
���� 3) ����(317��)

���� 4) �������� ��� ���
���� 4) ���(63.4��)

���� 5) �հݻ�(���� 75���̻�)�� �й��� ���� ���
���� 5) 1002�й�(100��), 1005�й�(81��)

���� 6) 1�� �л��� �й��� ���� ���
���� 6) 1002�й�(100��)

���� 7) �й��� �Է¹޾� ���� ���
���� 8) ������ �Է¹޾� �й� ���

���� 9) �й��� �Է¹޾� �л�����(�й��� ����) ����
���� 9) ���� �й� �Է� ��, ����ó��

���� 10) ���������� �������� ����

*/

struct Student {
	int hakbun;
	int score;
};

struct Control {
	Student* p;
	int count;
};

void main() {

	Control c = { 0 };

	c.count = 5;
	c.p = new Student[5];

	for (int i = 0; i<c.count; i++) {
		c.p[i].hakbun = 1001 + i;

	}

	printf(">>>���� 1\n");
	for (int i = 0; i < c.count; i++) {
		c.p[i].score = rand() % 100 + 1;
	}
	printf("\n");
	
	printf(">>>���� 2\n");
	for (int i = 0; i < c.count; i++) {
		printf("%d�й�(%d��) ", c.p[i].hakbun, c.p[i].score);
	}
	printf("\n");


	printf(">>>���� 3\n");
	int total = 0;
	for (int i = 0; i < c.count; i++) {
		total = c.p[i].score;
	}
	printf("���� : %d��\n", total);
	printf("\n");


	printf(">>>���� 4\n");
	float avg = total / (float)c.count;
	printf("��� : %.1f��\n", avg);
	printf("\n");


	printf(">>>���� 5\n");
	for (int i = 0; i < c.count; i++) {
		if (c.p[i].score >= 75) {
			printf("%d�й�(%d��) ", c.p[i].hakbun, c.p[i].score);
		}
	}
	printf("\n");


	printf(">>>���� 6\n");
	int max = 0; int max_idx;

	for (int i = 0; i < c.count; i++) {
		if (max < c.p[i].score ) {
			max = c.p[i].score;
			max_idx = i;
		}
	}
	printf("%d�й�(%d��) ", c.p[max_idx].hakbun, max );
	printf("\n");


	printf(">>>���� 7\n");
	printf("�й� �Է� : ");
	int sNum = 0; int sIdx = -1;
	scanf_s("%d", &sNum);
	for (int i = 0; i < c.count; i++) {
		if (c.p[i].hakbun == sNum ) {
			sIdx = i;
			printf("%d�й�(%d��) ", c.p[sIdx].hakbun, c.p[sIdx].score);
			break;
		}
	}

	if (sIdx == -1) {
		printf("�ش� �й��� �������� �ʽ��ϴ�.\n");
	}
	printf("\n");
	



	printf(">>>���� 8\n");
	printf("���� �Է� : ");
	int sScore = 0;  
	sIdx = -1;
	scanf_s("%d", &sScore);
	for (int i = 0; i < c.count; i++) {
		if (c.p[i].score == sScore) {
			sIdx = i;
			printf("%d�й�(%d��) ", c.p[sIdx].hakbun, c.p[sIdx].score);
			break;
		}
	}

	if (sIdx == -1) {
		printf("�ش� ������ ���� �л��� �������� �ʽ��ϴ�.\n");
	}
	printf("\n");


	printf(">>>���� 9\n");
	printf("������ �л��� �й� �Է� : ");
	int del = 0;
	scanf_s("%d", &del);

	int delete_idx = -1;
	for (int i = 0; i < c.count; i++) {
		if (del == c.p[i].hakbun) {
			delete_idx = i;
		}
	}

	if (delete_idx == -1) {
		printf("�й��� �߸� �Է��ϼ̽��ϴ�.\n");
	}
	else {
		// [3]�����Ϳ��Լ� [08]�л��������� ó�� �迭 ĭ�� �����ϸ鼭 ���� ������ �ʰ� �׳� size[5] ¥�� �迭ũ�� �����ϸ鼭 �ּҰ��� �Ű��ֳ�

		// �ǹ�. ! main���ۺο� 
		// c.p = new Student[c.count]; 
		// c.count = 5; �� �Ұ����Ѱɱ� ? 

		for (int i = delete_idx; i < c.count - 1; i++) {
			c.p[i].hakbun = c.p[i + 1].hakbun;
			c.p[i].score = c.p[i + 1].score;
		}
		c.count--;
	}
	for (int i = 0; i<c.count; i++) {
		printf("%d�й�(%d��) ", c.p[i].hakbun, c.p[i].score);
	}
	printf("\n");
	printf("\n");


	
	// ���� 10 ) ���������� �������� ����

	// 2�����迭 �������� ���� �����غ���� : ��(i) ���� �ڿ��ִ� ��� �� ��(i) ���� ���� ū����� ��������
	printf(">>>���� 10\n");

	//for (int i = 0; i < c.count; i++) {
	//	for (int j = i; j < c.count; j++) {
	//		if (c.p[i].score < c.p[j].score) {

	//			int* tmp = (int*)malloc(sizeof(Student) * 1);
	//			// ����ü struct �� �ּҸ� ��� �������ּҸ� �ϳ� �ļ� �� ���� ���ؼ� 
	//			// i �� j �� ����ü �ּ���ü�� ��ȯ�ϴ� ������ ¥���..���� �߾ȵǳ� ��,�� �Ф�..
	//		    tmp = c.p[i];
	//			c.p[i] = c.p[j];
	//			c.p[j] = tmp;
	//		}
	//	}
	//}

	for (int i = 0; i < c.count; i++) {
		int max_score = c.p[i].score;
		int max_idx = i;
		for (int j = i; j < c.count; j++) {
			if (max_score < c.p[j].score) {
				max_score = c.p[i].score;
				max_idx = j;
			}
		}

		int tmp = c.p[i].score;
		c.p[i].score = c.p[max_idx].score;
		c.p[max_idx].score = tmp;

		 tmp = c.p[i].hakbun;
		c.p[i].hakbun = c.p[max_idx].hakbun;
		c.p[max_idx].hakbun = tmp;
	}

	for (int i = 0; i < c.count; i++) {
		printf("%d�й�(%d��) ", c.p[i].hakbun, c.p[i].score);
	}

	printf("\n");
	printf("\n");


	system("pause");

}
