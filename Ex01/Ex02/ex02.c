#include <Windows.h>
#include <stdio.h>
// 한 프로젝트에 main 함수는 하나여만 한다.

/*
# 변수 (variable) : 데이터를 저장하는 공간
	1) 선언
	.	int a ;
	.	메모리 공간할당
	2) 사용
	.	a = 10;
	.	메모리에 값 저장

*/
void main() {

	//  정수(int ) : 4byte
	int a;
	a = 10; // 10을 a에 저장해라
	printf("%d", a);	printf("\n");

	// 실수(float) : 4byte
	float b;							// 선언(메모리 공간할당)
	b = 10.0;							// 메모리에 값 저장
	printf("%f", b);	printf("\n");

	// 문자(char) : 1byte
	char c;
	c = 'a';
	printf("%c", c);	printf("\n");


	/*
		# 변수의 특징
		1) 변수는 한 가지 값만 저장할 수 있다. (새로운 값이 저장되면 기존 값 삭제)
		2) 변수 선언은 한가지 이름으로만 사용할 수 있다. (중복선언불가)
		3) 예약어를 변수 이름으로 사용할 수 없다. (파란글씨는 예약어)
		4) 숫자를 이름으로 시작할 수 없다. 7a(x), a7(o)
		5) 대소문자를 구분한다.
		6) 변수이름으로 특수문자 $와 _ 두 개 사용가능
	*/

	int aa;
	aa = 10; aa = -1; aa = 0; aa = 13; aa = 3;
	printf("%d", aa);	printf("\n");
	
	int A;
	// 예) 문제1) 사각형의 넓이
	float garo;
	garo = 7;

	float sero;
	sero = 3;

	float rect;
	rect = garo * sero;
	printf("가로 %.2f, 세로 %.2f, 사각형 넓이 : %.2f", garo, sero, rect); 
	printf("\n");

	// 문제2) 시험점수를 20, 43, 71점을 받았다. 총점 평균 출력. 
	float score1; float score2; float score3; float total; float avg;
	score1 = 20;
	score2 = 43;
	score3 = 71;
	total = score1 + score1 + score3;
	avg = total / 3;
	printf("총점 : %.f, 평균 : %.2f", total, avg);
	printf("\n");

	// 문제3) 186800원을 화폐매수로 출력 
	// 정답3) 5만원(3장) 1만원(3장) 5천원(1장) 5백원(1개) 1백원(3개)
	int money = 186800;
	printf("5만원: %d장, 1만원: %d장, 5천원: %d장, 1천원: %d장, 5백원: %d개, 1백원: %d개",
		money / 50000, money % 50000 / 10000, money % 50000 % 10000 / 5000, money % 50000 % 10000 % 5000 / 1000,
		money % 50000 % 10000 % 5000 % 1000 / 500, money % 50000 % 10000 % 5000 % 1000 % 500 / 100);
	printf("\n");

	int n1 = money / 50000;
	int n2 = (money % 50000) / 10000;
	int n3 = (money % 10000) / 5000;
	int n4 = (money % 5000) / 1000;
	int n5 = (money % 1000) / 500;
	int n6 = (money % 500) / 100;

	printf("5만원 = %d장\n", n1);
	printf("1만원 = %d장\n", n2);
	printf("5천원 = %d장\n", n3);
	printf("1천원 = %d장\n", n4);
	printf("5백원 = %d개\n", n5);
	printf("1백원 = %d개\n", n6);

	// 문제4) x와 y의 값 교환.
	int x;
	int y;

	int z; //힌트

	x = 10;
	y = 20;

	z = x;
	x = y;
	y = z;
	printf("x : %d, y : %d", x, y);
	printf("\n");

	// 문제5) 월급이 100원이다. 연봉출력(조건 : 세금 10%제외)
	float salary;
	salary = 100;

	float profit;
	profit = salary * 12 * 0.9;
	printf("월급 : %.f원, 연봉 : %.f원", salary, profit);
	printf("\n");

	system("pause");
}