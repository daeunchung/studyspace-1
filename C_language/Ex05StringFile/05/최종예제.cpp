#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ���ڿ� �ڸ���  ==> strtok_s
// ���ڸ� ���ڷ� ��ȯ ==> atoi
struct Student {
	int num;
	char * name;
	int score;
};
int Join(Student ** p, int size);
void Print(Student *p, int size);
void Save(Student *p, int size);
int Load(Student **p);

void main() {
	Student* p = 0;
	int size = 0;
	int run = 1;
	while (1) {
		printf("1.ȸ������ 2.ȸ��Ż�� 3.��ü��� 4.���� 5.�ε�\n");
		int sel = 0;
		scanf_s("%d", &sel);
		if (sel == 1) {
			//	ȸ������
			size = Join(&p, size);
		}
		else if (sel == 2) {
			//	ȸ��Ż��
		}
		else if (sel == 3) {
			//	��ü���
			Print(p, size);
		}
		else if (sel == 4) {
			//	����
			Save(p, size);
		}
		else if (sel == 5) {
			//	�ε�
			size = Load(&p);
		}
	}
}

int Join(Student ** p, int size) {

}
void Print(Student *p, int size) {

}
void Save(Student *p, int size) {

}
int Load(Student **p) {

}