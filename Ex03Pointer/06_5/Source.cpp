#include <Windows.h>
#include <stdio.h>

// # 무제한배열 => 리스트 / 벡터 

void main() {

	int* p = 0;									// Q. 주소가 0인 자리에 무슨 값이 들어있을지 어찌 알고 ? 
	int count = 0;

	int run = 1;
	while (run == 1) {

		// 시작 부분에 항상 먼저 출력한번 해주고
		for (int i = 0; i < count; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");

		printf("[1] 추가\n");
		printf("[2] 삭제\n");
		printf("[3] 삽입\n");
		printf("[0] 종료\n");

		int sel = 0;
		scanf_s("%d", &sel);

		if (sel == 0) { run = 0; }
		else if (sel == 1) {
		
			if (count == 0) {
				//	한개짜리 방 파주기
				p = new int[1];
			}
			else if (count > 0) {
				//	p가 가진 주소값을 잠시 임시포인터변수에게 넘겨주고
				int* temp = p;
				//	새 방 파기
				p = new int[count + 1];	
				for (int i = 0; i < count; i++) {
					p[i] = temp[i];
				}
				delete[] temp;
			}

			printf("추가할 값 : ");
			int num = 0;
			scanf_s("%d", &num);
			p[count] = num;
			count++;
		}
		else if (sel == 2) {
		
			printf("삭제할 값 : ");
			int num;
			scanf_s("%d", &num);

			int del_idx = -1;
			for (int i = 0; i < count; i++) {
				if (p[i] == num) {
					del_idx = i;
				}
			}

			if (del_idx == -1) {
				printf("입력한 값이 존재하지 않는다");
				continue;
			}

			if (count == 1) {
				p = 0;		// 배열을 가리키는 주소값을 0으로 만들기
			}
			else if(count > 1){
				int* temp = p;

				p = new int[count - 1];
				int j = 0;
				for (int i = 0; i < count; i++) {
					if (i != del_idx) {
						p[j] = temp[i];
						j++;
					}
				}
				delete[] temp;
			}
			count--;
		}
		else if (sel == 3) {
		
			printf("삽입할 위치 입력 : ");
			int insert_idx = 0;
			scanf_s("%d", &insert_idx);

			if (count < insert_idx || insert_idx < 0) {
				printf("해당 위치에 삽입 불가능");
				continue;
			}

			printf("삽입할 값 입력 : ");
			int insert_num = 0;
			scanf_s("%d", &insert_num);

			if (count == 0) {
				p = new int[1];
			} 
			else if (count > 0) {
				int* temp = p;

				p = new int[count + 1];
				int j = 0;
				for (int i = 0; i < count+1; i++) {
					if (i != insert_idx) {
						p[i] = temp[j];
						j++;
					}
				}
				delete[] temp;
			}
			p[insert_idx] = insert_num;
			count++;
		}
	}
	system("pause");
}
