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


// ����ü ���1
struct User {
	int num;
	int score;
};

// ����ü ���2
typedef struct _User1 {
	int num;
	int score;
}User1;

// �͸� ����ü�� ����ü ��Ī ��!��!��!
typedef struct {
	char name[20];
	int age;
	char address[100];
}Person;

void main() {

	struct User user;
	user.num = 1001;
	user.score = 10;
	printf("�й� : %d, ���� : %d\n", user.num, user.score);

	User1 user2;
	user2.num = 1002;
	user2.score = 20;
	printf("�й� : %d, ���� : %d\n", user2.num, user2.score);

	Person p1;			// �͸� ����ü�� ����ü ��Ī���� ���� ����
	strcpy(p1.name, "ȫ�浿");
	p1.age = 30;
	strcpy(p1.address, "����� ��걸 �ѳ���");
	printf("�̸�: %s\n", p1.name);    
	printf("����: %d\n", p1.age);       
	printf("�ּ�: %s\n", p1.address);

	system("pause");
}

/*
�Ҵ�� ����ü �޸𸮿� �������ϱ�

1. ����ü�� ���ؼ� 
struct Point2D p1;
memset(&p1, 0, sizeof(struct Point2D));    // p1�� ����ü ũ�⸸ŭ 0���� ����

==> p1.�ɹ�����1 = 0;
	p1.�ɹ�����2 = 0;
			...
	p1.�ɹ�����last = 0; �� ���� ����


2. ����ü �����͸� ���ؼ� �� �����ϱ�
struct Point2D *p1 = malloc(sizeof(struct Point2D));    // ����ü ũ�⸸ŭ �޸� �Ҵ�
memset(p1, 0, sizeof(struct Point2D));    // p1�� ����ü ũ�⸸ŭ 0���� ����

==> p1->�ɹ�����1 = 0;
	p1->�ɹ�����2 = 0;
			...
	p1->�ɹ�����last = 0;

	free(p1);								// �����Ҵ�� �ʼ����� ~

*/