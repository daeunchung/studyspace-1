#include <Windows.h>
#include <stdio.h>
#include <string.h> // 문자열 관련 함수제공 

//	구조체와 문자열 [문제]

struct User {
	char* name;
	int score;
};

void main() {
	User* p = 0;		// 주의 ! 구조체 변수 만든거 아니고 구조체 포인터 변수입니다 !
	int count = 0;

	int run = 1;
	while (run) {
		for (int i = 0; i < count; i++) {
			printf("[%d]이름 : %s / 성적 : %d\n", (i + 1), p[i].name, p[i].score);
		}

		printf("1.추가 2.삭제 3.출력"); printf("\n");

		printf("메뉴를 선택하세요 : ");
		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 1) {
			if (count == 0) {
				p = new User[count + 1];
			}
			else if (count > 0) {
				User* temp = p;

				p = new User[count + 1];
				for (int i = 0; i < count; i++) {
					p[i].name = temp[i].name;
					p[i].score = temp[i].score;
				}
				delete[] temp;

			}

			printf("이름을 입력하세요 : ");
			char name[100] = { 0 };
			scanf_s("%s", name, 100);

			int len = strlen(name);
			p[count].name = new char[len + 1];
			strcpy_s(p[count].name, len + 1, name);

			printf("성적을 입력하세요 : ");
			scanf_s("%d", &p[count].score);

			count += 1;

		}
		else if (sel == 2) {
			printf("삭제할 번호를 선택하세요 : ");
			int del_idx = 0;
			scanf_s("%d", &del_idx);

			del_idx -= 1;

			if (count == 1) {
				p = 0;
			}
			else if (count > 1) {
				User* temp = p;

				p = new User[count - 1];
				//p = (User*)malloc(sizeof(User) * (count-1));  동적할당 했응께 ~

				int j = 0; 
				for (int i = 0; i < count; i++) {
					if (i != del_idx) {
						p[j].name = temp[i].name;
						p[j].score = temp[i].score;
						j += 1;
					}
				}

				delete[] temp[del_idx].name;
				// 문자열 이기 때문에 User 가 가지고 있는
				// *temp 칸 메모리 뿐만아니라 , temp[del_idx].name 가 가지고있는 char 메모리도 free 해줘야한다
				// ==> 내가 생각하는 이유임(불확실)

				delete[] temp;
				// int score 의 주소저장칸, char* name 의 주소저장칸 모두의 메모리 할당칸의 메모리를 free 해준다.
				// 이 때에 char* name 은 포인터 이기 때문에 포인터가 가리키는 배열의 메모리도 한번 더 지워줘야해서 윗줄이 수행되는 것.

			}
			
			count -= 1;

		}
		else if (sel == 3) {
			for (int i = 0; i<count; i++) {
				printf("이름 : %s / 성적 : %d\n", p[i].name, p[i].score);
			}
		}
	}
	system("pause");
}

