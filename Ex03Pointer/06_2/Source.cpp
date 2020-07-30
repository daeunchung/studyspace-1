#include <Windows.h>
#include <stdio.h>

void main() {

	// # 배열의 개수는 상수로 할당
	int arr[3];		// 상수 ==> 3
	new int[3];

	// # 동적할당
	int a = 3;
	int* p = new int[a];
	// 동적할당 문법 같은거라고 생각하면됌 
	// 그 과정에서 new 써주고 heap 메모리 사용하는것

	printf("배열의 크기를 입력하세요 : ");
	int size = 0;
	scanf_s("%d", &size);

	//	int test[size];		// 에 러 발 생
	int* tp = new int[size];

}