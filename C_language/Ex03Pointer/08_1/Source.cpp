#include <Windows.h>
#include <stdio.h>
#include <time.h>

void main() {
	srand(time(0));

	// �й� ���� ����

	int** pp = 0;
	int count = 0;
	int num = 0;

	int run = 1;
	while (run) {
		printf("�й�\t����\t����\n");
		for (int i = 0; i < count; i++) {
			printf("[%d] > %d��\t%d��\n", pp[i][0], pp[i][1], pp[i][2]);
		}

		printf("[1]�߰�\n");
		printf("[2]����\n");
		printf("�޴� ���� : ");
		int choice = 0;
		scanf_s("%d", &choice);

		if (choice == 1) {
			if (count == 0) {
				pp = new int*[1];

				pp[0] = new int[3];
			}
			else if (count > 0) {
				int** temp = pp;

				pp = new int*[count + 1];
				for (int i = 0; i < count; i++) {
					pp[i] = temp[i];
				}
				delete[] temp;

				pp[count] = new int[3];

			}
			int hakbun = 1000 + num;
			int kor = rand() % 100 + 1;
			int eng = rand() % 100 + 1;

			pp[count][0] = hakbun;
			pp[count][1] = kor;
			pp[count][2] = eng;

			count++; num++;

		}
		else if (choice == 2) {
			printf("������ �й��� �Է��ϼ��� : ");
			int del_hakbun = 0;
			scanf_s("%d", &del_hakbun);

			int del_idx = -1;
			for (int i = 0; i < count; i++) {
				if (pp[i][0] == del_hakbun) {
					del_idx = i;
				}
			}

			if (del_idx == -1) {
				printf("�ش� �й��� �������� �ʽ��ϴ�.\n");
				continue;
			}

			if (count == 1) {
				pp = 0;
				count = 0;
				num = 0;
			}
			else if (count > 1) {
				int** temp = pp;

				pp = new int*[count - 1];
				int j = 0; 
				for (int i = 0; i < count; i++) {
					if (i != del_idx) {
						pp[j] = temp[i];
						j++;
					}
				}

				delete[] temp[del_idx];		// Ű����Ʈ ! �� �̷��� �Ǵ��� �׸��׷��� ���ص��� ! �ذ� !
												
				delete[] temp;

			}
			count--;

		}
	}
	system("pause");
}

/*
delete[] : �迭��ü�� ���� ������ �Ҹ����� ȣ��� �޸� ȯ���� �Ѵ�
delete   : ���� ��ü�� ���� �Ҹ����� ȣ��� �޸� ȯ��

int*p = new int[5];
delete[] p;    (O)
//delete p;    (X)

����Ű�� ������p�� �ᱹ �ּҰ��̹Ƿ� delete�� delete[]�� ��������ʳ�? => ����� �ְŵ� !!
4����Ʈ int Ÿ���� 5�� �����ϰ� 
�޸� delete[] �� ������ ���
�� �迭�l ��Ҹ� 4����Ʈ�� 5�� ����������
delete�� ����ϰ� �Ǹ� 4����Ʈ ¥�� �޸𸮸� �� ���� ����

�츮�� new ������ ����Ͽ� �޸� �Ҵ�� �迭�� ũ�⿡ ���� ������ �����ϱ� ���� ���������� 4����Ʈ��ŭ �޸𸮸� �� �Ҵ��Ѵ�
�� �޸𸮸� �����Ҷ� delete[]�� ����ϸ� �� ���� Ȯ���Ͽ� ����������, delete �� ����ϸ� �迭�� ũ�⸦ Ȯ������ �ʰ� ����
( delete ����� ������ ��ü��ŭ �Ҹ��ڰ� ȣ����� �ʴ´�. �Ҹ��ڴ� �ѹ��� ȣ��ǰ� ������ �߻���Ų��. => �޸� ����(��)

*/