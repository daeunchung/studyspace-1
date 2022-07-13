#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>	// malloc �Լ�
#include <string.h>
// ���� ����� (io)
// 1.����
void main() {
	FILE * file;	// ������ �޸���ġ (���� ������Ʈ)
	fopen_s(&file, "test.txt", "wt");
	// 1. ���� �����	[1] &file		==> ������ �޸��ּ�
	//					[2] "test.txt"	==> �����̸�
	//					[3] "wt"		==> write.text �� ���� ��������� ����
	fputs("��ο쾾���", file);			// 2. ���Ͽ� ���������ϱ�
	fclose(file);						// 3. ���� �ݱ�

	// ����1) �Ʒ� �迭�� test01.txt ���Ͽ� ����
	// ���� ==> �Ʒ��� ������� ����
	// 100/34/65/2
	int arr[4] = { 100, 34, 65, 2 };

	// test01.txt ==> int ���·� �׳� �־ ������ֱ�

	//fopen_s(&file, "test01.txt", "wt");
	//for (int i = 0; i < 4; i++) {
	//	fprintf_s(file, "%d", arr[i]);

	//	if (i < 3) {
	//		fprintf_s(file, "%s", "/");
	//	}
	//}

	//test02.txt ==> int �� ���ڿ��� �ٲ㼭 ���ڿ� �������ֱ�
	fopen_s(&file, "test02.txt", "wt");

	char itoatemp[100] = { 0 };
	for (int i = 0; i < 4; i++) {
		_itoa_s(arr[i], itoatemp, 10);
		fputs(itoatemp, file);

		if (i < 3) {
			fputs("/", file);
		}
	}
	fclose(file);
}


/*
���ݱ��� printf�� ������ �����Ͽ� ���ڿ��� ȭ�鿡 ����ϰ�, sprintf�� ������ �����Ͽ� ���ڿ��� �����߽��ϴ�. �׷� ���ڿ��� ���Ͽ� �� ���� �������? �̶��� printf�� ���� ������ fprintf�� ����ϸ� �˴ϴ�.
���Ͽ� ���ڿ��� �� ���� ���� fopen �Լ��� ������ ��� ���� �����͸� ���� �� fprintf �Լ��� ����մϴ�
(stdio.h ��� ���Ͽ� ����Ǿ� �ֽ��ϴ�).

FILE *�������̸� = fopen(���ϸ�, ���ϸ��);
	FILE *fopen(char const *_FileName, char const *_Mode);
	�����ϸ� ���� �����͸� ��ȯ, �����ϸ� NULL�� ��ȯ
fprintf(����������, ����, ��1, ��2, ...);
	int fprintf(FILE * const _Stream, char const * const _Format, ...);
	�����ϸ� �� ���ڿ��� ���̸� ��ȯ, �����ϸ� ������ ��ȯ
fclose(����������);
	int fclose(FILE *_stream);
	�����ϸ� 0�� ��ȯ, �����ϸ� EOF(-1)�� ��ȯ


Ctrl + f5 ������ �ܼ�â ����
�ַ�� Ž���⿡�� ������Ʈ ���� Ŀ�� ���� ���콺 ��Ŭ��, ����Ž���� ���� ��������
���� �ȿ� .txt ���� ���� �ȿ� �������
https://dojang.io/mod/page/view.php?id=607
*/


/*scanf�� ������ �Է��� ���� ��
%c�� �Է¹����� ���� ���� ���ڸ� �Է� ���� �� �ְ� �ǰ� %s�� ������ �ϳ��� �ܾ �Է� ���� �� �ִ�. 
������� apple�� ��� %c�� 'a'�� %s�� ��� 'apple'�� �������ڷ� �ް� �ȴ�.
scanf�� ���ڸ� �Է��� ���� �� �Ϲ� int�� ������ ���� �տ� &�� �ٿ��� ������ ���ڿ��� �׷��� �ʴ�.
ex) scanf("%d", &ex1) int�� ���� ex1�� �޴� ���
ex) scanf("%s", ex2) char�� ���� ex2�� �޴� ���
��ó: https://coolbre.tistory.com/18 [dev80]*/


/*itoa�� ����ũ�μ���Ʈ ���־�Ʃ��������� �����س��� �Լ��Դϴ�. 
���� ����� �� �ٸ� �÷������� �����Ͻô� ���� ����Ͻ� ���� ������ �̴ϴ�.
�׷��� itoa �Լ� ��ſ� sprintf�� ����ϴ� ���� ����帳�ϴ�! */