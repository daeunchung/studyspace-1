#include <Windows.h>
#include <stdio.h>

void main() {

	//	개념 1
	//int arr[5] = { 1, 2, 3, 4, 5 };

	//int* p = &arr[0];

	//for (int i = 0; i < 5; i++) {
	//	printf("%d ", *(p + i));
	//	// *(p + 0) = p[0]
	//	// *(p + 1) = p[1] 
	//	// *(p + 2) = p[2] 
	//	// *(p + 3) = p[3] 
	//	// *(p + 4) = p[4] 
	//}

	//system("pause");

	int a = 10;
	printf("a = %d\n", a);

	int *p = &a;
	printf("a = %d\n", p[0]);
	printf("a = %d\n", *(p + 0));

	int** pp = &p;		// 단일 포인터의 주소를 넣어준 더블 포인터
	printf("a = %d\n", pp[0][0]);
	printf("a = %d\n", *(*(pp + 0) + 0));
	printf("a = %d\n", *(pp[0] + 0));


	printf("a의 주소 = %d\n", &a);
	printf("a의 주소 = %d\n", p);
	printf("a의 주소 = %d\n", pp[0]);
	printf("a의 주소 = %d\n", *pp);

	printf("p의 주소 = %d\n", &p);
	printf("p의 주소 = %d\n", pp);

	system("pause");
}