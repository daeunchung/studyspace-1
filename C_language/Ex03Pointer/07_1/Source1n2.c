#include <Windows.h>
#include <stdio.h>

void main() {

	//	���� 1
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

	int** pp = &p;		// ���� �������� �ּҸ� �־��� ���� ������
	printf("a = %d\n", pp[0][0]);
	printf("a = %d\n", *(*(pp + 0) + 0));
	printf("a = %d\n", *(pp[0] + 0));


	printf("a�� �ּ� = %d\n", &a);
	printf("a�� �ּ� = %d\n", p);
	printf("a�� �ּ� = %d\n", pp[0]);
	printf("a�� �ּ� = %d\n", *pp);

	printf("p�� �ּ� = %d\n", &p);
	printf("p�� �ּ� = %d\n", pp);

	system("pause");
}