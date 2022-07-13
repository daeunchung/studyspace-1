#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���ڿ� �ڸ���	==> strtok_s
// ���ڸ� ���ڷ� ��ȯ	==> atoi
/*
char *strtok_s(char *_String, const char *_Delimit, char **_Context);
[ ��ȯ�� :: ��е� ���ڿ� �� ù��° ���ڿ��� ���� �ּ� ]

[ ù��° �μ� :: ���� ���ڿ� ]
�� �Լ��� ���� ���ڿ��� �����մϴ�.
���� ���ڿ� ���(const char *)�� �����ϸ� ���� ������ ���α׷��� �ߴܵ� �� �ֽ��ϴ�.
( strtok("1234 5678", ...); // �̷��� ����ϸ� �� �˴ϴ�. )

[ �ι�° �μ� :: ���� ��ȣ ���� ]
���� ��ȣ�� ���ڿ� ���·� �����ϸ� �������� ����� �� �ֽ��ϴ�.

[ ����° �μ� :: ��е� ���ڿ� �� �ι�° ���ڿ��� ���� �ּҸ� ������ ������ ������ �ּ� ]
*/
struct Student {
	char* name;
	int score;
};

void main() {
	char data[100] = "3\n��ö��/20\n�̸���/30\n�ֹμ�/50";
	printf("%s", data); printf("\n");
	char* end;
	char* front;
	front = strtok_s(data, "\n", &end);					// ����° �μ��� ������ ������ �ּ��ΰ� ������
	// "\n" �� �������� "3" �� front�� ����
	// ���� "��ö��/20\n�̸���/30\n�ֹμ�/50" �� end �� ����
	printf("%s", front); printf("\n");
	printf("%s", end); printf("\n");

	int size = atoi(front);
	// �ڹٿ��� Integar.parseInt�� �����ǰ��� ��.��
	Student* p = new Student[size];
	for (int i = 0; i < size; i++) {
		front = strtok_s(end, "\n", &end);
		char* end2;
		front = strtok_s(front, "/", &end2);
		int len = strlen(front);
		p[i].name = new char[len + 1];			// ���� null �� ���ڸ� Ȯ��
		strcpy_s(p[i].name, len + 1, front);
		p[i].score = atoi(end2);
	}

	for (int i = 0; i < size; i++) {
		printf("[%s]", p[i].name);
		printf("[%d]", p[i].score);	printf("\n");
	}
}