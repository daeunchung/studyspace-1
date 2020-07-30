#include <Windows.h>
#include <stdio.h>
#include <time.h>
// 문제 9번 문제 10번 미완성 다시볼것 

/*
# 학생 성적관리 프로그램[구조체(변수+함수) 변경]

예)
학번 = [1001, 1002, 1003, 1004, 1005]
성적 = [  60,  100,   73,    3,   81]

문제 1) 1~100 사이의 랜덤 숫자 5개 저장
정답 1) [60, 100, 73, 3, 81]

문제 2) 전교생의 정보 출력

문제 3) 전교생의 총점 리턴
정답 3) 총점(317점)

문제 4) 전교생의 평균 리턴
정답 4) 평균(63.4점)

문제 5) 합격생(성적 75점이상)의 학번과 성적을 구조체에 저장해 구조체 배열로 리턴
정답 5) 1002학번(100점), 1005학번(81점)

문제 6) 1등 학생의 학번과 성적을 구조체에 저장해 구조체로 리턴
정답 6) 1002학번(100점)

문제 7) 학번을 입력받아 성적 리턴
문제 8) 성적을 입력받아 학번 리턴

문제 9) 학번을 입력받아 학생정보(학번과 성적) 삭제
조건 9) 없는 학번 입력 시, 예외처리

문제 10) 성적순으로 내림차순 정렬

*/

struct Student {
	int hakbun;
	int score;
};

struct Control {
	Student* p;
	int count;

	void init() {
		count = 5;
		p = new Student[count];

		for (int i = 0; i < count; i++) {
			p[i].hakbun = 1001 + i;
		}
	}

	void test1() {
		for (int i = 0; i < count; i++) {
			p[i].score = rand() % 100 + 1;
		}
	}

	void test2() {
		for (int i = 0; i < count; i++) {
			printf("%d학번 (%d점) ", p[i].hakbun, p[i].score);
		}
		printf("\n");
	}

	int test3() {
		int total = 0;
		for (int i = 0; i < count; i++) {
			total += p[i].score;
		}
		return total;
	}

	float test4() {
		int total = test3();
		float avg = total / (float)count;
		// float = int / int; 하면 에러나니 둘중하나만 float로 형변환
		return avg;
	}

	Student* test5(int* p_size) {
		int size = 0;
		for (int i = 0; i < count; i++) {
			if (p[i].score >= 75) {
				size += 1;
			}
		}

		p_size[0] = size;

		//미리 스캔해서 합격자 명수 알아내고 명수만큼 방파주기 ~
		Student* tmp = new Student[size];
		int j = 0;
		for (int i = 0; i < count; i++) {
			if (p[i].score >= 75) {
				tmp[j].hakbun = p[i].hakbun;
				tmp[j].score = p[i].score;
				j += 1;
			}
		}
		return tmp;
	}

	Student test6() {
		int max_s = 0; int max_idx = 0;
		for (int i = 0; i < count; i++) {
			if (max_s < p[i].score) {
				max_s = p[i].score;
				max_idx = i;
			}
		}

		Student tmp = { 0 };
		tmp.hakbun = p[max_idx].hakbun;
		tmp.score = max_s;
		return tmp;
	}

	int test7() {
		int score = 0;
		int num = 0;
		printf("학번 입력 : ");
		scanf_s("%d", &num);
		for (int i = 0; i < count; i++) {
			if (num == p[i].hakbun) {
				score = p[i].score;
			}
		}
		return score;
	}

	int test8() {
		int score = 0;
		int num = 0;
		printf("성적 입력 : ");
		scanf_s("%d", &score);
		for (int i = 0; i < count; i++) {
			if (score == p[i].score) {
				num = p[i].hakbun;
			}
		}
		return num;
	}

	void test9() {
		int del = 0;
		printf("삭제할 학번 입력 : ");
		scanf_s("%d", &del);
		int check = -1;
		for (int i = 0; i < count; i++) {
			if (del == p[i].hakbun) {
				check = i;
			}
		}

		if (check == -1) { printf("학번입력오류\n"); }
		else {
			for (int i = check; i < count - 1; i++) {
				//p[i].hakbun = p[i + 1].hakbun;
				//p[i].score = p[i + 1].score;

				 p[i] = p[i + 1]; 
				// 이건 구조체 의 껍데기 주소만 바꿔주는거 ( 속에 멤버변수를 가리키는 주소를 바꿔주는게 아니라구 )
			}
			count -= 1;		// 중요하지 다 옮겨주고 나서 한명 줄었으니 count 도 1감소
		}
	}

	//다은코드
	//void test10(){
	//	for (int i = 0; i < count; i++) {
	//		int max_s = p[i].score; 
	//		int max_idx = i;

	//		for (int j = i; j < count; j++) {
	//			if (max_s < p[j].score) {

	//				Student tmp = p[max_idx];
	//				p[max_idx] = p[j];
	//				p[j] = tmp;
	//			}
	//		}
	//	}
	//}

	//정답코드
	void test10() {
		for (int i = 0; i<count; i++) {
			int max_score = p[i].score;
			int max_idx = i;
			for (int j = i; j<count; j++) {
				if (max_score < p[j].score) {
					max_score = p[j].score;
					max_idx = j;
				}
			}
			Student tmp = p[i];
			p[i] = p[max_idx];
			p[max_idx] = tmp;
		}
	}
};

void main() {

	srand(time(0));
	Control c = { 0 };
	c.init();					// int count 변수가 struct Control 내에 위치하기 때문에 init()에서 count = 5; 
								// 한번만 해주면 딱히 바꿔주지 않는한 struct 내의 함수 호출하면 count값은 5
	printf(">>>문제 1\n");
	c.test1();
	printf("\n");

	printf(">>>문제 2\n");
	c.test2();
	printf("\n");

	printf(">>>문제 3\n");
	int total = c.test3();
	printf("총점 = %d점\n", total);
	printf("\n");

	printf(">>>문제 4\n");
	float avg = c.test4();
	printf("평균 = %.1f점\n", avg);
	printf("\n");

	printf(">>>문제 5\n");
	int p_size = 0;
	Student* p = c.test5(&p_size);
	//	처음에는 굳..이? p_size 변수를 터서 주소를 왜 함수에 넣어줘야하나 ? 생각이 들었지만
	//	아래 for문에서 i<p_size 까지 돌려야하니까 변수값을 꼭 알 수 있어야하는구나를 깨달음
	for (int i = 0; i < p_size; i++) {
		printf("%d학번 (%d점)", p[i].hakbun, p[i].score);
	}
	printf("\n");
	printf("\n");

	printf(">>>문제 6\n");
	Student tmp = c.test6();
	printf("1등학생 : %d학번 (%d점)", tmp.hakbun, tmp.score);
	printf("\n");

	printf(">>>문제 7\n");
	int score = c.test7();
	printf("점수 = %d점\n", score);
	printf("\n");

	printf(">>>문제 8\n");
	int hakbun = c.test8();
	printf("학번 = %d번\n", hakbun);
	printf("\n");

	printf(">>>문제 9\n");
	c.test9();
	c.test2();
	printf("\n");

	printf(">>>문제 10\n");
	c.test10();
	c.test2();
	printf("\n");

	system("pause");

}
