#include <Windows.h>
#include <stdio.h>

// # 포인터 == > 주소를 저장하는 변수
// 1) 선언 : int* p;
// 2) 사용 : p = &a;
// 3) 설명 : 포인터변수는 일반변수의 주소를 저장한다.
// 4) 주소 출력하는 법 : 변수 앞에 &를 붙이면 주소가 출력된다.

/*
void main() {
	int a = 0;			// 4byte
	double f = 0;		// 8byte
	char c = 0;			// 1byte
	printf("sizeof ==> %d ", sizeof(c));
	printf("\n");

	// & 앰퍼샌드
	printf("a의 주소 : %d", &a); printf("\n");

	int* p;
	char* pc;
	double* pf;
	p = &a;
	printf("p의 값 : %d", p); printf("\n");
	system("pause");

	printf("%d\n", a);
	printf("%d\n", &a);
	printf("%d\n", p);
	printf("%d\n", &p);

	p[0] = 200;
}

*/



// 함수 
// 1) 정의
//     1. void   ==> 키워드 
//     2. test() ==> 이름
//     3. {}     ==> 실행영역 
// 2) 사용
//     test();   ==> 함수실행 

// # 함수의 종류 (4종류)
void test() {
	printf("여기는 test"); printf("\n");
}

void test1() {
	printf("!!");
	printf("\n");
}
void test2(int a, int b) {
	printf("%d %d", a, b); printf("\n");
}

int test3() {
	int a = 10;
	return a;
}

int test4(int a, int b) {
	int c = a + b;
	return c;
}


void odd_even(int num) {
	if (num % 2 == 1) {
		printf("홀수\n");
	}
	else {
		printf("짝수\n");
	}
}

void swap(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void pswap(int* p1, int* p2) {
	int temp = p1[0];
	p1[0] = p2[0];
	p2[0] = temp;
	// int 값으로 바꿔주기

	// int temp = *p1;
	// *p1 = *p2;
	// *p2 = temp;
}

void main() {
	int a = 10;
	test();
	test();
	test();
	system("pause");

	test1();
	test2(10, 20);
	int c = test3();
	printf("test3 ==> %d", c);	printf("\n");
	printf("test4 ==> %d", test4(5, 6));	printf("\n");

	// =========> 질문 ! 왜 함수 표현식인 test4(5, 6); 이 printf() 함수 안에 들어가는게 아니고
	//					test4(5, 6) 을 부르는걸까?

	// C 언어는 함수를 정의해주는 (선언해주는) 부분이 main 함수보다 앞에 있어야만
	// main 에서 함수를 불러와 사용할 수 있다.
	// 함수 선언부가 실행부(;) 보다 뒤에 있으면 undefined 로 에러가 뜬다

	// # 홀수 또는 짝수를 출력해주는 함수
	odd_even(10);
	odd_even(1);
	odd_even(15);

	// # a 와 b 의 값을 교환하는 함수 (함수의 한계)
	int a = 10;
	int b = 20;
	printf("%d %d", a, b);	printf("\n");
	swap(a, b);
	printf("%d %d", a, b);	printf("\n");
	pswap(&a, &b);
	printf("%d %d", a, b);	printf("\n");


	system("pause");
}
// main();

