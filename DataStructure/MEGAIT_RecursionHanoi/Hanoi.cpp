#include <Windows.h>
#include<stdio.h>
void Hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("원판 1을 %c 에서 %c 으로 옯긴다.\n", from, to);
	}
	else {
		Hanoi(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옯긴다.\n", n, from, to);
		Hanoi(n - 1, tmp, from, to);
	}
}
void main() {
	Hanoi(3, 'a', 'b', 'c');
	system("pause");
}
