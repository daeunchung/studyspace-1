#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// �ݺ��� ���� 2���� // 1)�ʱ�� 2)���ǽ� 3)������ 
// 1) while
// 2) for   // ��������;(�����ݷ�)�� ����.

void main() {

	//������ ��� 4���� 
	// a = a + 1;
	// a += 1;
	// a++;
	// ++a;

	int n = 0;    // �ʱ�� 
	while (n < 4) {  // ���ǽ�
		printf("%d", n);
		n = n + 1;  // ������ 
	}
	printf("\n");
	for (int i = 0; i < 4; i = i + 1) {
		printf("%d", i);
	}
	printf("\n");

	system("pause");

	//	�����л����� [����]
	srand(time(0));
	// 1)�����л����� 2)���θ� 3)����Ų���
	// �����л� ���� ==> 3�� �� �������� 0~100���� ���
	// ��ȣ�� 1000 ~ 1002 ���� ��� 
	// 1����� 
	int max = 0; int max_num = 0;
	for (int i = 1000; i < 1003; i++) {
		int ran = rand() % 101;
		printf("%d  :   %d", i, ran); printf("\n");
		if (max < ran) {
			max = ran;
			max_num = i;
		}
	}
	printf("1�� : %d  :  %d", max_num, max); printf("\n");

	system("pause");




	// ����Ų��� 31 [����]
	// p1 , p2 �� �����ư��鼭 1~3�� �Է��Ѵ�.
	// br �� p1 , p2 �� ���� ���� �����Ѵ�.
	// br �� 31 �� �Ѿ�� �������� ( �ѱ����� �й� : �¸������)
	// p1 ==> 2  ,  br ==> 2
	// p2 ==> 3  ,  br ==> 5
	// p1 ==> 1  ,  br ==> 6  .. br > 10 ==> ���� 
	int p1 = 0; int p2 = 0; int br = 0;
	int turn = 0; int run = 1;
	while (1) {
		if (turn == 0) {
			printf("[p1] 1~3�� �Է��ϼ���"); printf("\n");
			scanf_s("%d", &p1);
			br += p1; turn = 1;
		}else if (turn == 1) {
			printf("[p2] 1~3�� �Է��ϼ���"); printf("\n");
			scanf_s("%d", &p2);
			br += p2; turn = 0;
		}

		if (br >= 31) {
			if (turn == 0) {
				printf("p1�¸�"); printf("\n");
			}
			else if (turn == 1) {
				printf("p2�¸�"); printf("\n");
			}
			break;
		}
	}

	// ATM pass

}
