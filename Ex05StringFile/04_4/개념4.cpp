#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자열 자르기	==> strtok_s
// 문자를 숫자로 변환	==> atoi
/*
char *strtok_s(char *_String, const char *_Delimit, char **_Context);
[ 반환값 :: 양분된 문자열 중 첫번째 문자열의 시작 주소 ]

[ 첫번째 인수 :: 원본 문자열 ]
본 함수는 원본 문자열을 수정합니다.
따라서 문자열 상수(const char *)를 전달하면 실행 오류로 프로그램이 중단될 수 있습니다.
( strtok("1234 5678", ...); // 이렇게 사용하면 안 됩니다. )

[ 두번째 인수 :: 구분 기호 집합 ]
구분 기호는 문자열 형태로 전달하며 여러개를 사용할 수 있습니다.

[ 세번째 인수 :: 양분된 문자열 중 두번째 문자열의 시작 주소를 저장할 포인터 변수의 주소 ]
*/
struct Student {
	char* name;
	int score;
};

void main() {
	char data[100] = "3\n김철수/20\n이만수/30\n최민수/50";
	printf("%s", data); printf("\n");
	char* end;
	char* front;
	front = strtok_s(data, "\n", &end);					// 세번째 인수는 포인터 변수의 주소인거 잊지마
	// "\n" 을 기준으로 "3" 은 front에 저장
	// 남은 "김철수/20\n이만수/30\n최민수/50" 는 end 에 저장
	printf("%s", front); printf("\n");
	printf("%s", end); printf("\n");

	int size = atoi(front);
	// 자바에서 Integar.parseInt랑 같은건가봐 ㅎ.ㅎ
	Student* p = new Student[size];
	for (int i = 0; i < size; i++) {
		front = strtok_s(end, "\n", &end);
		char* end2;
		front = strtok_s(front, "/", &end2);
		int len = strlen(front);
		p[i].name = new char[len + 1];			// 끝에 null 들어갈 한자리 확보
		strcpy_s(p[i].name, len + 1, front);
		p[i].score = atoi(end2);
	}

	for (int i = 0; i < size; i++) {
		printf("[%s]", p[i].name);
		printf("[%d]", p[i].score);	printf("\n");
	}
}