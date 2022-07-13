//#include <Windows.h>
//#include <stdio.h>
//#include <time.h>
////	Recursion version 재귀
//
//int Fact(int n) {
//	if (n == 0 || n == 1) {
//		return 1;
//	}
//	else {
//		return Fact(n - 1) * n;
//	}
//}
//
//void main() {
//	time_t start, end;
//	double result;
//	int fact = 0;
//
//	start = time(NULL);
//	fact = Fact(10);
//	end = time(NULL);
//
//	result = (double)(end - start);
//	printf("run time : %f s\n", result);
//
//	system("pause");
//}
//
//
//
///*
//1. 
//time(NULL) 함수를 이용하여 받아옵니다.
//단점은 ms단위가 아닌 초(s) 단위로 측정이 됩니다.
//#include <time.h> 헤더파일을 포함시키고 아래와 같이 사용하시면 됩니다.
//
//2.
//clock 함수를 이용하여 앞에 방법의 단점을 해결하여 ms 단위로 시간을 측정 할 수 있습니다.
//time 함수와 마찬가지로 include <time.h> 헤더 파일을 포함 시켜야 합니다.
//*/