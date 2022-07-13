#include <Windows.h>
#include <stdio.h>
#include <time.h>
// ���� 9�� ���� 10�� �̿ϼ� �ٽú��� 

/*
# �л� �������� ���α׷�[����ü(����+�Լ�) ����]

��)
�й� = [1001, 1002, 1003, 1004, 1005]
���� = [  60,  100,   73,    3,   81]

���� 1) 1~100 ������ ���� ���� 5�� ����
���� 1) [60, 100, 73, 3, 81]

���� 2) �������� ���� ���

���� 3) �������� ���� ����
���� 3) ����(317��)

���� 4) �������� ��� ����
���� 4) ���(63.4��)

���� 5) �հݻ�(���� 75���̻�)�� �й��� ������ ����ü�� ������ ����ü �迭�� ����
���� 5) 1002�й�(100��), 1005�й�(81��)

���� 6) 1�� �л��� �й��� ������ ����ü�� ������ ����ü�� ����
���� 6) 1002�й�(100��)

���� 7) �й��� �Է¹޾� ���� ����
���� 8) ������ �Է¹޾� �й� ����

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

	void init() {
		count = 5;
		p = new Student[count];

		for (int i = 0; i < count; i++) {
			p[i].hakbun = 1001 + i;
		}
	}

	void test1() {
		for (int i = 0; i < count; i++) {
			p[i].score = rand() % 100 + 1;
		}
	}

	void test2() {
		for (int i = 0; i < count; i++) {
			printf("%d�й� (%d��) ", p[i].hakbun, p[i].score);
		}
		printf("\n");
	}

	int test3() {
		int total = 0;
		for (int i = 0; i < count; i++) {
			total += p[i].score;
		}
		return total;
	}

	float test4() {
		int total = test3();
		float avg = total / (float)count;
		// float = int / int; �ϸ� �������� �����ϳ��� float�� ����ȯ
		return avg;
	}

	Student* test5(int* p_size) {
		int size = 0;
		for (int i = 0; i < count; i++) {
			if (p[i].score >= 75) {
				size += 1;
			}
		}

		p_size[0] = size;

		//�̸� ��ĵ�ؼ� �հ��� ��� �˾Ƴ��� �����ŭ �����ֱ� ~
		Student* tmp = new Student[size];
		int j = 0;
		for (int i = 0; i < count; i++) {
			if (p[i].score >= 75) {
				tmp[j].hakbun = p[i].hakbun;
				tmp[j].score = p[i].score;
				j += 1;
			}
		}
		return tmp;
	}

	Student test6() {
		int max_s = 0; int max_idx = 0;
		for (int i = 0; i < count; i++) {
			if (max_s < p[i].score) {
				max_s = p[i].score;
				max_idx = i;
			}
		}

		Student tmp = { 0 };
		tmp.hakbun = p[max_idx].hakbun;
		tmp.score = max_s;
		return tmp;
	}

	int test7() {
		int score = 0;
		int num = 0;
		printf("�й� �Է� : ");
		scanf_s("%d", &num);
		for (int i = 0; i < count; i++) {
			if (num == p[i].hakbun) {
				score = p[i].score;
			}
		}
		return score;
	}

	int test8() {
		int score = 0;
		int num = 0;
		printf("���� �Է� : ");
		scanf_s("%d", &score);
		for (int i = 0; i < count; i++) {
			if (score == p[i].score) {
				num = p[i].hakbun;
			}
		}
		return num;
	}

	void test9() {
		int del = 0;
		printf("������ �й� �Է� : ");
		scanf_s("%d", &del);
		int check = -1;
		for (int i = 0; i < count; i++) {
			if (del == p[i].hakbun) {
				check = i;
			}
		}

		if (check == -1) { printf("�й��Է¿���\n"); }
		else {
			for (int i = check; i < count - 1; i++) {
				//p[i].hakbun = p[i + 1].hakbun;
				//p[i].score = p[i + 1].score;

				 p[i] = p[i + 1]; 
				// �̰� ����ü �� ������ �ּҸ� �ٲ��ִ°� ( �ӿ� ��������� ����Ű�� �ּҸ� �ٲ��ִ°� �ƴ϶� )
			}
			count -= 1;		// �߿����� �� �Ű��ְ� ���� �Ѹ� �پ����� count �� 1����
		}
	}

	//�����ڵ�
	//void test10(){
	//	for (int i = 0; i < count; i++) {
	//		int max_s = p[i].score; 
	//		int max_idx = i;

	//		for (int j = i; j < count; j++) {
	//			if (max_s < p[j].score) {

	//				Student tmp = p[max_idx];
	//				p[max_idx] = p[j];
	//				p[j] = tmp;
	//			}
	//		}
	//	}
	//}

	//�����ڵ�
	void test10() {
		for (int i = 0; i<count; i++) {
			int max_score = p[i].score;
			int max_idx = i;
			for (int j = i; j<count; j++) {
				if (max_score < p[j].score) {
					max_score = p[j].score;
					max_idx = j;
				}
			}
			Student tmp = p[i];
			p[i] = p[max_idx];
			p[max_idx] = tmp;
		}
	}
};

void main() {

	srand(time(0));
	Control c = { 0 };
	c.init();					// int count ������ struct Control ���� ��ġ�ϱ� ������ init()���� count = 5; 
								// �ѹ��� ���ָ� ���� �ٲ����� �ʴ��� struct ���� �Լ� ȣ���ϸ� count���� 5
	printf(">>>���� 1\n");
	c.test1();
	printf("\n");

	printf(">>>���� 2\n");
	c.test2();
	printf("\n");

	printf(">>>���� 3\n");
	int total = c.test3();
	printf("���� = %d��\n", total);
	printf("\n");

	printf(">>>���� 4\n");
	float avg = c.test4();
	printf("��� = %.1f��\n", avg);
	printf("\n");

	printf(">>>���� 5\n");
	int p_size = 0;
	Student* p = c.test5(&p_size);
	//	ó������ ��..��? p_size ������ �ͼ� �ּҸ� �� �Լ��� �־�����ϳ� ? ������ �������
	//	�Ʒ� for������ i<p_size ���� �������ϴϱ� �������� �� �� �� �־���ϴ±����� ������
	for (int i = 0; i < p_size; i++) {
		printf("%d�й� (%d��)", p[i].hakbun, p[i].score);
	}
	printf("\n");
	printf("\n");

	printf(">>>���� 6\n");
	Student tmp = c.test6();
	printf("1���л� : %d�й� (%d��)", tmp.hakbun, tmp.score);
	printf("\n");

	printf(">>>���� 7\n");
	int score = c.test7();
	printf("���� = %d��\n", score);
	printf("\n");

	printf(">>>���� 8\n");
	int hakbun = c.test8();
	printf("�й� = %d��\n", hakbun);
	printf("\n");

	printf(">>>���� 9\n");
	c.test9();
	c.test2();
	printf("\n");

	printf(">>>���� 10\n");
	c.test10();
	c.test2();
	printf("\n");

	system("pause");

}
