#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {

	// # ���ڿ� �߶󳻱�
	// �޸�(,)�� �����ڷ� ���ڸ� �߶󳻾� 2���� ������ ���� pp�� ���ʴ�� �����ϼ���.
	char str[100] = "hello,java,android";
	char** pp = 0;

	char* end = 0;

	for (int i = 0; i < 3; i++) {
		pp[i] = strtok_s(str, ",", &end);

	}


	system("pause");
}
