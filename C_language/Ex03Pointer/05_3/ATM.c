#include <Windows.h>
#include <stdio.h>

/*
# ATM[�Լ��� ����]
1. ȸ������
2. �α���				: �α��ΰ� ���ÿ� ���� �޴��� �̵��ϱ�
3. ����
------------------
1. �Ա�
2. ���
3. ��ü
4. Ż��					: �α׾ƿ��� �Բ� �ڷΰ���
5. �α׾ƿ�				: �α׾ƿ��� �Բ� �ڷΰ���
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
