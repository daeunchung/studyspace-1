#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*scanf_s �Լ��� ���� _s�� ���� �Լ����� ���ڿ��� ���� �� ����ڰ� �Է��� ������ ������ �޸��� ũ�⸦
�Ѿ�� ������ ���� ���� ����� �޸��� ũ�⸦ ����ؾ� �մϴ�.*/

/*fopen�� fopen_s �� ��� �ٸ��� ����ؾ� �ϴ��� �������ִ� ��ũ
https://blog.naver.com/tipsware/221663656260
*/

// Ż��
// �ȵ�
// �ٽ��ؾ���

struct User {
	int num;	char id[100];	char pw[100];
};

void main() {
	User* p = 0;
	int userCount = 0;
	int run = 1;
	// 0���϶� ���� ==>

	while (1) {
		printf("1.ȸ������ 2.Ż�� 3.���� 4.���  ");
		int sel;
		scanf_s("%d", &sel);

		if (sel == 1) {
			if (userCount == 0) {
				p = new User[1];
			}
			else {
				User* temp = p;
				p = new User[userCount + 1];
				for (int i = 0; i < userCount; i++) {
					p[i] = temp[i];
				}
				delete[] temp;
			}

			p[userCount].num = 1000 + userCount + 1;
			printf("���̵� �Է��ϼ��� ");
			scanf_s("%s", p[userCount].id, 100);
			printf("��й�ȣ�� �Է��ϼ��� ");
			scanf_s("%s", p[userCount].pw, 100);

			userCount += 1;
		}



		else if (sel == 2) {
			printf("Ż���� ���� ���̵� �Է��ϼ��� ");
			char* del_id;

			scanf_s("%s", &del_id);

			int del_idx = -1;
			for (int i = 0; i < userCount; i++) {
				if (p[i].id == del_id) {
					del_idx = i;
				}
			}


			if (userCount == 1) {
				p = { 0 };
			}
			else if(userCount > 1){
				User* temp = p;
				p = new User[userCount - 1];

				int j = 0;
				for (int i = 0; i < userCount-1; i++) {
					if (j != del_idx) {
						p[i] = temp[j];
						j++;
					}
				}
				delete[] temp;
			}
			userCount = -1;
		}


		else if (sel == 3) {
			if (userCount <= 0) {
				continue;
			}
			char data[10000] = { 0 };
			char itoatemp[1000] = { 0 };
			//	1. ���ο��� ����->���ڿ�		2. "\n"		
			//	3. ȸ����ȣ ����-> ���ڿ�		4. "/"
			//	5. ȸ��id	6."/"	7.ȸ��pw		8."/"	
			//	9. �� ȸ�� ������ "\n"

			_itoa_s(userCount, itoatemp, 10);					// 10������
			strcat(data, itoatemp);
			strcat(data, "\n");

			for (int i = 0; i < userCount; i++) {
				_itoa_s(p[i].num, itoatemp, 10);
				strcat(data, itoatemp);
				strcat(data, "/");
				strcat(data, p[i].id);
				strcat(data, "/");
				strcat(data, p[i].pw);
				if (i < userCount - 1) {
					strcat(data, "\n");
				}
			}
			printf("%s", data);	printf("\n");
			FILE * file = 0;
			fopen_s(&file, "test01.txt", "wt");
			fputs(data, file);
			fclose(file);
		}


		else if (sel == 4) {
			for (int i = 0; i < userCount; i++) {
				printf("[%d] [%s] [%s]", p[i].num, p[i].id, p[i].pw);
				printf("\n");
			}
		}
	}
}


/*
errno_t fopen_s(FILE **pfp, const char *path,const char *mode); ���� ��Ʈ���� ���� �Լ�
�Է� �Ű� ���� ����Ʈ
1. pfp �� ���� ��Ʈ���� ������ FILE *���� ������ �ּ�
2. path ���� ��� Ȥ�� ��� ���
3. mode rwba+�� ���� ���ڿ�, fopen�� �����ϴ�.
��ȯ ��

�����ϸ� 0, �����ϸ� ���� ��

C11 ǥ�ؿ����� FILE ����ü�� struct _iobuf�� ���� ����� ����� �ֽ��ϴ�. 
�����ڿ� ���� ���� ����� �����ϴ� ���� �����Ͽ� �������� �����ϰ� �ֽ��ϴ�. 
�׸��� fopen �Լ��� ��ȯ ���� ù ��° �Է� ���ڷ� 
FILE ������ ������ �ּ�(FILE �������� ������)�� �޾� �����ϴ� fopen_s �Լ��� �����մϴ�.
*/