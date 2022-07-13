#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h> 
#include <string.h>

// ������
// �ȵ� 
// �ٽú���






// ���� �Է� �����Ŵ� �׳� �־��ְ� // ���ڿ� �Է� �����Ŵ� �̸� char* ������ �޸� �Ҵ��ϰ� strcpy ������ ~

struct Student {
	char* name;			// �̸���������������
	int* score;			// ������������������
	int score_count;	// ������ ����
};

void main() {

	Student* p = 0;		// ����ü Student����������
	int st_count = 0;	// �л��� ( ����ü ���� ��Ÿ���� ���� )

	int run = 1;
	while (run) {
		printf("[1]�߰�\n");
		printf("[2]����\n");		// �̸� �Է¹޾� ����
		printf("[3]����\n");
		printf("[4]���\n");

		printf("�޴� ���� : ");
		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 1) {

			if (st_count == 0) {
				p = new Student[1];
			}
			else if (st_count > 0) {
				Student* temp = p;
				p = new Student[st_count + 1];

				for (int i = 0; i < st_count; i++) {
					p[i] = temp[i];
				}
				delete[] temp;
			}
			printf("���� �� �Է� : ");
			scanf_s("%d", &p[st_count].score_count);

			p[st_count].score = new int[p[st_count].score_count];
			for (int i = 0; i < p[st_count].score_count; i++) {

				printf("%d�� ���� ������ �Է��ϼ��� : ", (i + 1));
				scanf_s("%d", &p[st_count].score[i]);
			}

			printf("�̸��� �Է��ϼ��� : ");
			char temp[100] = { 0 };
			scanf_s("%s", temp, 100);		// (����������, �Է¹޴¸޸��̸�, �޸�ũ��)

			int len = strlen(temp);

			p[st_count].name = new char[len + 1];
			strcpy_s(p[st_count].name, len + 1, temp);
			//	p[st_count].name�� len + 1 ũ�⸸ŭ temp �� ���빰�� copy

			st_count += 1;

		}
		else if (sel == 2) {
			printf("������ �̸��� �Է��ϼ��� : ");
			char temp[100] = { 0 };
			scanf_s("%s", temp, 100);		// (����������, �Է¹޴¸޸��̸�, �޸�ũ��)

			int del_idx = -1;
			for (int i = 0; i < st_count; i++) {
				if (strcmp(p[i].name, temp) == 0){
					del_idx = i;
				} 
			}


			if (del_idx == -1) {
				printf("�̸��� �߸��Է��߽��ϴ�.\n");
			}
			else {
				if (st_count == 1) {
					p = { 0 };
				}
				else if (st_count > 1) {
					Student* temp = p;
					p = new Student[st_count - 1];

					int j = 0;
					for (int i = 0; i < st_count-1; i++) {
						if (i != del_idx) {
							p[i] = temp[j];
						}
						j += 1;
					}

					/* �Ǵ� ������ ���� ���� ����
					p = new Student[st_count - 1];
					for(int i=0; i<remove; i++){
					p[i] = temp[i];
					}
					for(int i=remove; i<st_count - 1; i++){
					p[i] = temp[i + 1];
					}*/

					delete[] temp[del_idx].name;
					delete[] temp[del_idx].score;
					delete[] temp;
					// temp �� struct Student {char* name; int* score;	int score_count;}; ������ 
					// Student* (�����ͺ���)�ϱ� �ش� ����ü�� �ӿ� ������ �ִ� ������ �������� �� Ÿ�� ���� ���빰�� ���� ��������� 
					// ==> �׸����� �׷����� ���� ���� �߿� !

					st_count -= 1;
				}
			}
		}
		else if (sel == 3) {				// �̸����� ����	(�������� �̰��� �翬��)

			//for (int i = 0; i < st_count; i++) {
			//	// �����Ҳ��� ���� ù �� ������ �ھƳ���
			//	int idx = i;
			//	char max[100] = { 0 };
			//	strcpy_s(max, 100, p[i].name);	// ���� 3���� ���� ���� 
			//	// (����޴��ּ�������, ����޴��ּ������Ͱ� ����Ű�� �޸�ũ��, �������ٹ��ڿ��ּ�������)
			//	
			//	for (int j = i; j < st_count; j++) {
			//		if (strcmp(max, p[j].name) == 1) {
			//			// 	if (strcmp([idx].name, p[j].name) == 1 ) {} : ������
			//			// strcmp_s(a,b) a�� b���� �� ũ�� ��ȯ : ū���� �ڷΰ�����
			//			strcpy_s(max, 100, p[i].name);
			//			idx = j;
			//		}
			//	}
			//	Student temp = p[i];
			//	p[i] = p[idx];
			//	p[idx] = temp;
			//}

			for (int i = 0; i < st_count; i++) {
				for (int j = i; j < st_count; j++) {
					if (strcmp(p[i].name, p[j].name) == 1) {
						Student temp = p[i];
						p[i] = p[j];
						p[j] = temp;
					}
				}
			}	
		}
		else if (sel == 4) {
			for (int i = 0; i<st_count; i++) {
				printf("%s : ", p[i].name);
				for (int j = 0; j<p[i].score_count; j++) {
					printf("%d ", p[i].score[j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}

	system("pause");
}
