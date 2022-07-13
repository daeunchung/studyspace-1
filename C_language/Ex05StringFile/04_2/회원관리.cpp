#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*scanf_s 함수와 같이 _s가 붙은 함수들은 만자열을 받을 때 사용자가 입력한 문자의 개수가 메모리의 크기를
넘어서는 문제를 막기 위해 사용할 메모리의 크기를 명시해야 합니다.*/

/*fopen과 fopen_s 을 어떻게 다르게 사용해야 하는지 설명해주는 링크
https://blog.naver.com/tipsware/221663656260
*/

// 탈퇴가
// 안돼
// 다시해야해

struct User {
	int num;	char id[100];	char pw[100];
};

void main() {
	User* p = 0;
	int userCount = 0;
	int run = 1;
	// 0명일때 저장 ==>

	while (1) {
		printf("1.회원가입 2.탈퇴 3.저장 4.출력  ");
		int sel;
		scanf_s("%d", &sel);

		if (sel == 1) {
			if (userCount == 0) {
				p = new User[1];
			}
			else {
				User* temp = p;
				p = new User[userCount + 1];
				for (int i = 0; i < userCount; i++) {
					p[i] = temp[i];
				}
				delete[] temp;
			}

			p[userCount].num = 1000 + userCount + 1;
			printf("아이디를 입력하세요 ");
			scanf_s("%s", p[userCount].id, 100);
			printf("비밀번호를 입력하세요 ");
			scanf_s("%s", p[userCount].pw, 100);

			userCount += 1;
		}



		else if (sel == 2) {
			printf("탈퇴할 계정 아이디 입력하세요 ");
			char* del_id;

			scanf_s("%s", &del_id);

			int del_idx = -1;
			for (int i = 0; i < userCount; i++) {
				if (p[i].id == del_id) {
					del_idx = i;
				}
			}


			if (userCount == 1) {
				p = { 0 };
			}
			else if(userCount > 1){
				User* temp = p;
				p = new User[userCount - 1];

				int j = 0;
				for (int i = 0; i < userCount-1; i++) {
					if (j != del_idx) {
						p[i] = temp[j];
						j++;
					}
				}
				delete[] temp;
			}
			userCount = -1;
		}


		else if (sel == 3) {
			if (userCount <= 0) {
				continue;
			}
			char data[10000] = { 0 };
			char itoatemp[1000] = { 0 };
			//	1. 총인원수 숫자->문자열		2. "\n"		
			//	3. 회원번호 숫자-> 문자열		4. "/"
			//	5. 회원id	6."/"	7.회원pw		8."/"	
			//	9. 한 회원 끝나면 "\n"

			_itoa_s(userCount, itoatemp, 10);					// 10진수로
			strcat(data, itoatemp);
			strcat(data, "\n");

			for (int i = 0; i < userCount; i++) {
				_itoa_s(p[i].num, itoatemp, 10);
				strcat(data, itoatemp);
				strcat(data, "/");
				strcat(data, p[i].id);
				strcat(data, "/");
				strcat(data, p[i].pw);
				if (i < userCount - 1) {
					strcat(data, "\n");
				}
			}
			printf("%s", data);	printf("\n");
			FILE * file = 0;
			fopen_s(&file, "test01.txt", "wt");
			fputs(data, file);
			fclose(file);
		}


		else if (sel == 4) {
			for (int i = 0; i < userCount; i++) {
				printf("[%d] [%s] [%s]", p[i].num, p[i].id, p[i].pw);
				printf("\n");
			}
		}
	}
}


/*
errno_t fopen_s(FILE **pfp, const char *path,const char *mode); 파일 스트림을 여는 함수
입력 매개 변수 리스트
1. pfp 연 파일 스트림을 설정할 FILE *형식 변수의 주소
2. path 절대 경로 혹은 상대 경로
3. mode rwba+의 조합 문자열, fopen과 같습니다.
반환 값

성공하면 0, 실패하면 에러 값

C11 표준에서는 FILE 구조체인 struct _iobuf의 내부 멤버를 숨기고 있습니다. 
개발자에 의해 직접 멤버에 접근하는 것을 방지하여 안전성을 도모하고 있습니다. 
그리고 fopen 함수의 반환 값을 첫 번째 입력 인자로 
FILE 포인터 변수의 주소(FILE 포인터의 포인터)를 받아 설정하는 fopen_s 함수를 제공합니다.
*/