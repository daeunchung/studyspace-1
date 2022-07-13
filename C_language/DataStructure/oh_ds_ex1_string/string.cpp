//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//#define BUFFER_SIZE 100
//
//// 예제 1
//int main() {
//	char * words[100];
//	int n = 0; // number of strings
//	char buffer[BUFFER_SIZE];
//
//	while (n < 4 && scanf("%s", buffer) != EOF) {
//		words[n] = _strdup(buffer);	
//		// strdup : 매개변수로 하나의 문자열을 받아서 문자열의 복제본을 만들어서 복제본의 주소를 반환하는 POSIX 함수
//		// strcpy(str2, str1)
//		n++;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		printf("%s\n", words[i]);
//	}
//}