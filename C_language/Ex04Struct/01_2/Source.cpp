#include <Windows.h>
#include <stdio.h>

struct User {
	int num;
	int score;
};

void main() {
	User user = { 0 };		// 구조체 속의 모든 멤버 변수를 0으로 초기화 하냐 안하냐 의 차이   // User user; 


/*	struct 구조체이름 변수이름 = { 0, };    // 구조체 변수의 내용을 모두 0으로 초기화
								   // 단 malloc 함수로 할당한 메모리에는 사용할 수 없음*/

	user.num = 1001;
	user.score = 10;

	User user2 = { 0 };
	user2.num = 1002;
	user2.score = 20;

	User user3 = { 0 };
	user3.num = 1003;
	user3.score = 30;

	//----------------------

	User list[3] = { 0 };

	list[0].num = 1001;
	list[0].score = 10;

	list[1].num = 1002;
	list[1].score = 20;

	list[2].num = 1003;
	list[2].score = 30;

	for (int i = 0; i<3; i++) {
		printf("학번 : %d, 점수 : %d\n", list[i].num, list[i].score);
	}

	system("pause");

}
