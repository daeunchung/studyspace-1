#include <Windows.h>// system
#include <stdio.h>	// printf, scanf_s
#include <stdlib.h>	// rand
#include <time.h>	// time

void main() {

/*
	// atm [문제]
	// 1.입금 2.출금 
	int cash = 8000;
	int atm = 5000;
	printf("==== ATM ===="); printf("\n");
	printf("1.입금 2.출금"); printf("\n");
	int select;
	scanf_s("%d", &select);
	if (select == 1) {
		printf("입금할 금액을 입력하세요 "); printf("\n");
		int money;
		scanf_s("%d", &money);
		if (money <= cash) {
			cash = cash - money;
			atm = atm + money;
		}
		if (money > cash) {
			printf("금액을 다시입력하세요 "); printf("\n");
		}
	}
	printf("%d %d", cash, atm); printf("\n");

	system("pause");

//		time 함수 : time.h 헤더파일에 존재
//		1970년 1월 1일 0시 (UTC) 부터 현재까지 흐른 시간을 초단위로 반환합니다.

//		srand 함수 : stdlib.h 헤더파일에 존재
//		seed 값에 따라 rand의 값이 바뀐다. ( seed 는 양의 정수만 가능 )

//		rand 함수 = srand(1) 같은 효과	

//rand() 그냥 이렇게 써놓고 출력하려고 하면 0부터 stdlib.h 파일에서 지정되있는 0x7fff까지의 범위를 가진 난수를 출력한다.
//0x7fff는 32767이니까 0~32767의 범위 사이에서 난수가 생성된다는 말이다.
//자신이 원하는 범위에서 난수를 뽑아내려면 rand()%n 이런 식으로 뒤에 뭔가를 더 써줘야 한다.
//rand()%n은 0~n-1 범위를 가진다. 조금 더 다양한 범위를 정해주고 싶다면
//A + (rand() % B) + C -> A+C ~ (A+B+C)-1 의 범위
//이런 식으로 쓸 수도 있다. 이렇게 쓰다보면 이상한 점을 발견할 수 있다. 난수가 항상 같은 값이 나온다는 점이다.
//이게 무슨소리냐면 예를 들어 5개의 난수를 뽑으려는데 1 2 3 4 5가 나왔다고 하자. 실행시킨 걸 껐다가 다시 키면 또 똑같이 1 2 3 4 5가 나온다.
//난 분명 랜덤으로 수를 뽑아내는 걸 원해서 랜덤 함수라는 rand 함수를 찾아서 썼는데 이 랜덤이 주어진 범위 사이에서 랜덤의 숫자를 뽑아낼 뿐, 항상 그 값이 같다는 것이다.
//항상 같지 않은, 매번 다른 난수를 발생시키기 위해서는 시드 값을 주는 방법이 있는데 여기서 srand 함수가 쓰인다.
//그리고 srand()의 인자로 time()으로 반환되는 값을 준다. time 함수를 쓰려면 time.h 파일을 추가시켜줘야 한다.
//보통 srand(time(NULL)), 혹은 srand(time(0))을 쓴다. (NULL == 0)
//time(NULL)은 1970년 1월 1일 이후의 경과된 시간을 초 단위로 반환하는 함수이다.

	srand(time(0));	// 랜덤함수의 기준변경
	//	1~4만정도 사이의 숫자가 나온다.

	int a = 10;
	printf("%d", a); printf("\n");

	int b = rand();
	printf("%d", b); printf("\n");

	int c = rand();
	printf("%d", c); printf("\n");

	// 0 ~ 4
	int d = rand() % 5;		// 0, 1, 2, 3, 4
	printf("%d", d); printf("\n");

	//	3 ~ 7
	int e = rand() % 5 + 3;	// 0 ~ 4 ==> 3 ~ 7
	printf("%d", e); printf("\n");

	// -4 ~ 3
	int f = rand() % 8 - 4;
	printf("%d", f); printf("\n");

	system("pause");



	//	구구단 [문제]	srand(time(0));
	//rand();
	// 구구단 문제 랜덤 출제후 정답입력후 결과출력 
	
	int a = rand() % 8 + 2;  // 2단 ~ 9단
	int b = rand() % 9 + 1;  // 1~9

	printf("%d * %d = ?", a, b);
	int c;
	scanf_s("%d", &c);
	if (c == a * b) {
		printf("정답");
	}
	else {
		printf("오답");
	}

	system("pause");

	// if 문 옵션 2가지 (단독사용불가능)
	// 1) else  ==> if 의 조건 빼고 전부다 

	void main() {
		int score = 60;
		if (score >= 60 && score <= 100) {
			printf("합격");
		}
		else {
			printf("불합격");
		}
		printf("\n");
		printf("\n");

		printf("====== atm ======="); printf("\n");
		printf("1. 입금 2. 출금 3.종료"); printf("\n");
		int select;
		scanf_s("%d", &select);
		if (select == 1) {
			printf("입금");
		}
		if (select == 2) {
			printf("출금");
		}
		if (select == 3) {
			printf("종료");
		}
		else {
			printf("오류");
		}

		system("pause");


		// if 의 옵션 2가지
		// 1) else
		// 2) elseif ==> if 의 조건을 여러개 필요할때 사용 
		//				 위에서부터 순차적으로 조건을 검사해서 참이나오면 나머지는 무시
		//				결과는 언제나 1개만 나온다.
		printf("====== atm ======="); printf("\n");
		printf("1. 입금 2. 출금 3.종료"); printf("\n");
		int select;
		scanf_s("%d", &select);
		if (select == 1) {
			printf("입금");
		}
		else if (select == 2) {
			printf("출금");
		}
		else if (select == 3) {
			printf("종료");
		}
		else {
			printf("오류");
		}
		system("pause");

*/
	
srand(time(0));
//문1) 가위 바위 보 // 1명 직접 1명은 랜덤
int me;
printf("1.가위 , 2.바위 , 3.보"); printf("\n");
scanf_s("%d", &me);
int com = rand() % 3 + 1;
int 가위 = 1; int 바위 = 2; int 보 = 3;

if (com == 가위 && me == 가위) {
	printf("비겼다");
}
if (com == 바위 && me == 바위) {
	printf("비겼다");
}
if (com == 보 && me == 보) {
	printf("비겼다");
}
if (com == 가위 && me == 바위) {
	printf("내가 이겼다");
}
if (com == 보 && me == 가위) {
	printf("내가 이겼다");
}
if (com == 바위 && me == 보) {
	printf("내가 이겼다");
}
if (com == 가위 && me == 보) {
	printf("내가 졌다");
}
if (com == 보 && me == 바위) {
	printf("내가 졌다");
}
if (com == 바위 && me == 가위) {
	printf("내가 졌다");
}




// 동전게임 // 동전 1~10개중 랜덤저장후 1)홀  2)짝
int coin = rand() % 10 + 1;
printf("\n");
printf("============동전게임============"); printf("\n");
printf("치트키 : %d", coin);
printf("\n");
printf("1)홀 2)짝"); printf("\n");
int sel; scanf_s("%d", &sel);
if (sel == 1 && coin % 2 == 1) {
	printf("정답");
}
else if (sel == 2 && coin % 2 == 0) {
	printf("정답");
}
else {
	printf("꽝");
}
printf("\n");





// 복권 // 1)긁기 2)종료 
// 긁기 ==> 30퍼센트확률로 당첨 
printf("===========복권========="); printf("\n");
printf("1.긁기 2.종료"); printf("\n");
sel; scanf_s("%d", &sel);
int lotto = rand() % 10;
printf("치트키 : %d", lotto); printf("\n");
if (sel == 1) {
	if (lotto >= 3) {
		printf("꽝"); printf("\n");
	}
	else {
		printf("당첨"); printf("\n");
	}
}
system("pause");

}