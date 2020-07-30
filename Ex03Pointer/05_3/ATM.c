#include <Windows.h>
#include <stdio.h>

/*
# ATM[함수로 변경]
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

void print_info(int* accs, int* moneys, int count);
int check_acc(int* accs, int acc, int count);
int member(int* accs, int* moneys, int count);
int login_check(int* accs, int login, int count);
int income();
int check_acc(int* accs, int count);
void withdraw(int* accs, int* moneys, int login, int count);
void outcome(int* moneys, int login);
int del(int* accs, int* moneys, int login, int count);
int run(int* accs, int* moneys, int count);


void main() {

	int count = 3;
	int accs[5] = { 1111, 2222, 3333, 0, 0 };
	int moneys[5] = { 1000, 2000, 3000, 0, 0 };

	system("pause");

}
