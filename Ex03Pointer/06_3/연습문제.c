//#include <Windows.h>
//#include <stdio.h>
//
///*
//# 배열 기본문제[함수로 변경]
//문제 1) 전체 합 리턴
//정답 1) 150
//
//문제 2) 4의 배수만 배열에 저장해 리턴
//정답 2) 20 40
//
//문제 3) 4의 배수의 합 리턴
//정답 3) 60
//
//문제 4) (인덱스로)값 교체
//문제 5) (값으로)값 교체
//*/
//void print_arr(int* p, int count) {
//	printf("[ ");
//	for (int i = 0; i < count; i++) {
//		printf("%d ", p[i]);
//	}
//	printf("] \n");
//
//}
//
//int test1(int* p, int count) {
//	int total = 0;
//	for (int i = 0; i < count; i++) {
//		total += p[i];
//	}
//	return total;
//}
//
//int* test2(int* p, int count, int* p_size) {	//  int 형배열의 포인터를 반환하는 함수
//	int cnt = 0;
//	for (int i = 0; i < count; i++) {
//		if (p[i] % 4 == 0) {
//			cnt++;
//		}
//	}
//
//	p_size[0] = cnt;	//   int p_size 에다가 cnt 값을 넣어주는
//
//	int * tmp = new int[cnt];	// 동적할당 : 직전에 결정된 cnt 값만큼 heap 메모리에 int 방 파주기
//
//	int j = 0;
//	for (int i = 0; i < count; i++) {
//		if (p[i] % 4 == 0) {
//			tmp[j] = p[i];
//			j++;
//		}
//	}
//
//	return tmp;
//}
//int test3(int* p, int count) {
//	int total = 0;
//	for (int i = 0; i < count; i++) {
//		if (p[i] % 4 == 0) {
//			total += p[i];
//		}
//	}
//	return total;
//}
//
//void test4(int* p, int idx1, int idx2) {
//	int tmp = p[idx1];
//	p[idx1] = p[idx2];
//	p[idx2] = tmp;
//}
//
//void test5(int* p, int count, int value1, int value2) {
//	int idx1 = 0;
//	int idx2 = 0;
//	for (int i = 0; i < count; i++) {
//		if (p[i] == value1) { idx1 = i; }
//		if (p[i] == value2) { idx2 = i; }
//	}
//	int tmp = p[idx1];
//	p[idx1] = p[idx2];
//	p[idx2] = tmp;
//
//}
//
//void main() {
//
//	int count = 5;
//	int arr[5] = { 10, 20, 30, 40, 50 };
//
//	printf(">>>문제 1\n");
//	int tot = test1(&arr[0], count);
//	printf("tot = %d\n", tot);
//	printf("\n");
//
//	printf(">>>문제 2\n");
//	int p_size = 0;
//	int* p = test2(&arr[0], count, &p_size);
//	print_arr(p, p_size);
//	printf("\n");
//
//	printf(">>>문제 3\n");
//	tot = test3(&arr[0], count);
//	printf("tot = %d\n", tot);
//	printf("\n");
//
//	printf(">>>문제 4\n");
//	test4(&arr[0], 0, 4);
//	print_arr(&arr[0], count);
//	printf("\n");
//
//	printf(">>>문제 5\n");
//	test5(&arr[0], count, 20, 40);
//	print_arr(&arr[0], count);
//	printf("\n");
//
//	system("pause");
//}
