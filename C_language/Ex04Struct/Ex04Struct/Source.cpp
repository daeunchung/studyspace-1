#include <Windows.h>
#include <stdio.h>

// # ����ü (��������� �ڷ��� : ���� �ڷ����� �����ؼ� �����.)
// 1) ���� ==> ������
//      [1] struct : Ű����
//      [2] User   : ����ü �̸�(�������� �ڷ����̶������ϸ�ȴ�)
//      [3] {};    : ���� (Ư���ϰ� ; ���� �������Ѵ�)
// 2) ����
//      [1] User user;  //  ��ġ  int a; �� ����ϴ�.
// 3) ��� 
//      [1] user.num = 1001;  // . ���� ���� ������ �����Ѵ�.

struct User {
	int num;
	int score;
};

void main() {

	// User user;
	User user = { 0 };
	user.num = 1001;
	user.score = 10;
	printf("�й� : %d, ���� : %d\n", user.num, user.score);

	User user2 = { 0 };
	user2.num = 1002;
	user2.score = 20;
	printf("�й� : %d, ���� : %d\n", user2.num, user2.score);

	system("pause");
}
