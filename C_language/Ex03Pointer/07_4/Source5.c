#include <Windows.h>
#include <stdio.h>

void main() {
	// 1001 // 70, 60
	// 1002 // 50, 30, 20
	// 1003 // 30
	// 1004 // ����

	int arr[4][10000] = { 0 };

	int** pp = 0;
	int count = 4;

	pp = (int**)malloc(sizeof(int*)*count);
	// ���� �����Ϳ� (int ������ ũ�� * ���� ũ��)��ŭ
    // ���� �޸� �Ҵ�. �迭�� ����

	pp[0] = (int*)malloc(sizeof(int)*2);
	pp[0][0] = 70;
	pp[0][1] = 60;


	pp[1] = (int*)malloc(sizeof(int) * 3);
	pp[1][0] = 50;
	pp[1][1] = 30;
	pp[1][2] = 20;

	pp[2] = (int*)malloc(sizeof(int) * 1);
	pp[2][0] = 30;

	pp[3] = (int*)malloc(sizeof(int) * 10001);
	system("pause");
	// ������ �׸� ��� �׷���



}