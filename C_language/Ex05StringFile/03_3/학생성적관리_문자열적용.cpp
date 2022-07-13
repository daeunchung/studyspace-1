#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h> 
#include <string.h>

// 삭제가
// 안돼 
// 다시봐바






// 숫자 입력 받은거는 그냥 넣어주고 // 문자열 입력 받은거는 미리 char* 파준후 메모리 할당하고 strcpy 잊지마 ~

struct Student {
	char* name;			// 이름문자저장포인터
	int* score;			// 점수숫자저장포인터
	int score_count;	// 점수의 개수
};

void main() {

	Student* p = 0;		// 구조체 Student저장포인터
	int st_count = 0;	// 학생수 ( 구조체 개수 나타내는 숫자 )

	int run = 1;
	while (run) {
		printf("[1]추가\n");
		printf("[2]삭제\n");		// 이름 입력받아 삭제
		printf("[3]정렬\n");
		printf("[4]출력\n");

		printf("메뉴 선택 : ");
		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 1) {

			if (st_count == 0) {
				p = new Student[1];
			}
			else if (st_count > 0) {
				Student* temp = p;
				p = new Student[st_count + 1];

				for (int i = 0; i < st_count; i++) {
					p[i] = temp[i];
				}
				delete[] temp;
			}
			printf("과목 수 입력 : ");
			scanf_s("%d", &p[st_count].score_count);

			p[st_count].score = new int[p[st_count].score_count];
			for (int i = 0; i < p[st_count].score_count; i++) {

				printf("%d번 과목 점수를 입력하세요 : ", (i + 1));
				scanf_s("%d", &p[st_count].score[i]);
			}

			printf("이름을 입력하세요 : ");
			char temp[100] = { 0 };
			scanf_s("%s", temp, 100);		// (서식지정자, 입력받는메모리이름, 메모리크기)

			int len = strlen(temp);

			p[st_count].name = new char[len + 1];
			strcpy_s(p[st_count].name, len + 1, temp);
			//	p[st_count].name에 len + 1 크기만큼 temp 속 내용물을 copy

			st_count += 1;

		}
		else if (sel == 2) {
			printf("삭제할 이름을 입력하세요 : ");
			char temp[100] = { 0 };
			scanf_s("%s", temp, 100);		// (서식지정자, 입력받는메모리이름, 메모리크기)

			int del_idx = -1;
			for (int i = 0; i < st_count; i++) {
				if (strcmp(p[i].name, temp) == 0){
					del_idx = i;
				} 
			}


			if (del_idx == -1) {
				printf("이름을 잘못입력했습니다.\n");
			}
			else {
				if (st_count == 1) {
					p = { 0 };
				}
				else if (st_count > 1) {
					Student* temp = p;
					p = new Student[st_count - 1];

					int j = 0;
					for (int i = 0; i < st_count-1; i++) {
						if (i != del_idx) {
							p[i] = temp[j];
						}
						j += 1;
					}

					/* 또는 위에랑 같은 역할 수행
					p = new Student[st_count - 1];
					for(int i=0; i<remove; i++){
					p[i] = temp[i];
					}
					for(int i=remove; i<st_count - 1; i++){
					p[i] = temp[i + 1];
					}*/

					delete[] temp[del_idx].name;
					delete[] temp[del_idx].score;
					delete[] temp;
					// temp 는 struct Student {char* name; int* score;	int score_count;}; 구조의 
					// Student* (포인터변수)니까 해당 구조체가 속에 가지고 있는 포인터 변수들은 다 타고 들어가서 내용물을 각각 지워줘야함 
					// ==> 그림으로 그려보는 것이 아주 중요 !

					st_count -= 1;
				}
			}
		}
		else if (sel == 3) {				// 이름으로 정렬	(오름차순 이겠지 당연히)

			//for (int i = 0; i < st_count; i++) {
			//	// 정렬할꺼니 비교할 첫 값 변수로 박아놓고
			//	int idx = i;
			//	char max[100] = { 0 };
			//	strcpy_s(max, 100, p[i].name);	// 인자 3개라 순서 주의 
			//	// (복사받는주소포인터, 복사받는주소포인터가 가리키는 메모리크기, 복사해줄문자열주소포인터)
			//	
			//	for (int j = i; j < st_count; j++) {
			//		if (strcmp(max, p[j].name) == 1) {
			//			// 	if (strcmp([idx].name, p[j].name) == 1 ) {} : 같은말
			//			// strcmp_s(a,b) a가 b보다 더 크면 교환 : 큰놈이 뒤로가야지
			//			strcpy_s(max, 100, p[i].name);
			//			idx = j;
			//		}
			//	}
			//	Student temp = p[i];
			//	p[i] = p[idx];
			//	p[idx] = temp;
			//}

			for (int i = 0; i < st_count; i++) {
				for (int j = i; j < st_count; j++) {
					if (strcmp(p[i].name, p[j].name) == 1) {
						Student temp = p[i];
						p[i] = p[j];
						p[j] = temp;
					}
				}
			}	
		}
		else if (sel == 4) {
			for (int i = 0; i<st_count; i++) {
				printf("%s : ", p[i].name);
				for (int j = 0; j<p[i].score_count; j++) {
					printf("%d ", p[i].score[j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}

	system("pause");
}
