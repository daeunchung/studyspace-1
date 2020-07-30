#include <Windows.h>
#include <stdio.h>

void test(int * p, int count) {
	for (int i = 0; i < count; i++) {
		p[i] += 1;
	}
}

void main() {
	int arr[6] = { 10, 20, 30, 40, 50, 60 };
	test(&arr[0], 6);

	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
}