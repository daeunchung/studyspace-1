#include <Windows.h>
#include <stdio.h>

// # 구조체 (사용자정의 자료형 : 기존 자료형을 조합해서 만든다.)
// 1) 정의 ==> 디자인
//      [1] struct : 키워드
//      [2] User   : 구조체 이름(내가만든 자료형이라고생각하면된다)
//      [3] {};    : 내용 (특이하게 ; 으로 마무리한다)
// 2) 선언
//      [1] User user;  //  마치  int a; 랑 비슷하다.
// 3) 사용 
//      [1] user.num = 1001;  // . 으로 내부 변수에 접근한다.


// 구조체 방법1
struct User {
	int num;
	int score;
};

// 구조체 방법2
typedef struct _User1 {
	int num;
	int score;
}User1;

// 익명 구조체는 구조체 별칭 반!드!시!
typedef struct {
	char name[20];
	int age;
	char address[100];
}Person;

void main() {

	struct User user;
	user.num = 1001;
	user.score = 10;
	printf("학번 : %d, 성적 : %d\n", user.num, user.score);

	User1 user2;
	user2.num = 1002;
	user2.score = 20;
	printf("학번 : %d, 성적 : %d\n", user2.num, user2.score);

	Person p1;			// 익명 구조체는 구조체 별칭으로 변수 선언
	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");
	printf("이름: %s\n", p1.name);    
	printf("나이: %d\n", p1.age);       
	printf("주소: %s\n", p1.address);

	system("pause");
}

/*
할당된 구조체 메모리에 값설정하기

1. 구조체를 통해서 
struct Point2D p1;
memset(&p1, 0, sizeof(struct Point2D));    // p1을 구조체 크기만큼 0으로 설정

==> p1.맴버변수1 = 0;
	p1.맴버변수2 = 0;
			...
	p1.맴버변수last = 0; 과 같은 역할


2. 구조체 포인터를 통해서 값 설정하기
struct Point2D *p1 = malloc(sizeof(struct Point2D));    // 구조체 크기만큼 메모리 할당
memset(p1, 0, sizeof(struct Point2D));    // p1을 구조체 크기만큼 0으로 설정

==> p1->맴버변수1 = 0;
	p1->맴버변수2 = 0;
			...
	p1->맴버변수last = 0;

	free(p1);								// 동적할당시 필수죠잉 ~

*/