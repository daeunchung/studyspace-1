#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {

	// # 문자열 잘라내기
	// 콤마(,)를 구분자로 문자를 잘라내어 2차원 포인터 변수 pp에 차례대로 저장하세요.
	char str[100] = "hello,java,android";
	char** pp = 0;

	char* end = 0;

	for (int i = 0; i < 3; i++) {
		pp[i] = strtok_s(str, ",", &end);

	}


	system("pause");
}
