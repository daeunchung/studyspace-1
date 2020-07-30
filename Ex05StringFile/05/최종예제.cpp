#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 문자열 자르기  ==> strtok_s
// 문자를 숫자로 변환 ==> atoi
struct Student {
	int num;
	char * name;
	int score;
};
int Join(Student ** p, int size);
void Print(Student *p, int size);
void Save(Student *p, int size);
int Load(Student **p);

void main() {
	Student* p = 0;
	int size = 0;
	int run = 1;
	while (1) {
		printf("1.회원가입 2.회원탈퇴 3.전체출력 4.저장 5.로드\n");
		int sel = 0;
		scanf_s("%d", &sel);
		if (sel == 1) {
			//	회원가입
			size = Join(&p, size);
		}
		else if (sel == 2) {
			//	회원탈퇴
		}
		else if (sel == 3) {
			//	전체출력
			Print(p, size);
		}
		else if (sel == 4) {
			//	저장
			Save(p, size);
		}
		else if (sel == 5) {
			//	로드
			size = Load(&p);
		}
	}
}

int Join(Student ** p, int size) {

}
void Print(Student *p, int size) {

}
void Save(Student *p, int size) {

}
int Load(Student **p) {

}