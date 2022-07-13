#include <Windows.h>
#include <stdio.h>
#include <string.h>

void main() {

	// ���� strlen, ���� strcpy_s
	// �� strcmp ==> ���ʱ������� ũ�� 1, ������ 0, ������ -1

	int a = strcmp("a", "a");	//0
	printf("%d", a);	printf("\n");

	a = strcmp("b", "a");		//1
	printf("%d", a);	printf("\n");

	a = strcmp("a", "b");		//-1
	printf("%d", a);	printf("\n");

	// ����1) �Ʒ� �̸��� ������ ������ (������ ������� )
	char name[4][100] = {
		{"��ö��"}, {"��ö��"}, {"��ö��"}, {"��ö��"}
	};

	for (int i = 0; i < 4; i++) {
		printf("%s ", name[i]);
	}

	printf("\n");

	// ���� §��
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (strcmp(name[i], name[j]) == 1) {	// if(name[i] > name[j])

				char temp[100] = { 0 };
				strcpy_s(temp, 100, name[i]);
				strcpy_s(name[i], 100, name[j]);
				strcpy_s(name[j], 100, temp);
			}
		}
	}


	/*	�����ڵ�
	
		for(int i = 0; i < 4; i++){
		int id = i;
		char max[100] = {0};
		strcpy_s(max , 100 , name[i]);

		for(int j = i; j < 4; j++){
			if(strcmp(max , name[j]) == 1){
				strcpy_s(max , 100, name[j]);
				id = j;
			}
		}
		char temp[100] = {0};
		strcpy_s(temp , 100 , name[i]);
		strcpy_s(name[i] , 100 , name[id]);
		strcpy_s(name[id]  , 100 , temp);
	}
	
	*/

	for (int i = 0; i < 4; i++) { 
		printf("%s ", name[i]);
	}

	printf("\n");
}