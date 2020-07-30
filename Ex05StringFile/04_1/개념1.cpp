#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>	// malloc 함수
#include <string.h>
// 파일 입출력 (io)
// 1.쓰기
void main() {
	FILE * file;	// 저장할 메모리위치 (보통 프로젝트)
	fopen_s(&file, "test.txt", "wt");
	// 1. 파일 만들기	[1] &file		==> 저장할 메모리주소
	//					[2] "test.txt"	==> 파일이름
	//					[3] "wt"		==> write.text 의 약자 저장용으로 연결
	fputs("헬로우씨언어", file);			// 2. 파일에 내용저장하기
	fclose(file);						// 3. 파일 닫기

	// 문제1) 아래 배열을 test01.txt 파일에 저장
	// 조건 ==> 아래의 모양으로 저장
	// 100/34/65/2
	int arr[4] = { 100, 34, 65, 2 };

	// test01.txt ==> int 상태로 그냥 넣어서 출력해주기

	//fopen_s(&file, "test01.txt", "wt");
	//for (int i = 0; i < 4; i++) {
	//	fprintf_s(file, "%d", arr[i]);

	//	if (i < 3) {
	//		fprintf_s(file, "%s", "/");
	//	}
	//}

	//test02.txt ==> int 를 문자열로 바꿔서 문자열 저장해주기
	fopen_s(&file, "test02.txt", "wt");

	char itoatemp[100] = { 0 };
	for (int i = 0; i < 4; i++) {
		_itoa_s(arr[i], itoatemp, 10);
		fputs(itoatemp, file);

		if (i < 3) {
			fputs("/", file);
		}
	}
	fclose(file);
}


/*
지금까지 printf로 서식을 지정하여 문자열을 화면에 출력하고, sprintf로 서식을 지정하여 문자열을 생성했습니다. 그럼 문자열을 파일에 쓸 수는 없을까요? 이때는 printf의 파일 버전인 fprintf를 사용하면 됩니다.
파일에 문자열을 쓸 때는 먼저 fopen 함수로 파일을 열어서 파일 포인터를 얻은 뒤 fprintf 함수를 사용합니다
(stdio.h 헤더 파일에 선언되어 있습니다).

FILE *포인터이름 = fopen(파일명, 파일모드);
	FILE *fopen(char const *_FileName, char const *_Mode);
	성공하면 파일 포인터를 반환, 실패하면 NULL을 반환
fprintf(파일포인터, 서식, 값1, 값2, ...);
	int fprintf(FILE * const _Stream, char const * const _Format, ...);
	성공하면 쓴 문자열의 길이를 반환, 실패하면 음수를 반환
fclose(파일포인터);
	int fclose(FILE *_stream);
	성공하면 0을 반환, 실패하면 EOF(-1)를 반환


Ctrl + f5 실행후 콘솔창 끄고
솔루션 탐색기에서 프로젝트 위에 커서 놓고 마우스 우클릭, 파일탐색기 에서 폴더열기
폴더 안에 .txt 파일 열면 안에 들어있음
https://dojang.io/mod/page/view.php?id=607
*/


/*scanf로 문자형 입력을 받을 때
%c로 입력받으면 제일 앞의 문자를 입력 받을 수 있게 되고 %s로 받으면 하나의 단어를 입력 받을 수 있다. 
예를들어 apple의 경우 %c는 'a'가 %s의 경우 'apple'을 전달인자로 받게 된다.
scanf로 문자를 입력을 받을 땐 일반 int형 변수의 경우는 앞에 &를 붙여서 받지만 문자열은 그렇지 않다.
ex) scanf("%d", &ex1) int형 변수 ex1을 받는 경우
ex) scanf("%s", ex2) char형 변수 ex2를 받는 경우
출처: https://coolbre.tistory.com/18 [dev80]*/


/*itoa는 마이크로소프트 비주얼스튜디오에서만 정의해놓은 함수입니다. 
따라서 우분투 등 다른 플랫폼에서 개발하시는 분은 사용하실 수가 없었을 겁니다.
그래서 itoa 함수 대신에 sprintf를 사용하는 것을 권장드립니다! */