//malloc�Լ��� calloc�Լ��� ������!
//malloc�� �Ҵ�� ������ ������ �ٲ��� �ʴ´�.
//calloc�� �Ҵ�� ������ ���� ��� 0���� �ٲ۴�.
//�迭�� �Ҵ��ϰ� ��� 0���� �ʱ�ȭ�� �ʿ䰡 ������쿡�� calloc�� ���� ���ϴ�.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr_1[5];	// �迭 ����
	int* arr_2;		// ������ ���� ����

	int i; for (i = 0; i < 5; i++) {
		arr_1[i] = i + 1;	// �迭�� �� ����
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);
	// �޸� �Ҵ�, �迭�� ũ�⸸ŭ �Ҵ��ϱ� ���� 5�� ����

	arr_2 = (int*)calloc(5, sizeof(int));
	// sizeof(int)ũ���� ������ 5�� ������ �� �ִ� �����Ҵ�

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];	printf("%d", arr_2[i]);
	}
	free(arr_2);	// free�Լ��� �̿��Ͽ� �޸� ����
	return 0;
}
