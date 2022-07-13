#include <Windows.h>
#include <stdio.h>
// 반복문 
// 1) while ==> 키워드 (파란색글씨)
// 2) (1)   ==> 조건의 결과가 1이면 실행 0이면 무시
// 3) {}    ==> 실행문 
//	특징 ==> 실행문이 종료후 다시 while 로 이동한다
//	주의 ==> 반드시 종료조건 (끝내기) 를 만들어야한다.

void main() {
	if (0) {
		printf("!!");
	}
	while (0) {
		printf("반복");
	}

	//	5번 반복
	int n = 0;
	while (n < 5){
		printf("%d", n); printf("\n");
		n = n + 1;

	}
	system("pause");

	// 1~5 까지 전체합 1 + 2 + 3 + 4 + 5
	 n = 1;
	int total = 0;
	while (n < 6) {
		total = total + n;
		n = n + 1;
	}
	printf("합 : %d", total); printf("\n");

	// 문제1) 1~5중에서 홀수의 합 출력 1 + 3 + 5
	 n = 1;
	 total = 0;
	while (n < 6) {
		if (n % 2 == 1) {
			total = total + n;
		}
		n = n + 1;
	}
	printf("홀수의 합 : %d", total); printf("\n");

	// 문제2) 1~5중에서 홀수의 갯수 출력 ==> 3
	 n = 1;
	int cnt = 0;
	while (n < 6) {
		if (n % 2 == 1) {
			cnt++;
		}
		n = n + 1;
	}
	printf("홀수의 갯수 : %d", cnt); printf("\n");

	system("pause");


	//  ----------------------------------------------영 수 증 문 제 ----------------------------------------------
	//문제1) 주문을 5번하고 영수증출력
	//예) 햄버거 2개 400원 콜라 1개 300원 .... 거스름돈 ... 원

	int money = 10000;
	int k = 0;
	int c1 = 0; int c2 = 0; int c3 = 0;
	while (k < 5) {
		printf("======= 롯데리아 ========"); printf("\n");
		printf("1.햄버거 200원 "); printf("\n");
		printf("2.콜라 300원 "); printf("\n");
		printf("3.감자 400원 "); printf("\n");
		printf("번호를 입력하세요 ");
		int sel; scanf_s("%d", &sel);
		if (sel == 1) {
			c1++;
			money -= 200;
		}
		else if (sel == 2) {
			c2++;
			money -= 300;

		}
		else if (sel == 3) {
			c3++;
			money -= 400;
		}
		k++;
	}
	printf("햄버거 %d개 ,  콜라 %d개 ,  감자 %d개 , 거스름돈 :  %d원", c1, c2, c3, money);
	printf("\n");

	system("pause");


	// ------------------------------------------  문제1) 소수찾기 
	// 소수 ==> 1과 자신으로만 나눠지는 1보다큰수 
	// 2 , 3 , 5 , 7 , 11 , 13 ....
	// 숫자를 입력받고 "소수다" "소수가아니다" 출력 
	// 찾는방법 1부터 입력받은 숫자까지 1씩증가하면서 나눈다.
	// 나머지가0이면 나눠진거다. 
	// 나눠질때마다 카운트를 센다.
	// 카운트가 2면 소수 
	// 초과하면 소수가아니다. 
	// 3/1 , 3/2 , 3/3 ==> (2) ==> 소수
	// 4/1 , 4/2 , 4/3 , 4/4 ==> (3) ==> 소수가아니다.
	// 4/0 ==>에러
	
	int j= 1;
	int count = 0;
	int num;
	scanf_s("%d", &num);
	while (j <= num) {
		if (num % j == 0) {
			count++;
		}
		j++;
	}

	if (count == 2) {
		printf("소수입니다");
	}
	else
	{
		printf("소수가 아닙니다");
	}

	system("pause");

	// ------------------------------------------- 쇼핑몰 문제 pass
}

