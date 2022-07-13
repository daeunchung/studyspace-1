#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {

	// 길이 strlen, 저장 strcpy_s
	// 비교 strcmp ==> 왼쪽기준으로 크면 1, 같으면 0, 작으면 -1

	int a = strcmp("a", "a");	//0
	printf("%d", a);	printf("\n");

	a = strcmp("b", "a");		//1
	printf("%d", a);	printf("\n");

	a = strcmp("a", "b");		//-1
	printf("%d", a);	printf("\n");

	// 문제1) 아래 이름을 정렬해 보세요 (가나다 순서대로 )
	char name[4][100] = {
		{"김철수"}, {"이철수"}, {"박철수"}, {"오철수"}
	};

	for (int i = 0; i < 4; i++) {
		printf("%s ", name[i]);
	}

	printf("\n");

	// 내가 짠거
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (strcmp(name[i], name[j]) == 1) {	// if(name[i] > name[j])

				char temp[100] = { 0 };
				strcpy_s(temp, 100, name[i]);
				strcpy_s(name[i], 100, name[j]);
				strcpy_s(name[j], 100, temp);
			}
		}
	}


	/*	정답코드
	
		for(int i = 0; i < 4; i++){
		int id = i;
		char max[100] = {0};
		strcpy_s(max , 100 , name[i]);

		for(int j = i; j < 4; j++){
			if(strcmp(max , name[j]) == 1){
				strcpy_s(max , 100, name[j]);
				id = j;
			}
		}
		char temp[100] = {0};
		strcpy_s(temp , 100 , name[i]);
		strcpy_s(name[i] , 100 , name[id]);
		strcpy_s(name[id]  , 100 , temp);
	}
	
	*/

	for (int i = 0; i < 4; i++) { 
		printf("%s ", name[i]);
	}

	printf("\n");
}