//#include <Windows.h>
//#include <stdio.h>
//#include <time.h>
////	Recursion version ���
//
//int Fact(int n) {
//	if (n == 0 || n == 1) {
//		return 1;
//	}
//	else {
//		return Fact(n - 1) * n;
//	}
//}
//
//void main() {
//	time_t start, end;
//	double result;
//	int fact = 0;
//
//	start = time(NULL);
//	fact = Fact(10);
//	end = time(NULL);
//
//	result = (double)(end - start);
//	printf("run time : %f s\n", result);
//
//	system("pause");
//}
//
//
//
///*
//1. 
//time(NULL) �Լ��� �̿��Ͽ� �޾ƿɴϴ�.
//������ ms������ �ƴ� ��(s) ������ ������ �˴ϴ�.
//#include <time.h> ��������� ���Խ�Ű�� �Ʒ��� ���� ����Ͻø� �˴ϴ�.
//
//2.
//clock �Լ��� �̿��Ͽ� �տ� ����� ������ �ذ��Ͽ� ms ������ �ð��� ���� �� �� �ֽ��ϴ�.
//time �Լ��� ���������� include <time.h> ��� ������ ���� ���Ѿ� �մϴ�.
//*/