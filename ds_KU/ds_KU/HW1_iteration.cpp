#include <stdio.h>
#include <time.h>
//	Iteration version นÝบน

int Fact_iter(int n) {
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		tmp = tmp * i;
	}
	return tmp;
}

int main() {
	clock_t start, end;
	float result;
	int fact = 0;

	start = clock();
	for (int i = 1; i < 20; i++) {
		printf("%d! : %d\n", i, Fact_iter(i));
	}
	end = clock();
	result = (float)(end - start);

	printf("run time : %.3f ms\n", result);
	return 0;
}


