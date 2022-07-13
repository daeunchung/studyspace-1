#include <Windows.h>
#include <stdio.h>

void test(int **pp) {
	pp[0] = new int[3];
	/*	더블 포인터 pp값 : 단일포인터의 주소값
		pp[0] 값 : 단일포인터 속의 내용물 ( 단일포인터가 가리키는 주소 )

									(int a = 10; int* p = &a; int* pp = &p; 일때 a의 주소)	*/
}

void main() {
	int* p = new int[3];		// 배열의 주소를 포인터 p에 대입
	int* p1 = 0;
	int ** pp = &p1; 

	pp[0] = new int[3];			// 배열의 주소를 포인터 pp가 가리키는 주소
	pp[0][0] = 10;
	p1[0] = 200;
	printf("%d\n", pp[0][0]);

	// -------------------------------

	int* p2 = 0;
	test(&p2);
	delete[] p2;

	system("pause");
}