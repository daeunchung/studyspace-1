// === [파일 이름] ===
// _03_stack_mine.cpp 
//===================

#include "mine.h"
void main() {
	// 1) 7 * 7 맵에 0으로 가득 채우고
	// 2) 35개의 폭탄 설치 ( 폭탄은 9로 표현 )
	// 3) 폭탄 위치 섞기
	// 4) 폭탄이 아닌 곳 (0) 주변 8방향을 검사해서 폭탄갯수를 0에 저장
	// 5) 폭탄이 아닌 곳을 입력 받고 연결된 모든 값을 마크 1로 변경

	Mine** map = set_bomb();
	print_map(map);
	shuffle(map);
	print_map(map);
	count_bomb(map);
	print_map(map); 
	int run = 1;
	while (run == 1) {
		// system("cls");
		print_game(map);
		play_game(map);
	}
}