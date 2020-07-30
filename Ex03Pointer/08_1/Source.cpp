#include <Windows.h>
#include <stdio.h>
#include <time.h>

void main() {
	srand(time(0));

	// 학번 국어 수학

	int** pp = 0;
	int count = 0;
	int num = 0;

	int run = 1;
	while (run) {
		printf("학번\t국어\t수학\n");
		for (int i = 0; i < count; i++) {
			printf("[%d] > %d점\t%d점\n", pp[i][0], pp[i][1], pp[i][2]);
		}

		printf("[1]추가\n");
		printf("[2]삭제\n");
		printf("메뉴 선택 : ");
		int choice = 0;
		scanf_s("%d", &choice);

		if (choice == 1) {
			if (count == 0) {
				pp = new int*[1];

				pp[0] = new int[3];
			}
			else if (count > 0) {
				int** temp = pp;

				pp = new int*[count + 1];
				for (int i = 0; i < count; i++) {
					pp[i] = temp[i];
				}
				delete[] temp;

				pp[count] = new int[3];

			}
			int hakbun = 1000 + num;
			int kor = rand() % 100 + 1;
			int eng = rand() % 100 + 1;

			pp[count][0] = hakbun;
			pp[count][1] = kor;
			pp[count][2] = eng;

			count++; num++;

		}
		else if (choice == 2) {
			printf("삭제할 학번을 입력하세요 : ");
			int del_hakbun = 0;
			scanf_s("%d", &del_hakbun);

			int del_idx = -1;
			for (int i = 0; i < count; i++) {
				if (pp[i][0] == del_hakbun) {
					del_idx = i;
				}
			}

			if (del_idx == -1) {
				printf("해당 학번은 존재하지 않습니다.\n");
				continue;
			}

			if (count == 1) {
				pp = 0;
				count = 0;
				num = 0;
			}
			else if (count > 1) {
				int** temp = pp;

				pp = new int*[count - 1];
				int j = 0; 
				for (int i = 0; i < count; i++) {
					if (i != del_idx) {
						pp[j] = temp[i];
						j++;
					}
				}

				delete[] temp[del_idx];		// 키포인트 ! 왜 이렇게 되는지 그림그려서 이해됐음 ! 해결 !
												
				delete[] temp;

			}
			count--;

		}
	}
	system("pause");
}

/*
delete[] : 배열객체에 대한 각각의 소멸자의 호출과 메모리 환원을 한다
delete   : 단일 객체에 대한 소멸자의 호출과 메모리 환원

int*p = new int[5];
delete[] p;    (O)
//delete p;    (X)

가리키는 포인터p는 결국 주소값이므로 delete나 delete[]나 상관없지않나? => 상관이 있거든 !!
4바이트 int 타입을 5개 생성하고 
메모리 delete[] 로 해제할 경우
각 배열릐 요소를 4바이트씩 5번 해제하지만
delete만 사용하게 되면 4바이트 짜리 메모리를 한 번만 해제

우리가 new 연산자 사용하여 메모리 할당시 배열의 크기에 대한 정보를 저장하기 위해 내부적으로 4바이트만큼 메모리를 더 할당한다
이 메모리를 해제할때 delete[]를 사용하면 이 값을 확인하여 해제하지만, delete 만 사용하면 배열의 크기를 확인하지 않고 해제
( delete 실행시 생성한 객체만큼 소멸자가 호출되지 않는다. 소멸자는 한번만 호출되고 오류를 발생시킨다. => 메모리 누수(릭)

*/