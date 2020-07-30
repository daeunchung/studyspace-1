#include <Windows.h>
#include <stdio.h>


/*
# ATM[구조체(변수) 변경]
1. 회원가입
2. 로그인				: 로그인과 동시에 하위 메뉴로 이동하기
3. 종료
------------------
1. 입금
2. 출금
3. 이체
4. 탈퇴					: 로그아웃과 함께 뒤로가기
5. 로그아웃				: 로그아웃과 함께 뒤로가기

*/

struct Client {
	int accs;
	int moneys;
};

struct ATM {
	int count;
	int login;
	Client* c;
};

void main() {

	ATM atm = { 0 };
	atm.count = 3;
	atm.login = -1;
	atm.c = new Client[atm.count];

	atm.c[0].accs = 1111;	atm.c[0].moneys = 1000;
	atm.c[1].accs = 2222;	atm.c[1].moneys = 2000;
	atm.c[2].accs = 3333;	atm.c[2].moneys = 3000;

	while (1) {
		printf("1.로그인\n");
		printf("2.로그아웃\n");
		printf("3.이체하기\n");
		printf("4.회원가입\n");
		printf("5.탈퇴하기\n");
		printf("6.종료하기\n");
	}

	system("pause");

}
