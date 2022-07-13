#include <Windows.h>
#include <stdio.h>
void test(int** pp) {
	pp[0] = /*(int*) 인지 (int**) 인지*/malloc(sizeof(int) * 3);

	free(pp[0]);
}


void main() {
	//int* p = /*(int*) 인지 (int**) 인지*/malloc(sizeof(int) * 3);
	int* p1 = 0;
	int** pp = &p1;

	pp[0] = (int**)malloc(sizeof(int) * 3);
	pp[0][0] = 10;
	p1[0] = 200;
	printf("%d\n", pp[0][0]);

	free(pp[0]);
	system("pause");

	// -----------------------------------
	int* p2 = 0;
	test(&p2);
	
	system("pause");
	
}