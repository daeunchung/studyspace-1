#include <Windows.h>
#include <stdio.h>
#include <string.h> // ���ڿ� ���� �Լ����� 

//	����ü�� ���ڿ� [����]

struct User {
	char* name;
	int score;
};

void main() {
	User* p = 0;		// ���� ! ����ü ���� ����� �ƴϰ� ����ü ������ �����Դϴ� !
	int count = 0;

	int run = 1;
	while (run) {
		for (int i = 0; i < count; i++) {
			printf("[%d]�̸� : %s / ���� : %d\n", (i + 1), p[i].name, p[i].score);
		}

		printf("1.�߰� 2.���� 3.���"); printf("\n");

		printf("�޴��� �����ϼ��� : ");
		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 1) {
			if (count == 0) {
				p = new User[count + 1];
			}
			else if (count > 0) {
				User* temp = p;

				p = new User[count + 1];
				for (int i = 0; i < count; i++) {
					p[i].name = temp[i].name;
					p[i].score = temp[i].score;
				}
				delete[] temp;

			}

			printf("�̸��� �Է��ϼ��� : ");
			char name[100] = { 0 };
			scanf_s("%s", name, 100);

			int len = strlen(name);
			p[count].name = new char[len + 1];
			strcpy_s(p[count].name, len + 1, name);

			printf("������ �Է��ϼ��� : ");
			scanf_s("%d", &p[count].score);

			count += 1;

		}
		else if (sel == 2) {
			printf("������ ��ȣ�� �����ϼ��� : ");
			int del_idx = 0;
			scanf_s("%d", &del_idx);

			del_idx -= 1;

			if (count == 1) {
				p = 0;
			}
			else if (count > 1) {
				User* temp = p;

				p = new User[count - 1];
				//p = (User*)malloc(sizeof(User) * (count-1));  �����Ҵ� ������ ~

				int j = 0; 
				for (int i = 0; i < count; i++) {
					if (i != del_idx) {
						p[j].name = temp[i].name;
						p[j].score = temp[i].score;
						j += 1;
					}
				}

				delete[] temp[del_idx].name;
				// ���ڿ� �̱� ������ User �� ������ �ִ�
				// *temp ĭ �޸� �Ӹ��ƴ϶� , temp[del_idx].name �� �������ִ� char �޸𸮵� free ������Ѵ�
				// ==> ���� �����ϴ� ������(��Ȯ��)

				delete[] temp;
				// int score �� �ּ�����ĭ, char* name �� �ּ�����ĭ ����� �޸� �Ҵ�ĭ�� �޸𸮸� free ���ش�.
				// �� ���� char* name �� ������ �̱� ������ �����Ͱ� ����Ű�� �迭�� �޸𸮵� �ѹ� �� ��������ؼ� ������ ����Ǵ� ��.

			}
			
			count -= 1;

		}
		else if (sel == 3) {
			for (int i = 0; i<count; i++) {
				printf("�̸� : %s / ���� : %d\n", p[i].name, p[i].score);
			}
		}
	}
	system("pause");
}

