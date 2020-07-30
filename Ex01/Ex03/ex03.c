#include <Windows.h>
#include <stdio.h>

/*
	# 입력받기
	.	scanf_s(1, 2);
	.	1번(data type) : %d %f %s %c 등등을 사용할 수 있다.
	.	2번(저장할 변수) : [주의] 변수 앞에 &(앤퍼샌드)을 붙여줘야한다.
*/
void main() {

	printf("시작\n"); printf("\n");
	int a1;
	scanf_s("%d", &a1);	// 숫자를 입력하고 엔터를 누를때까지 대기한다.
	printf("종료\n"); printf("\n");

	printf("%d", a1); printf("\n");




	//	# 입력받기 [문제]
	// 문제1) 숫자 1개를 입력받고 연봉출력 (세금10%제외)
	float salary;
	printf("문제1) 월급을 입력하시오"); printf("\n");
	scanf_s("%f", &salary);
	printf("월급: %.f원, 연봉: %.f원", salary, salary * 12 * 0.9);
	printf("\n");

	// 문제2) 숫자 2개를 입력받고 삼각형 넓이출력 
	float num1;
	float num2;
	printf("문제2) 삼각형의 밑변, 높이 길이를 입력하시오"); printf("\n");
	scanf_s("%f %f", &num1, &num2);
	printf("삼각형의 넓이: %.2f", num1 * num2 / 2);
	printf("\n");

	// 문제3) 숫자 2개를 입력받고 서로 교환 
	int num3;
	int num4;
	printf("문제3) 숫자 2개를 입력하시오"); printf("\n");
	scanf_s("%d %d", &num3, &num4);
	int t;

	t = num3;
	num3 = num4;
	num4 = t;
	printf("num3 : %d, num4 : %d", num3, num4);
	printf("\n");
	system("pause");


	// 1. 출력 , 변수 , 입력 
	// 2. 연산자 (operator) 중요연산자 4종류 
	//    1) 산술연산자 ==> + - * / %
	//    2) 대입연산자 ==> int a;  a = 10;
	//                 ==> 오른쪽의 값을 왼쪽으로 저장(복사)한다.

	//    3) 비교연산자 ==> 6개 ==> 결과가 1(참)  0(거짓) 둘중하나로 출력된다.
	//           1.  왼쪽이 크다			a > b
	//           2.  왼쪽이 작다			a < b
	//           3.  서로 같다			a == b
	//           4.  서로 다르다			a != b 
	//           5.  왼쪽이 크거나 같다  a >= b
	//           6.  왼쪽이 작거나 같다  a <= b

	int b2 = 10;	// 축약형, 선언과 저장을 한번에 한다.
	int a2 = b2;
	//	printf("b2 : %d", b2);	printf("\n");
	printf("a2 : %d", a2);		printf("\n");

	// 비교연산자
	printf("%d", 10 == 10); printf("\n");
	printf("%d", 10 != 10); printf("\n");
	printf("%d", 10 > 10); printf("\n");
	printf("%d", 10 < 10); printf("\n");
	printf("%d", 10 >= 10); printf("\n");
	printf("%d", 10 <= 10); printf("\n");


	// 비교연산자 [문제]
	//문제1) 전부 1이나오도록 숫자를 변경해보세요 
	printf("%d", 10 == 10); printf("\n");
	printf("%d", 11 != 10); printf("\n");
	printf("%d", 11 > 10); printf("\n");
	printf("%d", 10 < 11); printf("\n");
	printf("%d", 10 >= 10); printf("\n");
	printf("%d", 10 <= 10); printf("\n");

	//문제2) 전부 0 이나오도록 a나  b를 변경해보세요 
	int a = 10;
	int b = 10;
	printf("================================="); printf("\n");
	a = 1;
	printf("%d", a == b); printf("\n");
	a = 10;
	printf("%d", a != b); printf("\n");
	printf("%d", a > b); printf("\n");
	printf("%d", a < b); printf("\n");
	a = 9;
	printf("%d", a >= b); printf("\n");
	b = 8;
	printf("%d", a <= b); printf("\n");

	system("pause");

	//	종합 [문제]

	//문1) 숫자 1개를 입력받고 60이상이면 1출력 
	int d;
	printf("문제1) 숫자 1개 입력하시오");		printf("\n");
	scanf_s("%d", &d);
	printf("%d", d >= 60);					printf("\n");

	//문2)  초를 입력받고 시간 분 초 출력  5321 ==> 
	int e;
	printf("문제2) 초를 입력하시오");			printf("\n");
	scanf_s("%d", &e);
	printf("%d분 %d초", e / 60, e % 60);		printf("\n");

	//문3) 숫자 2개를 입력받고 두번째 숫자가 크면 1출력 
	int f; int g;
	printf("문제3) 숫자 2개를 입력하시오");	printf("\n");
	scanf_s("%d %d", &f, &g);
	printf("%d", f < g);					printf("\n");

	// 문4) 숫자를 입력받고 짝수면 1출력 
	// 짝수 ==> 2의 배수 
	// 2의 배수 ==> 어떤수든 2로 나눠서 나머지가 0이면 2의 배수이다. 
	int h;
	printf("문제4) 숫자 1개를 입력하시오");	printf("\n");
	scanf_s("%d", &h);
	printf("%d", h % 2 == 0);				printf("\n");
	system("pause");


	// 4번연산자 ==> 논리연산자 ==> and , or , not  ==> 결과가 1 , 0 으로 나온다.
	// 1) and  ==>  a == b && c == d  ==> 1번도 참이고 2번도 참이면 참 
	// 2) or   ==>  a == b || c == d  
	// 3) not  ==> !a  

	printf("%d", 10 == 10 && 9 == 9); printf("\n");
	printf("%d", 10 != 10 && 9 == 9); printf("\n");
	printf("%d", 10 == 10 && 9 != 9); printf("\n");
	printf("%d", 10 != 10 && 9 != 9); printf("\n");
	printf("======================================"); printf("\n");

	printf("%d", 10 == 10 || 9 == 9); printf("\n");
	printf("%d", 10 != 10 || 9 == 9); printf("\n");
	printf("%d", 10 == 10 || 9 != 9); printf("\n");
	printf("%d", 10 != 10 || 9 != 9); printf("\n");

	printf("======================================"); printf("\n");
	printf("not ==> ! ==>  %d", !(10 == 10)); printf("\n");

	system("pause");

	//문제1) 점수가 60~100이면 1 출력 
	int a0 = 80;
	int b0 = 120;
	printf("%d", 60 <= a0 && a0 <= 100);	printf("\n");
	printf("%d", 60 <= b0 && b0 <= 100);	printf("\n");

	//문제2) 점수가 1~59면 1출력 
	int c0 = 40;
	printf("%d", 0 < c0 && c0 < 60);		printf("\n");

	//문제3) 숫자가 3의 배수이면서 4의 배수이면 1출력 
	int d0 = 9;
	printf("%d", (d0 % 3 == 0) && (d0 % 4 == 0));	printf("\n");

	//문제4) 점수 2개를 입력받고 평균이 60이상이면 1출력 
	// (조건 : 과락 ==> 평균이 60이상일지라도 한과목이라도 50이하가 있으면 과락)
	//  100 , 50 ==> 150 ==> 0
	//  60  , 60 ==> 120 ==> 1
	int n1; int n2;
	int tot; float average;
	printf("두 점수를 입력하시오");		printf("\n");

	scanf_s("%d", &n1);
	scanf_s("%d", &n2);
	tot = n1 + n2;
	average = tot / 2;

	printf("%d", average >= 60 && n1 > 50 && n2 > 50);		printf("\n");

	//문제5) 장학생 ==> 국어점수가 만점이거나 수학점수가 만점이면 장학생 (1)
	// 100 , 0   ==> 1
	// 99  , 99  ==> 0

	int s1; int s2;
	printf("두 점수를 입력하시오");		printf("\n");
	scanf_s("%d", &s1);
	scanf_s("%d", &s2);

	printf("%d", s1 == 100 || s2 == 100);		printf("\n");

	system("pause");

}