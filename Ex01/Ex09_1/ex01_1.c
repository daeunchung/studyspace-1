#include <stdio.h>
#include <math.h>
int main() {
	// 문제1)  9의 배수중  일의 자리가 6인 첫번째 배수 출력
	// 답 : 36

	int  i = 0;
	while (i < 1000) {
		if (i % 10 == 6 && i % 9 == 0) {
			printf("%d", i);		printf("\n");
			i = 1000;		// 오...... 기발하다 break; 안쓰고도 바로 while 문 밖으로 나갈수 있구나

		}
		i += 1;
	}

	// 문제2)  9의 배수중 십의 자리가 6인 첫번째 배수 출력
	//답 : 63

	for (i = 0; i < 100; i++) {
		if (i % 9 == 0 && i / 10 == 6) {
			printf("%d", i);		printf("\n");
			break;
		}
	}

	// 문제3) 8로 나누면 5가 남는수 중 150에 가장 가까운수를 구하시요
	// 답 149
	int gab = 0; int mingab = 8; int ans;
	for (i = 140; i < 160; i++) {
		if (i % 8 == 5 ) {
			gab = abs(i - 150);
			if (gab < mingab) {
				mingab = gab;
				 ans = i;
			}
		}
	}
	printf("%d", ans);		printf("\n");

	// 문제4) 50에서 100까지 자연수중에서 9의 배수는 모두 몇개입니까 ?
	// 답 6 (54, 63, 72, 81, 90, 99)

	int cnt = 0;
	for (i = 50; i <= 100; i++) {
		if (i % 9 == 0) {
			cnt++;
		}
	}printf("%d\n", cnt);

	// 문제5) 28의 배수 중에서 가장 큰 세자리 수를 구하시요.
	// 답 980
	for (i = 1000; i > 900; i--) {
		if (i % 28 == 0) {
			printf("%d\n", i); break;
		}
	}
	//문제6) 8의 배수를 작은수부터 5개 출력
	// 답 : 0, 8, 16, 24, 32
	cnt = 0;
	for (i = 1; i < 100; i++) {
		if (i % 8 == 0) {
			printf("%d ", i);
			cnt++;
		}

		if (cnt = 5) { break; }
	}

}

