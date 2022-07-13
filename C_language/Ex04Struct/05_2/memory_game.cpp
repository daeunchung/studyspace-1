#include <Windows.h>
#include <stdio.h>
#include <time.h>

// # ���� ����[����ü(����) ����]

struct Memory{
	int count;
	int* front;
	int* back;
};

void main(){

	srand(time(0));
	// ���� �ð��� �ٽô� ���ƿ� �� �����Ƿ� �Ź� ������ ����ÿ� �ٸ� ������ ������ֱ����� ���ش�.
	// ( 1�ʾȿ� ������ 2���ϸ� �������� ���´ٰ���)

	Memory m = {0};
	m.count = 10;
	m.front = new int[m.count];
	m.back = new int[m.count];


	// {1,1,2,2,3,3,4,4,5,5} ������ �迭�� �� �־��ֱ�
	int j = 1;
	for (int i = 0; i < m.count; i++) {
		if (i % 2 == 0 && i != 0) {
			j++;	// i�� 2 4 6 8 �϶��� ���� �־��ֱ� ������ +1
		}
		m.front[i] = j;
	}

	for (int i = 0; i < m.count; i++) {
		m.back[i] = 0;
	}
	memset(m.back, 0, 40);
	//memset(m.back, 0, sizeof(int) * m.count);

	
	
	// ����
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
		printf("�ε��� 1 �Է�[1~10] : ");
		scanf_s("%d", &idx1);
		idx1 -= 1;

		printf("�ε��� 2 �Է�[1~10] : ");
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
