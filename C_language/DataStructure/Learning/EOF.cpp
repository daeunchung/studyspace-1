// fgetc�� getchar �Լ��� �Է��� �޴� �Լ��ε� ���� EOF�� ��ȯ�ұ�
// 1. �Լ� ȣ���� ����
// 2. �����쿡�� Ctrl + z, ���������� Ctrl + d�� �Է����� ���
#include <stdio.h>
int main() {
	int ch;
	while (1) {
		ch = getchar();
		if (ch == EOF)
			break;
		putchar(ch);
	}
	return 0;
}