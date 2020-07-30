#include <Windows.h>
#include <stdio.h>

void main() {
	// 1001 // 70, 60
	// 1002 // 50, 30, 20
	// 1003 // 30
	// 1004 // 만개

	int arr[4][10000] = { 0 };

	int** pp = 0;
	int count = 4;

	pp = (int**)malloc(sizeof(int*)*count);
	// 이중 포인터에 (int 포인터 크기 * 세로 크기)만큼
    // 동적 메모리 할당. 배열의 세로

	pp[0] = (int*)malloc(sizeof(int)*2);
	pp[0][0] = 70;
	pp[0][1] = 60;


	pp[1] = (int*)malloc(sizeof(int) * 3);
	pp[1][0] = 50;
	pp[1][1] = 30;
	pp[1][2] = 20;

	pp[2] = (int*)malloc(sizeof(int) * 1);
	pp[2][0] = 30;

	pp[3] = (int*)malloc(sizeof(int) * 10001);
	system("pause");
	// 포인터 그림 모두 그렸음



}