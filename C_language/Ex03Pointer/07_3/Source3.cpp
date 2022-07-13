#include <Windows.h>
#include <stdio.h>

int* dma1() {
	int* p = new int[2];
	return p;
}

void dma2(int** pp) {
	pp[0] = new int[2];
}

void main() {
	int* p = dma1();
	delete[] p;

	dma2(&p);
	delete[] p;

	system("pause");
}
