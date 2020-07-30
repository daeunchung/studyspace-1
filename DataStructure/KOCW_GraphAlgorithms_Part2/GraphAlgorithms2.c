
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 그래프 탐색 알고리즘 ( 그래프 검색 알고리즘 )
트리 탐색 알고리즘과 같이 (중위 전위 후위 레벨 순서 탐색) 그래프 검색 알고리즘도 그래프의 특정 정점에서 시작해서
간선을 따라 정점을 검사하며 그래프를 '검색' 하는것
ㄴ
두가지 
Depth First Search (DFS, 깊이 우선 검색)
Breath First Search (BFS, 너비 우선 검색)
*** DFS 
	주어진 정점 u에서 시작
	u부터 다른 정점으로 향하며 간선들 검사
	만약 그 간선이 이미 방문한 정점에 연결되어 있다면 현재의 정점 u로 되돌아온다
	반면 간선이 방문하지 않은 정점에 연결되어 있다면, 그 정점으로 이동하여 그 정점부터 다시 처리시작
		->새 정점을 현재정점으로 바꾸기
	이 과정을 막다른 곳 다다를때까지 반복
	이제 백트래킹이 시작되는데 최초 백트래킹을 시작한 정점에 닿을 때 종료

	미로에서의 교차로 : 그래프 vertex 
	    "		길 : 그래프 edge


컴퓨터 과학에서 검색 (Search)이란 아이템의 집합 중에서 특정한 속성을 가진 한 아이템을 찾는 과정이다.
아이템들은 데이터베이스의 레코드로 저장되어 있을 수도 있고, 배열 속의 간단한 데이터 항목이거나 파일 안의 문자, 
트리의 노드, 그래프의 정점과 간선 혹은 다른 검색 공간의 항목일 수 있다.

검색 과정을 향상시키기 위해 데이터를 정리하는 방법들이 존재한다
데이터를 특정한 순서로 저장하면 필요한 항목을 찾기가 쉬어짐 -> 정렬은 항목들을 순서 있게 하는 기법 중 하나

검색의 종류들

무순서 선형 검색 (Unordered Linear Search)						: 정렬 안되어있는거 일일히 하나씩 찾기
정렬/순서 선형 검색 (Sorted/Ordered Linear Search)				: 정렬 다 되어있는데도 불구하고 linear로 찾기
이진 검색 (Binary Search)										: 정렬 다 되어있으니까 좀 똑똑하게 찾기 timecomplexity O(log n)
심볼 테이블 (Symbol Table) 과 해싱(Hashing)						: 해싱 O(1)
문자열 검색 알고리즘 : 트라이(Trie), 삼진 검색 (Ternary Search)와 접미 트리 (Suffix Tree)
*/

// 항목들의 순서가 알려지지 않은 배열이 주어졌을때(정렬X) : 특정 항목 검색하려면 전체 배열을 스캔해서 항목이 있는지 여부확인
// 시간복잡도 : 최악의 경우에 전체 배열을 스캔 O(n)					공간복잡도 : O(1) 별도의 공간 int i 때문
int UnsortedLinearSearch(int A[], int n, int data) {
	for (int i = 0; i < n; i++) {
		if (A[] == data)return i;
	}
	return -1;
}

// 배열의 항목들이 이미 정렬되어있다면 항목이 배열 안에 있는지 여부 확인 위해서 전체배열 스캔할 필요 X
// 아래 코드 A[i]의 값이 찾으려는 data보다 크다면 나머지 배열을 검색할 필요없이 -1리턴
// 시간복잡도 : 최악의 경우에 전체 배열을 스캔 O(n)	, 평균경우에 성장률은 감소 O(n/2)식으로->still O(n)			
// 공간복잡도 : O(1) 별도의 공간 int i 때문
int SoredLinearSearch(int A[], int n, int data) {
	for (int i = 0; i < n; i++) {
		if (A[i] == data) 
			return i;
		else if (A[i] > data) 
			return -1;
	}
	return -1;
}

// Binary Search
// 사전에서 단어찾기 : 찾으려는 페이지가 선택할 페이지보다 앞이면 앞쪽 절반만 반복 -> Binary Search Algorithm
// - 반복적인 이진 검색 알고리즘
int BinarySearchIterative(int A[], int n, int data) {
	int low = 0;
	int high = n - 1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (A[mid] == data)
			return mid;
		else if (A[mid] < data)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

// - 재귀적인 이진 검색 알고리즘
int BinarySearchRecursive(int A[], int low, int high, int data) {
	if (low > high) return -1;
	int mid = (low + high) / 2;
	if (A[mid] == data)
		return mid;
	else if (A[mid] < data)
		return BinarySearchRecursive(A, mid + 1, high, data);
	else
		return BinarySearchRecursive(A, low, mid - 1, data);
}






/* Hashing 해싱
실제적용에서 균형이진트리의 삽입삭제검색처럼 O(log n) 시간 걸리는 것들을 O(1) 시간안에 해결해야할때에 해싱을 사용
최악time: O(n) 이지만 평균time : O(1)]

ex) 주어진 문자열에서 '처음으로 반복되는 글자'를 출력하는 알고리즘
	한 문자 붙잡고 처음부터 끝까지, 다음 문자 붙잡고 처음부터 끝까지 ... => O(n제곱) time 공간은 O(1)

	해법 : 글자들을 어떤 배열에 저장해서 첫번째로 반복되는 글자를 찾아보자

	가능한 글자의 개수 256 (단순함을 위해 ascii 만 고려)
	크기가 256인배열 뚫고 모든 항목 0 초기화,	각 입력 글자를 읽을 때마다 해당하는 위치의 카운터 증가
	배열을 사용하므로 어느 위치를 찾든지 상수 시간 소요
	입력을 스캔하면서 카운터가 이미 1인 글자를 찾으면 이 글자가 처음으로 반복되는 글자라는 것을 뜻함
*/
char FirstRepeatedChar(char * str) {
	int i, len = strlen(str);
	int count[256];	// 부가적인 배열
	for (i = 0; i < 256; i++) 
		count[i] = 0;
	for (i = 0; i < len; i++) {
		if (count[str[i]] == 1) {
			printf("%c", str[i]);
			break;
		}
		else
			count[str[i]]++;
	}
	if (i == len)
		printf("No Repeated Characters");
	return 0;
}
//위 코드는 배열 크기를 256으로 고정했는데 그건 미리 알아서 가능한거고
//주어진 배열이 글자가 아니라 '숫자들' 이면? 
// 이 경우에 가능한 키의 집합은 무한하다고 봐야함 ( 숫자들이 엄청 큰 수까지 나올수 있으니까 , 범위가 없어진다고 봐도 무방)
// => 거대한 배열을 만들어서 카운터를 저장하는것은  불가능하다
// 이 문제를 풀려면 이 가능한 모든 키를 가능한 메모리 위치에 어떤 식으로든 '매핑'해야함
// 저장 가능한 키가 매우 많은 상황에서 배열사용은 XXXXXXXXXXXX 
// => 이 경우에 해싱 사용. 다수의 키를 적절한 장소에 매핑하는 과정 = 해싱
// 해싱의 주요 구성요소들		1) 해시 테이블	2) 해시 함수		3) 충돌Collision		4) 충돌 해결 기법

/* 해시 테이블

배열에서는 키가 k인 항목을 배열의 k위치에 저장
주어진 키 k에 대해, 해당 항목을 배열의 k번째 위치를 통해 찾기 => Direct Addressing
Direct Addressing 은 모든 가능한 키에 대해 하나의 장소를 할당할 수 있을 때에 사용.

키들의 범위가 내가 가질 수 있는 배열의 범위를 훨씬 뛰어넘을 정도로 크면 ( 굉장히 많은 키가 있을때 )-> Hashing 써야하는거고
 => 이때 가능한 방법 '해시 테이블 ' 사용 // 실제 저장되는 키의 개수가 가능한 키의 모든 개수에 비해 상당히 적을 때 사용
 U : universal set of all possible keys		// 전체집합
 K : set of keys actually used				// 사용되는 키들의 한 세트
 |U| >> |K|
 We use a hash function to compute the slot form the key k
 h maps the universal set of key into slot of hash table

 hash table :  실제 배열 대신에 가지고 있는 작은 데이타 저장소
*/