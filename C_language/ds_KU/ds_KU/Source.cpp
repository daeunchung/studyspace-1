//// C��� ���α׷� ���� �ð��� ����

// ������ ��α� �ڵ�
//
//#include <stdio.h>
//#include <time.h>
//
//int func1(int x)
//{
//	return x + x;
//}
//
//inline int func2(int x)
//{
//	return x + x;
//}
//
//
//int main(void)
//{
//	clock_t start1, start2, end1, end2;
//	float res1, res2;
//	int i;
//
//	puts(" \n * �Ϲ� �Լ� \n ");
//	start1 = clock();
//	for (i = 0; i <= 100000; i++)
//	{
//		printf(" i = %6d, func1(%6d) = %d \n", i, i, func1(i));
//	}
//	end1 = clock();
//	res1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
//
//
//	start2 = clock();
//	puts(" \n * inline �Լ� \n ");
//	for (i = 0; i <= 100000; i++)
//	{
//		printf(" i = %6d, func2(%6d) = %d \n", i, i, func2(i));
//	}
//
//	end2 = clock();
//	res2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
//	printf(" �Ϲ��Լ� �ҿ�� �ð� : %.3f \n", res1);
//	printf(" line�Լ� �ҿ�� �ð� : %.3f \n", res2);
//
//	printf(" start1 = %d \n", start1);
//	printf(" start2 = %d \n", start2);
//	printf(" end1   = %d \n", end1);
//	printf(" end2   = %d \n", end2);
//
//	return 0;
//}