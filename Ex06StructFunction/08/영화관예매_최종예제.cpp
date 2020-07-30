#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
# 영화관 예매
1. 회원가입
2. 로그인
3. 로그아웃
4. 충전
5. 예매하기
6. 예매취소
0. 종료
*/

struct Client {
	char* id;
	char* pw;
	int money;
};

struct Movie {
	int cnt;
	Client* client;	// *회원정보
	int* seat;		// *좌석 

	int log;

	void print_all() {
		if (log == -1) {
			printf("로그아웃 상태\n");
		}
		else {
			printf("%s 로그인 중...\n", client[log].id);
		}
		for (int i = 0; i < cnt; i++) {
			printf("ID[%s], PW[%s], Money[%d]\n", client[i].id, client[i].pw, client[i].money);
		}
	}

	void init() {
		cnt = 0;
		client = 0;
		seat = 0;
		log = -1;
		seat = new int[10];
		for (int i = 0; i < 10; i++) {
			seat[i] = -1;
		}
	}

	void print_menu() {
		printf("1. 회원가입\n");
		printf("2. 로그인\n");
		printf("3. 로그아웃\n");
		printf("4. 충전\n");
		printf("5. 예매하기\n");
		printf("6. 예매취소\n");
		printf("0. 종료\n");
	}
	
	void member() {				// 1. 회원가입
		char id[100] = { 0 };
		printf("ID를 입력하세요 : ");
		scanf_s("%s", &id[0]);

		char pw[100] = { 0 };
		printf("PW를 입력하세요 : ");
		scanf_s("%s", &pw[0]);

		int money = 0;
		printf("적립할 금액을 입력하세요 : ");
		scanf_s("%d", &money);

		if (cnt == 0) {
			client = new Client[cnt + 1];
		}
		else {
			Client* tmp = client;

			client = new Client[cnt + 1];		// 회원가입해서 명 수 한명 느니까 cnt + 1
			for (int i = 0; i < cnt; i++) {
				client[i] = tmp[i];
			}
			delete[] tmp;
		}

		//포인터로 가리키고 있으면 무조건 메모리 크기 (방칸 수)만큼 뚫어서 주소 넣어주는거야
		int len = strlen(id);
		client[cnt].id = new char[len + 1];		// 문자열은 무조건 끝에 \0 자리 한칸 생각해서 len + 1
		strcpy(client[cnt].id, id);

		len = strlen(pw);
		client[cnt].pw = new char[len + 1];		// 포인터면 메모리 파주기
		strcpy(client[cnt].pw, pw);				// 문자열이면 strcpy

		client[cnt].money = money;				// int 면 그냥 넣어줘 ㅎㅎㅎ

		cnt += 1;

		save();									// 내용이 변했으면 저장을 해줘야함
	}

	void login() {				// 2. 로그인
		char id[100] = { 0 };
		printf("ID를 입력하세요 : ");
		scanf_s("%s", &id[0]);

		char pw[100] = { 0 };
		printf("PW를 입력하세요 : ");
		scanf_s("%s", &pw[0]);

		for (int i = 0; i < cnt; i++) {
			if (strcmp(id, client[i].id) == 0 && strcmp(pw, client[i].pw) == 0) {
				log = i;
			}
		}

		if (log == -1) {
			printf("ID와 PW를 확인해주세요.\n");
		}
		else {
			printf("%s님, 환영합니다.\n", client[log].id);
		}
	}

	void logout() {				// 3. 로그아웃
		if (log != -1) {
			log = -1;
			printf("로그아웃 되었습니다.\n");
		}
	}

	void add_money() {			// 4. 충전
		if (log != -1) {
			int money = 0;
			printf("충전할 금액을 입력하세요 : ");
			scanf_s("%d", &money);

			client[log].money += money;
			printf("충전을 완료하였습니다.\n");
		}
		save();
	}

	void print_seat() {
		printf("[ ");
		for (int i = 0; i<10; i++) {
			if (seat[i] == -1) {
				printf("[ ] ");
			}
			else {
				printf("[%s] ", client[seat[i]].id);
			}
		}
		printf("]\n");
	}

	void set_seat() {			// 5. 예매하기
		if (log == -1) {
			print_seat();
			int sel = 0;
			printf("좌석번호를 입력하세요[1~10] : ");
			scanf("%d", &sel);
			sel -= 1;

			if (seat[sel] == -1) {
				seat[sel] = log;
				client[log].money -= 12000;
				printf("예약을 완료하였습니다.\n");
			}
			else {
				printf("해당 좌석은 예약이 완료되었습니다.\n");
			}
		}
		save();
	}

	void cancel_seat() {		// 6. 예매취소
		int check = -1;
		if (log != -1) {
			for (int i = 0; i < 10; i++) {
				if (seat[i] == log) {
					check = i;
				}
			}
		}

		if (check == -1) {
			printf("예약된 좌석이 없습니다.\n");
		}
		else {
			seat[check] = -1;
			printf("예약이 취소되었습니다.\n");
		}
		save();
	}

	void load() {							// load => read => fgets 
		char data[100] = { 0 };

		FILE* f = NULL;
		fopen_s(&f, "movie.txt", "rt");
		if (f != NULL) {
			fgets(data, 100, f);

			cnt = atoi(data);

		}
	}

	void save() {							// save => write => fputs

	}

	void run() {

		init();		//	방파주기
		load();		//	
		while (1) {

			print_seat();		//	좌석상태 출력
			print_all();		//	id pw 충전금 출력
			print_menu();		//	메뉴 출력

			int sel = 0;
			printf("메뉴 선택 : ");
			scanf_s("%d", &sel);

			if (sel == 1) { member(); }
			else if (sel == 2) { login(); }
			else if (sel == 3) { logout(); }
			else if (sel == 4) { add_money(); }
			else if (sel == 5) { set_seat(); }
			else if (sel == 6) { cancel_seat(); }
			else if (sel == 0) {
				printf("프로그램 종료\n");
				break;
			}


		}



	}
};
