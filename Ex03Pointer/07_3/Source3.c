//#include <Windows.h>
//#include <stdio.h>
//
//void test(int** pp) {
//	pp[0] = new int[3];
//}
//
//void main() {
//
//	int* p = new int[3];
//
//	int* p1 = 0;
//	int** pp = &p1;
//
//	pp[0] = new int[3];
//	pp[0][0] = 10;
//	p1[0] = 200;
//	printf("%d\n", pp[0][0]);
//
//	//--------------------------
//
//	int* p2 = 0;
//	test(&p2);
//
//	delete[] p2;
//
//	system("pause");
//}

#include <Windows.h>
#include <stdio.h>

int* dma1() {
	//int* p = new int[2];
	int* p = (int*)malloc(sizeof(int) * 2);
	return p;
}

void dma2(int** pp) {
	//pp[0] = new int[2];
	pp[0] = /*(int*)인지(int**)인지*/malloc(sizeof(int) * 2);
	free(pp[0]);
}

void main() {
	int* p = dma1();
	free(p);

	dma2(&p);

	system("pause");
}