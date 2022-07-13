//#include <Windows.h>
//#include <stdio.h>
//
///*
//	# 동적할당
//	1. 동적메모리는 반드시 포인터 변수에 저장해야 한다.
//		int*p = new int;		// heap 메모리에 한 개 생성
//		int* p = new int[3];	// heap 메모리에 3개 생성
//	2. 동적메모리는 메모리 누수를 막기 위해 삭제하는 기능이 있다.
//		delete[] p;				// 여러개 삭제
//*/
//
//// 자바에서는 new 키워드 나오면 무조건 heap 영역에서 객체 방 틔워주기 였는데 그거랑 연관이 있으려나..?
//// 연관 있음 , 사실상 그대로 같게 작동, 
//// 아래 코드의 나머지 모든 변수랑 배열은 모두 stack 영역의 main() 안에 생성되고
//// new int[count] 만 자바 때 배운거랑 "동일하게" heap 영역에 방 틔워줌
//// delete[] p 는 heap 영역에 생성한 방 5칸 없애버림
//
//void main() {
//
//	int num = 10;
//	int arr[5] = { 0 };
//
//	int count = 5;
//	int* p = new int[count];
//	delete[] p;
//
//	system("pause");
//
//}
//// Question . 21 , 22 번 줄에 warning 뜨는데 어째서 콘솔창이 뜨는거지?