#include <Windows.h>
#include <stdio.h>
#include <string.h>	// 문자열 관련 함수제공

void main() {
	//	*	문자열 기본개념	*

	// 김철수 ==> 배열
	// 이름여러개  ==> 2차원배열 
	char name[100] = { 0 };

	printf("이름을 입력하세요 "); printf("\n");
	//scanf_s("%s" , &name[0] , 100);  아래 축약형 가능
	scanf_s("%s", name, 100);
	// scanf_s 로 입력받을때는 마지막 3번째 인자에 꼭 배열의 크기 넣어줘야함
	//scanf 함수에서 서식 지정자로 %s를 사용하면 입력 값을 
	//배열 형태의 문자열에 저장할 수 있습니다(stdio.h 헤더 파일에 선언되어 있습니다).

	/*
	scanf_s 함수로 문자열 입력받을 때 !
	scanf_s(문자열 지정받을수 있도록 서식지정자 %s, 입력값을 저장할 배열의 이름(&안붙임), 배열의 크기);
	
	문자열 내의 공백까지 포함하여 입력받으려면 서식 지정자로 %[^\n]s 를 사용
	*/

	//printf("이름 : %s" , &name[0]); printf("\n"); 아래 축약형 가능
	printf("이름 : %s", name); printf("\n");

	for (int i = 0; name[i] != '\0'; i++) {
		printf("[%c]", name[i]);
	}
	printf("\n");

	system("pause");
/*

scanf_s 함수로 문자열을 입력 받을때 scanf함수와 달리 인자가 3개가 필요하다는 걸을 알았습니다. 예를 들면
char name[30];			
scanf("%s", name);		라고 할 경우 아무런 문제가 없죠,
그런데	scanf_s("%s", name);	라고 할경우 원하는 문자열이 제대로 입력이 안됩니다.
printf("%s", name);	로 확인해 보시면 문자가 다 깨져 있는걸 보실수 있을겁니다.

이런 문제는 scanf_s 문자열 배열의 크기를 인식하지 못해서 생기는데요.
해결 방법은 아주 간단하답니다.
scanf_s("%s", name, sizeof(name));
이라고, 마지막에 배열의 크기를 적어 주시면 정상적으로 입력을 받는걸 확인하실수 있습니다.~
scanf_s로 문자열을 입력 받을때 마지막에 배열의 크기를 입력하는거 잊지 마세요~

출처: https://alisa2304.tistory.com/106 [전문가가 되는 그날까지!!]	*/


	//	*	문자열 관련 함수	*
	char temp[100] = { 0 };

	printf("이름을 입력하세요 ");
	scanf_s("%s", temp, 100);

	int len = strlen(temp);
	//	strlen ==> 문자열 배열안의 글자수 반환
	//	예) abc ==> 3

	char * p = new char[len + 1];
	//	 실제 길이 + 1 만큼 동적 할당
	//	이유) 마지막에 \0 들어갈 자리 확보

	/*		여기서 잠깐 !
	'\0' == null문자(널문자) == symbol NULL == 아스키코드 값 0
	'0' == 숫자 0 == 아스키코드 값 48
	*/

	strcpy_s(p, len + 1, temp);
	// strcpy_s 문자열 복사
	// 이유) 문자열은 = 을 사용할 수 없다.


	// p 포인터를 타고 들어간 주소에서부터 len + 1 크기 만큼 temp 속 문자열 값을 복사해서 넣어줘라 .. 이뜻인가?

	// 함수 원형
	// char* strcpy(char* strDestination, const char* strSource);

	printf("복사 성공 : %s", p);	printf("\n");
}

