#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {

	// strcmp, strlen, strcpy_s (compare, length, copy)
	// strcat_s, strtok_s (concatenate �����Ű��, tokenize ��������) 
	/*
	strcat : https://dojang.io/mod/page/view.php?id=359

	char *s1 = "world";    // ���ڿ� ������
	char *s2 = "Hello";    // ���ڿ� ������
	strcat(s2, s1);    // ====> ���� ����

	���ڿ� ������ s2�� �б� ���� �޸𸮶� ���ڿ��� ���� �� �����ϴ�.
	���ڿ��� ���̷��� s2�� ���Ⱑ �����ϵ��� malloc �Լ��� ���� �޸𸮸� �Ҵ��ϰ�, 
	���ڿ��� ���� �� �ֵ��� ������ �˳��ϰ� 20���� �������ݴϴ�.

						 ��
						 ��
					    \  /
						 \/

	char *s1 = "world";                      // ���ڿ� ������
	char *s2 = malloc(sizeof(char) * 20);    // char 20�� ũ�⸸ŭ ���� �޸� �Ҵ�

	strcpy(s2, "Hello");   // s2�� Hello ���ڿ� ����

	strcat(s2, s1);       // s2 �ڿ� s1�� ����

	printf("%s\n", s2);   // Helloworld

	free(s2);    // ���� �޸� ����

	�̷������� ����ؾ��� !!




	strtok : https://dojang.io/mod/page/view.php?id=376
	���伳�� ���� �� ��������
	*/



	// �ֹ���/�̿���/�����/��ö��/������
	// ������ ���ڿ��� �����ϱ�
	char name[5][100] = { 
		{ "�ֹ���" },{ "�̿���" },{ "�����" },{ "��ö��" },{ "������" }
	};

	char temp[1000] = { 0 };
	for (int i = 0; i < 5; i++) {
		strcat_s(temp, name[i]);
		if (i < 4) {
			strcat_s(temp, "/");
		}
	}

	printf("%s", temp);	printf("\n");

	// ----------------------------------------------------------------------
	// ���ڸ� ���ڷ� ��ȯ
	// _itoa_s(1.�����Ҽ��� 2.���ڹ迭 3.10����)
	char itoa_temp[100] = { 0 };		// ������ ���ڿ��� ���� ���ְ�
	_itoa_s(1001, itoa_temp, 10);
	printf("%s", itoa_temp);	printf("\n");

	int score[5] = { 10, 50, 30, 50, 7};
	int num[5] = { 1001, 1002, 1003, 1004, 1005 };

	char data[1000] = { 0 };
	strcat_s(data, "5");
	strcat_s(data, "\n");

	for (int i = 0; i < 5; i++) {
		_itoa_s(num[i], itoa_temp, 10);		// ���ڴ� ���ڷ� ��ȯ���ְ� �迭�� �迭�� ����������.
		strcat_s(data, itoa_temp);
		strcat_s(data, "/");

		strcat_s(data, name[i]);
		strcat_s(data, "/");

		_itoa_s(score[i], itoa_temp, 10);		
		strcat_s(data, itoa_temp);

		if (i < 4) {
			strcat_s(data, "\n");
		}
	}

	printf("%s", data); printf("\n");

	system("pause");
}