#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {
	// # const ==> 변수를 상수로 바꾼다. 한번 저장되면 값변경불가능.
	const char* name = "김철수";
	// 대상체인 "김철수" 를 상수로 만들어준다 ( 포인터 name은 아직 변수 )
	// 포인터를 상수로 만들고 싶다면 char* const name = &a; 와 같은 식으로 !
	// const char* const name = &a; 해주면 둘다 상수로
	// https://m.blog.naver.com/lyw94k/220845759642


	int a = strlen(name);	
	printf("%d", a);		// 6   한글은 2byte
	printf("\n");

	char temp[] = "abcdefg";
	a = strlen(temp);
	printf("%d", a);		// 7   영어는 1byte
	printf("\n");

	char* test = new char[a + 1];	//char[8]
	strcpy_s(test, a + 1, temp);	// test 부터 메모리크기 a + 1 만큼 temp 속의 값을 copy
	printf("%s", test);
	printf("\n");
	system("pause");


}