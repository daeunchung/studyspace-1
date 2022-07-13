#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 파일 입출력 io
// 1.쓰기
// 2.읽기

void main() {
	char data[100];
	FILE* file = NULL;	// 파일포인터 메모리에 NULL ==> 0 
	fopen_s(&file, "test.txt", "wt");
	fputs("3,100/20/40", file);
	fclose(file);

	// --------------------------------------
	fopen_s(&file, "test.txt", "rt");	// 1. 읽기 모드로 파일 불러옴 readtext
	fgets(data, 100, file);				// 2. 한줄 자르기
	fclose(file);						// 3. 파일 닫기
	printf("%s", data); printf("\n");
}

/*
fprintf	: 서식을 지정하여 문자열 쓰기 
	fprintf(파일포인터, 서식, 값1, 값2, ...);
	성공하면 쓴 문자열의 길이를 반환, 실패하면 음수를 반환


fscanf	: 서식을 지정하여 문자열 읽기 
	fscanf(파일포인터, 서식, 변수의주소1, 변수의주소2, …);
	성공하면 읽어온 값의 개수를 반환, 실패하면 EOF(-1)를 반환


fputs	: 파일에 문자열 쓰기
	fputs(버퍼, 파일포인터);	
	성공하면 음수가 아닌 값을 반환, 실패하면 EOF(-1)을 반환
	fputs 함수도 파일 포인터 대신 stdout을 지정하면 문자열이 표준 출력(화면)에 출력됩니다.
	==>	fputs("Hello, world!", stdout);    // Hello, world!: 표준 출력(stdout)에 문자열 출력


fwrite	: 파일에 문자열 쓰기
	fwrite(버퍼, 쓰기크기, 쓰기횟수, 파일포인터);
	성공한 쓰기 횟수를 반환, 실패하면 지정된 쓰기 횟수보다 작은 값을 반환
	fwrite 함수는 fputs 함수와는 달리 쓰기 크기와 쓰기 횟수를 지정해야 합니다. 
	따라서 먼저 파일에 쓸 문자열의 포인터 s1을 지정합니다 (배열이나 동적메모리를 할당한 포인터도 가능)
	그리고 쓰기 크기에는 strlen(s1)과 같이 문자열의 길이를 구해서 넣고, 쓰기횟수, 파일포인터 넣어줍니다.
	==>	fwrite(s1, strlen(s1), 1, fp);    // strlen으로 문자열의 길이를 구함.
										// 문자열의 길이만큼 1번 파일에 저장

	fwrite 함수도 파일 포인터 대신 stdout을 지정하면 문자열이 화면에 출력됩니다.
	char *s1 = "Hello, world!";
	fwrite(s1, strlen(s1), 1, stdout);    // Hello, world!
                                      // 문자열 길이만큼 표준출력(stdout)에 문자열 출력


fgets	: 파일에서 문자열 읽기
	fgets(버퍼, 버퍼크기, 파일포인터);
	성공하면 읽은 문자열의 포인터를 반환, 실패하면 NULL을 반환

	char buffer[20];    // 파일을 읽을 때 사용할 임시 공간
	FILE *fp = fopen("hello.txt", "r");    // hello.txt 파일을 읽기 모드로 열기.
	// 파일 포인터를 반환
	fgets(buffer, sizeof(buffer), fp);    // hello.txt에서 문자열을 읽음


fread	: 파일에서 문자열 읽기
	fread(버퍼, 읽기크기, 읽기횟수, 파일포인터);
	성공한 읽기 횟수를 반환, 실패하면 지정된 읽기 횟수보다 작은 값을 반환


	https://dojang.io/mod/page/view.php?id=610
*/