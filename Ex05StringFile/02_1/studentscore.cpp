#include <Windows.h>
#include <stdio.h>

struct Student {
	int* score;	// 각 과목당 점수를 저장하는 배열을 가리키는 배열포인터인듯
	int size;	// 과목 수 (int* score 에 할당된 배열의 int 칸수를 말하는듯)
};


void print_user(Student* p, int count) {
	for (int i = 0; i < count; i++) {
		printf("[%d] ", i);
		for (int j = 0; j < p[i].size; j++) {		// p[i].size 는 i학생이 가진 과목수 인듯
			printf("%d ", p[i].score[j]);
		}
		printf("\n");
	}
	printf("\n");
}

Student* insert_user(Student* p, int* count) {
	if (count[0] == 0) {				//				 int count 값 == count[0] 
										//	==>  (좌의 count는 int형, 우의 count는 int*형)
										//  실수 하지 말자 ! 함수 입력을 int*count 로 받았으면  " 이 함수 안에서는 무조건 "
										//  인원수를 나타내는 int count 값을 나타내고 싶을때마다 무조건 count[0] 으로 써줘야함 
		p = new Student[count[0] + 1];
	}
	else if (count[0] > 0) {
		Student* tmp = p;

		p = new Student[count[0] + 1];	// 기존주소 옮겨놓고 한칸 키운 방 새로 뚫기
		for (int i = 0; i < count[0]; i++) {
			p[i].score = tmp[i].score;
			p[i].size = tmp[i].size;
		}

		//delete[] tmp; 이거 정답코드에 안써져있는데 왜 안써줘도되는걸까..? 의문이드네
	}

	printf("과목 수를 입력 하세요 : ");
	scanf_s("%d", &p[count[0]].size);

	p[count[0]].score = new int[p[count[0]].size];		// 받은 과목 수 개수만큼 배열 방파주기 
	// 우변에서 메모리 할당 후 좌변 score(int* score이니까 포인터변수)에 할당받은 배열 메모리 주소 넘겨주기

	for (int i = 0; i < p[count[0]].size; i++) {
		printf("%d번 과목 점수를 입력하세요 : ", i + 1);
		scanf_s("%d", &p[count[0]].score[i]);			// 앞에 &때면 p[count[0]].score[i] 는 주소속의 값이니 
														// 주소에 넣어줘야하니까 앞에 & 붙여
														// 복습시 꼭 다시한번 볼 부분
	}

	count[0] += 1;			// 내용 다 넣어준 후에 int count 값 ++

	return p;
}


void delete_user(Student** pp, int* count) {
	printf("삭제할 번호를 입력하세요 : ");
	int del_idx = 0;
	scanf_s("%d", &del_idx);
	
	if (count[0] == 1) {
		pp[0] = 0;		// 함수가 Student** pp 를 입력받기 때문에 pp[0] (*pp)은 int* p 값을 나타낸다
	}
	else if (count[0] > 1) {
		Student* temp = pp[0];

		pp[0] = new Student[count[0] - 1];

		int j = 0;
		for (int i = 0; i < count[0]; i++) {
			if (i != del_idx) {
				pp[0][j].score = temp[i].score;
				pp[0][j].size = temp[i].size;
				j += 1;
			}
		}

		delete[] temp[del_idx].score;
		delete[] temp;
	}
	count[0] -= 1;

}



void main() {

	Student* p = 0;
	int count = 0;	// 학생 명수 ( Struct* p 가 가리키는 Struct 의 칸수를 나타내는듯)

	int run = 1;
	while (run == 1) {
		print_user(p, count);

		printf("1.추가 2.삭제 3.출력");
		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 1) { p = insert_user(p, &count); }
		else if (sel == 2) { delete_user(&p, &count); }		// &p 를 던져주니까 위에서 함수의 입력타입이 Struct** pp 인거 쯤은 알아야겠쥬 ~? *^^*
		else if (sel == 3) { print_user(p, count); }
	}

	system("pause");

}