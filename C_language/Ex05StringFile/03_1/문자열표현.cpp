#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {
	// # const ==> ������ ����� �ٲ۴�. �ѹ� ����Ǹ� ������Ұ���.
	const char* name = "��ö��";
	// ���ü�� "��ö��" �� ����� ������ش� ( ������ name�� ���� ���� )
	// �����͸� ����� ����� �ʹٸ� char* const name = &a; �� ���� ������ !
	// const char* const name = &a; ���ָ� �Ѵ� �����
	// https://m.blog.naver.com/lyw94k/220845759642


	int a = strlen(name);	
	printf("%d", a);		// 6   �ѱ��� 2byte
	printf("\n");

	char temp[] = "abcdefg";
	a = strlen(temp);
	printf("%d", a);		// 7   ����� 1byte
	printf("\n");

	char* test = new char[a + 1];	//char[8]
	strcpy_s(test, a + 1, temp);	// test ���� �޸�ũ�� a + 1 ��ŭ temp ���� ���� copy
	printf("%s", test);
	printf("\n");
	system("pause");


}