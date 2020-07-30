// fgetc과 getchar 함수는 입력을 받는 함수인데 언제 EOF를 반환할까
// 1. 함수 호출의 실패
// 2. 윈도우에서 Ctrl + z, 리눅스에서 Ctrl + d를 입력했을 경우
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