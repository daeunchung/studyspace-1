#include <Windows.h>
#include <stdio.h>

void main() {

	// # �迭�� ������ ����� �Ҵ�
	int arr[3];		// ��� ==> 3
	new int[3];

	// # �����Ҵ�
	int a = 3;
	int* p = new int[a];
	// �����Ҵ� ���� �����Ŷ�� �����ϸ�� 
	// �� �������� new ���ְ� heap �޸� ����ϴ°�

	printf("�迭�� ũ�⸦ �Է��ϼ��� : ");
	int size = 0;
	scanf_s("%d", &size);

	//	int test[size];		// �� �� �� ��
	int* tp = new int[size];

}