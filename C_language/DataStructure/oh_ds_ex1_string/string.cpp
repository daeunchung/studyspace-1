//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//#define BUFFER_SIZE 100
//
//// ���� 1
//int main() {
//	char * words[100];
//	int n = 0; // number of strings
//	char buffer[BUFFER_SIZE];
//
//	while (n < 4 && scanf("%s", buffer) != EOF) {
//		words[n] = _strdup(buffer);	
//		// strdup : �Ű������� �ϳ��� ���ڿ��� �޾Ƽ� ���ڿ��� �������� ���� �������� �ּҸ� ��ȯ�ϴ� POSIX �Լ�
//		// strcpy(str2, str1)
//		n++;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		printf("%s\n", words[i]);
//	}
//}