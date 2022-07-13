#include <Windows.h>
#include <stdio.h>
void main() {
	// ----------------------------------------   3 6 9 게임 
	// 1~50을 차례대로 출력 
	// 조건1) 숫자가 3 이나 6이나 9면 숫자대신 "짝" 출력
	// 조건2) 숫자가 3 이나 6이나 9가 2개면 "짝짝" 출력 
	// 12짝45짝78짝.....
	int n = 1;
	while (n <= 50) {
		int a = n / 10;
		int b = n % 10;
		int count = 0;
		if (a == 3 || a == 6 || a == 9) {
			count += 1;
		}
		if (b == 3 || b == 6 || b == 9) {
			count += 1;
		}
		if (count == 2) {
			printf("짝짝");
		}
		else if (count == 1) {
			printf("짝");
		}
		else {
			printf("%d", n);
		}
		n++;
	}
	printf("\n");
	system("pause");

	// ------------------------------------------   ATM   ------------------------------
/*	int db_id1 = 1111; int db_id2 = 2222;
	int db_m1 = 1000; int db_m2 = 2000;
	int log = -1; //로그아웃은 -1 // 로그인은 해당 아이디 //
	int run = 1;
	while (run == 1) {
		if (log == -1) {
			printf("로그인 하세요 "); printf("\n");
		}
		else {
			printf("[%d] 로그인중 ", log); printf("\n");
		}
		printf("====== mega atm ======="); printf("\n");
		printf("1.로그인 2.종료");
		printf("\n");
		int sel; scanf_s("%d", &sel);
		if (sel == 1) {
			printf("아이디를 입력하세요 ");
			int id; scanf_s("%d", &id);
			if (id == db_id1) {
				log = id;
			}
			if (id == db_id2) {
				log = id;
			}
			while (log != -1) {
				printf("====== %d =======", log); printf("\n");
				printf("3.잔액조회 4.출금 5.입금 0.로그아웃");
				int sel1; scanf_s("%d", &sel1);
				if (sel1 == 0) {
					log = -1;
				}
			}
		}
	}

	system("pause");*/



	// ---------------------------------------------  택시 게임
	// 1.전진 ==> 방향으로 속도만큼 이동 
	// 2.회전 ==> 북 동 남 서  ==> 0 , 1 , 2 , 3
	// 3.속도 ==> 0~3 사이로 이동 
	// 목적지 도착시 ==> 랜덤으로 목적지 변경 (0~10) 
	// 목적지 도착시 ==> 요금 정산 ==> 2칸 마다 50원 추가 
	int money = 0;			int x = 5; int y = 5; int path = 0;
	int speed = 0; int dir = 0;	int dx = 7; int dy = 1;	 int run = 1;
	while (run == 1) {
		system("cls"); // 화면클리어
		printf("[수입] %d", money);						printf("\n");
		printf("[현위치] x : %d, y : %d", x, y);		 printf("\n");
		printf("[속도] %d , [방향] %d ", speed, dir);	 printf("\n");
		printf("[목적지] dx : %d , dy : %d", dx, dy);	printf("\n");
		printf("1.전진 2.회전 3.속도조절");				printf("\n");
		int sel; scanf_s("%d", &sel);
		if (sel == 1) {
			if (dir == 0) {y += speed;}
			else if (dir == 1) { x += speed; }
			else if (dir == 2) { y -= speed; }
			else if (dir == 3) { x -= speed; }
			path += speed;
		}
		else if (sel == 2) {
			printf(" 0) 북 , 1) 동 , 2)남 , 3)서");
			scanf_s("%d", &dir);
		}
		else if (sel == 3) {
			printf("속도를 입력하세요 (0~3)");
			scanf_s("%d", &speed);
		}


		if (x == dx && y == dy) {
			printf("목적지 도착");
			printf("택시요금은 %d원 입니다", path / 2 * 50);		printf("\n");
			dx = rand() % 11;
			dy = rand() % 11;
			system("pause");
		}
	}
}
