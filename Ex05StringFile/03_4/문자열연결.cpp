#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {

	// strcmp, strlen, strcpy_s (compare, length, copy)
	// strcat_s, strtok_s (concatenate 연결시키다, tokenize 조각내다) 
	/*
	strcat : https://dojang.io/mod/page/view.php?id=359

	char *s1 = "world";    // 문자열 포인터
	char *s2 = "Hello";    // 문자열 포인터
	strcat(s2, s1);    // ====> 실행 에러

	문자열 포인터 s2는 읽기 전용 메모리라서 문자열을 붙일 수 없습니다.
	문자열을 붙이려면 s2에 쓰기가 가능하도록 malloc 함수로 동적 메모리를 할당하고, 
	문자열을 붙일 수 있도록 공간도 넉넉하게 20으로 설정해줍니다.

						 ㅣ
						 ㅣ
					    \  /
						 \/

	char *s1 = "world";                      // 문자열 포인터
	char *s2 = malloc(sizeof(char) * 20);    // char 20개 크기만큼 동적 메모리 할당

	strcpy(s2, "Hello");   // s2에 Hello 문자열 복사

	strcat(s2, s1);       // s2 뒤에 s1을 붙임

	printf("%s\n", s2);   // Helloworld

	free(s2);    // 동적 메모리 해제

	이런식으로 사용해야함 !!




	strtok : https://dojang.io/mod/page/view.php?id=376
	개념설명 정말 잘 나와있음
	*/



	// 최민정/이영수/김민희/박철수/오영수
	// 한줄의 문자열로 연결하기
	char name[5][100] = { 
		{ "최민정" },{ "이영수" },{ "김민희" },{ "박철수" },{ "오영수" }
	};

	char temp[1000] = { 0 };
	for (int i = 0; i < 5; i++) {
		strcat_s(temp, name[i]);
		if (i < 4) {
			strcat_s(temp, "/");
		}
	}

	printf("%s", temp);	printf("\n");

	// ----------------------------------------------------------------------
	// 숫자를 문자로 변환
	// _itoa_s(1.저장할숫자 2.문자배열 3.10진수)
	char itoa_temp[100] = { 0 };		// 저장할 문자열을 먼저 파주고
	_itoa_s(1001, itoa_temp, 10);
	printf("%s", itoa_temp);	printf("\n");

	int score[5] = { 10, 50, 30, 50, 7};
	int num[5] = { 1001, 1002, 1003, 1004, 1005 };

	char data[1000] = { 0 };
	strcat_s(data, "5");
	strcat_s(data, "\n");

	for (int i = 0; i < 5; i++) {
		_itoa_s(num[i], itoa_temp, 10);		// 숫자는 문자로 변환해주고 배열과 배열을 연결해주자.
		strcat_s(data, itoa_temp);
		strcat_s(data, "/");

		strcat_s(data, name[i]);
		strcat_s(data, "/");

		_itoa_s(score[i], itoa_temp, 10);		
		strcat_s(data, itoa_temp);

		if (i < 4) {
			strcat_s(data, "\n");
		}
	}

	printf("%s", data); printf("\n");

	system("pause");
}