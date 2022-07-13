//malloc함수와 calloc함수의 차이점!
//malloc은 할당된 공간의 값을은 바꾸지 않는다.
//calloc은 할당된 공간의 값을 모두 0으로 바꾼다.
//배열을 할당하고 모두 0으로 초기화할 필요가 있을경우에는 calloc을 쓰면 편하다.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr_1[5];	// 배열 선언
	int* arr_2;		// 포인터 변수 선언

	int i; for (i = 0; i < 5; i++) {
		arr_1[i] = i + 1;	// 배열에 값 대입
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);
	// 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함

	arr_2 = (int*)calloc(5, sizeof(int));
	// sizeof(int)크기의 변수를 5개 저장할 수 있는 공간할당

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];	printf("%d", arr_2[i]);
	}
	free(arr_2);	// free함수를 이용하여 메모리 해제
	return 0;
}
