#include <Windows.h>
#include <stdio.h>

// # �����ѹ迭 => ����Ʈ / ���� 

void main() {

	int* p = 0;									// Q. �ּҰ� 0�� �ڸ��� ���� ���� ��������� ���� �˰� ? 
	int count = 0;

	int run = 1;
	while (run == 1) {

		// ���� �κп� �׻� ���� ����ѹ� ���ְ�
		for (int i = 0; i < count; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");

		printf("[1] �߰�\n");
		printf("[2] ����\n");
		printf("[3] ����\n");
		printf("[0] ����\n");

		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 0) { run = 0; }
		else if (sel == 1) {
		
			if (count == 0) {
				//	�Ѱ�¥�� �� ���ֱ�
				p = new int[1];
			}
			else if (count > 0) {
				//	p�� ���� �ּҰ��� ��� �ӽ������ͺ������� �Ѱ��ְ�
				int* temp = p;
				//	�� �� �ı�
				p = new int[count + 1];	
				for (int i = 0; i < count; i++) {
					p[i] = temp[i];
				}
				delete[] temp;
			}

			printf("�߰��� �� : ");
			int num = 0;
			scanf_s("%d", &num);
			p[count] = num;
			count++;
		}
		else if (sel == 2) {
		
			printf("������ �� : ");
			int num;
			scanf_s("%d", &num);

			int del_idx = -1;
			for (int i = 0; i < count; i++) {
				if (p[i] == num) {
					del_idx = i;
				}
			}

			if (del_idx == -1) {
				printf("�Է��� ���� �������� �ʴ´�");
				continue;
			}

			if (count == 1) {
				p = 0;		// �迭�� ����Ű�� �ּҰ��� 0���� �����
			}
			else if(count > 1){
				int* temp = p;

				p = new int[count - 1];
				int j = 0;
				for (int i = 0; i < count; i++) {
					if (i != del_idx) {
						p[j] = temp[i];
						j++;
					}
				}
				delete[] temp;
			}
			count--;
		}
		else if (sel == 3) {
		
			printf("������ ��ġ �Է� : ");
			int insert_idx = 0;
			scanf_s("%d", &insert_idx);

			if (count < insert_idx || insert_idx < 0) {
				printf("�ش� ��ġ�� ���� �Ұ���");
				continue;
			}

			printf("������ �� �Է� : ");
			int insert_num = 0;
			scanf_s("%d", &insert_num);

			if (count == 0) {
				p = new int[1];
			} 
			else if (count > 0) {
				int* temp = p;

				p = new int[count + 1];
				int j = 0;
				for (int i = 0; i < count+1; i++) {
					if (i != insert_idx) {
						p[i] = temp[j];
						j++;
					}
				}
				delete[] temp;
			}
			p[insert_idx] = insert_num;
			count++;
		}
	}
	system("pause");
}
