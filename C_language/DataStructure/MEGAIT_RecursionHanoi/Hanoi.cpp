#include <Windows.h>
#include<stdio.h>
void Hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("���� 1�� %c ���� %c ���� �����.\n", from, to);
	}
	else {
		Hanoi(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c���� �����.\n", n, from, to);
		Hanoi(n - 1, tmp, from, to);
	}
}
void main() {
	Hanoi(3, 'a', 'b', 'c');
	system("pause");
}
