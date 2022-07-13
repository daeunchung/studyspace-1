#include <Windows.h>
#include <stdio.h>
#include <time.h>

// # 기억력 게임[구조체(변수) 변경]

struct Memory{
	int count;
	int* front;
	int* back;
};

void main(){

	srand(time(0));
	// 현재 시간은 다시는 돌아올 수 없으므로 매번 컴파일 실행시에 다른 패턴을 만들어주기위해 써준다.
	// ( 1초안에 컴파일 2번하면 같은패턴 나온다고함)

	Memory m = {0};
	m.count = 10;
	m.front = new int[m.count];
	m.back = new int[m.count];


	// {1,1,2,2,3,3,4,4,5,5} 상태의 배열로 값 넣어주기
	int j = 1;
	for (int i = 0; i < m.count; i++) {
		if (i % 2 == 0 && i != 0) {
			j++;	// i가 2 4 6 8 일때만 값을 넣어주기 직전에 +1
		}
		m.front[i] = j;
	}

	for (int i = 0; i < m.count; i++) {
		m.back[i] = 0;
	}
	memset(m.back, 0, 40);
	//memset(m.back, 0, sizeof(int) * m.count);

	
	
	// 셔플
	for (int i = 0; i < 1000; i++) {
		int r = rand() % m.count;
		int tmp = m.front[0];
		m.front[0] = m.front[r];
		m.front[r] = tmp;
	}

	int cnt = 0;
	while (1) {
		printf("front = [ ");
		for (int i = 0; i<m.count; i++) {
			printf("%d ", m.front[i]);
		}
		printf("]\n");
		printf("back =  [ ");
		for (int i = 0; i<m.count; i++) {
			printf("%d ", m.back[i]);
		}
		printf("]\n");


		int idx1 = 0; int idx2 = 0;
		printf("인덱스 1 입력[1~10] : ");
		scanf_s("%d", &idx1);
		idx1 -= 1;

		printf("인덱스 2 입력[1~10] : ");
		scanf_s("%d", &idx2);
		idx2 -= 1;


		if (m.front[idx1] == m.front[idx2]) {
			m.back[idx1] = m.front[idx1];
			m.back[idx2] = m.front[idx2];
			cnt++;
		}

		if (cnt == 5) { break;  }

	}
	system("pause");
}
