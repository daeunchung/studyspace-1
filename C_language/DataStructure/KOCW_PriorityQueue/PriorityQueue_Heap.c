#include <stdio.h>
#include <stdlib.h>

/* Priority Queue : 정해진 우선순위에 따라 작업 스케줄링 처리

우선순위 큐 ADT 가 제공하는 연산들 : 
Insert DeleteMin DeleteMax ..등등
기존 일반 큐에서의 Enqueue Dequeue 연산과 유사하지만, 항목들이 추가&처리되는 순서가 다를 수 있다

Ascending Priority Queue 
작은 키값을 갖는 항목일수록 높은 우선순위를 갖는 ( 항상 제일 작은 항목을 삭제하는 ) 오름차순 프라이오리티 큐
Descending Priority Queue
큰 키값을 갖는 항목일수록 높은 우선순위를 갖는 ( 항상 제일 큰 항목을 삭제하는 ) 내림차순 프라이오리티 큐
*/

/*
Binary Heap
일반적으로 Node가 아닌 Array 로 만든다. 포인터필요 X, 메모리 사용량이 적다\
힙이란 몇가지 특수한 속성을 가진 트리
노드의 값이 그 자식의 노드의 값보다 <= 혹은 <= 한다는 것이 힙의 속성
트리의 높이 h>0 일때 모든 리프 노드들이 h혹은 h-1레벨에 있어야 한다 (완전이진트리 이어야 한다)

힙은 자식이 2개짜리인 binary heap 만 거의 쓴다고 보면된다
배열을 사용해서 나타낸다. 포인터X
*/
struct Heap {
	int * array;
	int count;		// 힙 안의 항목 개수
	int capacity;	// 힙의 용량
	int heap_type;	// 최소 힙인지 최대 힙인지
};


// 시간복잡도 O(1) : loop 이 없으니
struct Heap* CreateHeap(int capacity, int heap_type) {
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	if (h == NULL) {
		printf("Memory Error");
		return;
	}
	h->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;
	h->array = (int*)malloc(sizeof(int) * h->capacity);
	if (h->array == NULL) {
		printf("Memory Error");
		return;
	}
	return h;
}

// 노드의 부모         // 시간복잡도 O(n)
int Parent(struct Heap* h, int i) {
	if (i <= 0 || i >= h->count)
		return -1;

	return (i - 1) / 2;
}

// 노드의 자식들						// 둘다 시간복잡도 O(1)
int LeftChild(struct Heap* h, int i) {
	int left = 2 * i + 1;
	if (left >= h->count) return -1;
	return left;
}
int RightChild(struct Heap* h, int i) {
	int right = 2 * i + 2;
	if (right >= h->count) return -1;
	return right;
}

// 최대 항목 구하기					// 시간복잡도 O(1)
// 최대 힙에서 최대 항목은 항상 루트에 있으므로 
int GetMaximum(struct Heap * h) {
	if (h->count == 0)
		return -1;
	return h->array[0];
}

/*
항목을 힙으로 만들기 ( 특정 노드가 heap 특성을 만족하도록 하기 )
힙에 항목을 새로 추가하고 나면 더 이상 힙 속성을 만족하지 않을 수 있다.
이 경우에 힙 안의 위치를 조정하여 다시 힙으로 만들어야 할 필요가 있다.
이 과정을 힙으로 만들기 Heapifying 이라고 한다.
Max Heap 의 경우 : 최대 힙에서 항목을 힙으로 만들려면 
				  그 자식 노드들의 최대값을 찾아 현재 항목과 바꿔치기를 한 뒤 
				  이 과정을 모든 노드가 힙 속성을 만족할 때까지 계속해야 한다.
*/

// Heapifying : PercolateDown ( i위치의 항목을 힙으로 만들기 )
// 시간복잡도  :	O(log n) 완전이진 트리이므로 최악의 경우에 루트에서 시작해서 리프까지 내려가는 완전 이진 트리의 높이와 같다
// 공간복잡도  : O(1)
void PercolateDown(struct Heap* h, int i) {
	int l, r, max, temp;
	l = LeftChild(h, i);
	r = RightChild(h, i);

	if (l != -1 && h->array[l] > h->array[i])	max = l;
	else max = i;

	if (r != -1 && h->array[r] > h->array[max])	max = r;
	if (max != i) {
		// h->array[i]와 h->array[max] 바꿔치기하기
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		PercolateDown(h, max);
	}
}

/*
항목 삭제하기 : 힙에서 항목삭제하려면 루트에서 항목을 삭제하기만 하면된다
	이것이 표준 힙에서 지원되는 유일한 연산 (최대 항목)
	루트 항목을 삭제한 뒤, 힙(트리)의 마지막 항목을 복사하고 이 마지막 항목을 삭제한다.
	그런데 마지막 항목을 교체하고 나면 트리는 힙 속성을 만족시키지 못할 수도 있다
	다시 힙으로 만들려면 PercolateDown 함수를 호출해야함
		- 첫번째 항목을 어떤 변수에 복사한다
		- 마지막 항목을 첫번째 항목의 위치에 복사한다
		- 첫번째 항목에서 PercolateDown 을 호출한다.

시간복잡도 : O(log n)	// 흘러내리기를 사용
*/

int DeleteMax(struct Heap * h) {
	int data;
	if (h->count == 0)
		return -1;
	data = h->array[0];
	h->array[0] = h->array[h->count-1];
	h->count--;	// 힙 크기를 줄인다
	PercolateDown(h, 0);
	return data;
}



/*
항목 삽입하기 : 힙크기늘린다, 새 항목을 힙(트리)끝에 위치시킨다, 
			   그 항목에 대해 밑에서 위(루트)로 힙으로만들기 수행

			   가장 아래쪽에 삽입된 노드를 제자리(윗쪽) 으로 올려주기위해 홀러올리기 PercolateUp 사용
시간복잡도 : O(log n)	힙으로 만들기 함수와 똑같이
*/
int Insert(struct Heap * h, int data) {
	int i;
	if (h->count == h->capacity)					// 용량이 부족하면 resize
		ResizeHeap(h);
	h->count++;										// 새 항목을 저장하기 위해 힙의 크기를 증가시킨다.
	i = h->count - 1;
	while (i > 0 && data > h->array[(i - 1)/2]) {	// 루트까지 가거나, 부모array[(i-1)/2] 보다 작으면 멈춤
		h->array[i] = h->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->array[i] = data; 
}

void ResizeHeap(struct Heap * h) {
	int* array_old = h->array;
	h->array = (int*)malloc(sizeof(int) * h->capacity * 2);
					// realloc 써주면 밑에 코드가 한줄안에 모두 처리됨
	if (h->array == NULL) {
		printf("Memory Error");
		return;
	}
	for (int i = 0; i < h->capacity; i++) 
		h->array[i] = array_old[i];

	h->capacity *= 2;
	free(array_old);
}

void DestroyHeap(struct Heap* h) {
	if (h == NULL)
		return;
	free(h->array);
	free(h);
	h = NULL;		// 의미없는 코드 여기에서 말고 바깥쪽에서 NULL로 만들어줘야지
}


/*SORT 란 ?
	큰 순서 또는 작은 순서대로 정렬하는것  
	가장 멍청하게 O(n제곱)  for(int i = 0; i<count; i++){for(int j = i; j<count; j++){
							ex) 이중for문있잖아... 이게 제일 무식한 정렬법인거고
HeapSort 를 이용한 정렬은?
	PercolateUp 은 시간복잡도 O(log n) 이니까 이것을 n번 수행해주면
	O(nlog n) 이라는 상당히 훌륭한 시간복잡도로 정렬이 가능하다는 뜻
*/

/*
정렬되지 않은 배열을 힙으로 만들기

힙을 만드는 간단한 방법 하나는 n개의 항목을 입력 받아 이들을 빈 힙에 위치시키는 것이다.
이는 n번의 연속적인 삽입연산으로 수행될 수 있으며 최악의 경우에 O(nlog n)이 걸린다.
각각의 삽입 연산에 O(log n)이 필요하기 때문이다.

리프노드는 항상 힙 속성을 만족 -> PercolateDown 고려할 필요 X
리프항목들은 항상 마지막에 위치하므로 주어진 배열을 힙으로 만들려면 리프가 아닌 노드들만 힙으로 만들면 된다.
이제 리프가 아닌 가장 처음 노드를 찾는데 집중하자.
힙의 마지막 항목은 h->count-1 에 위치하므로 , 
리프가 아닌 가장 처음 노드는 이 마지막 항목의 부모 노드를 찾아서 발견할 수 있다.
*/


/* 배열을 힙으로 만들기
	 시간복잡도 : 힙을 만드는 선형적시간의 계(bound)는 모든 노드의 높이 합을 계산하여 알 수 있다.
	 높이가 h인 완전 이진 트리에는 n - 2(h+1승) - 1 개의 노드가 있고, 
	 이 노드들의 높이의 합은 n-h-1 대략 n-logn-1 이다 (맞나틀리나다시한번체크해볼것)

	 즉, 힙을 만드 레벨 순서로 PercolateDown 함수를 적용해서 선형 시간 O(n) 에 이루어진다.

*/
void BuildHeap(struct Heap * h, int A[], int n) {
	if (h == NULL)
		return;		// 힙이 널이면 CreateHeap하면 될텐데..  아무것도 안하고 return 하라는거 보면 이 함수 밖에서 힙을 만들어서 가지고 들어오는듯
	while (n > h->capacity)		// 내가 받은 n보다 힙의 용량이 작으면 A[] 다 담을 수 있을때 까지 용량*2 반복으로 늘리기
		ResizeHeap(h);
	for (int i = 0; i < n; i++) {	// 아직 heap은 아닌 상태고 일단 배열에 내용모두 copy해주기
		h->array[i] = A[i];
	}
	h->count = n;					// count값 n으로 고정
	for (int i = (n - 1) / 2; i >= 0; i--) {	// i = (n-1)/2 일때가 가장마지막노드의 부모 ( = 뒤에서부터따질때 처음으로 leaf노드가 아닌 노드 ) 에서   ~   i = 0 (root노드) 까지
		PercolateDown(h, i);
	}
}







/*
힙 ADT 는 주로 정렬에 이용한다. (힙 정렬)
힙 정렬 알고리즘은 모든 항목을 (정렬되지 않은 배열로부터) 힙으로 만들어서 힙의 루트로부터 힙이 빌 때까지 항목들을 제거
힙 정렬은 정렬될 배열과 같은 장소에서 정렬이 이루어질 수 있다 ( 즉, output 배열 따로 이용X)
항복을 삭제하는 대신 첫 번재 항목 (제일 큰 항목) 과 마지막 항목을 교체하고 힙 크기(배열크기)를 감소
그런 다음 첫번째 항목을 기준으로 힙으로 만든다. 이 과정을 남은 항목이 한개일때까지 반복

시간복잡도 : 항목을 힙으로부터 삭제할 때마다 값이 정렬된다(최대항목이 언제나 루트에만 있기때문)
			삭제 알고리즘의 시간 복잡도가 O(log n)이므로, 힙 안의 항목의 수가 n일 때 
			힙 정렬 알고리즘의 시간 복잡도는 O(nlog n) 이다
*/
void HeapSort(int A[], int n) {
	struct Heap* h = CreateHeap(n);	// O(1)
	int old_size, i, temp;
	BuildHeap(h, A, n); // O(n)
	old_size = h->count;
	for (i = n - 1; i > 0; i--) {// for문 n번반복이니까 곱하기 n
		// h->array[0] 이 가장 큰 항목이다.
		temp = h->array[0];
		h->array[0] = h->array[h->count - 1];
		h->array[h->count - 1] = temp;
		h->count--;
		PercolateDown(h, 0); // O(log n)
	}						 // => O(nlog n)
	h->count = old_size;
}
// 최종 : O(1) + O(n) + O(nlog n) => O(nlog n)

















/*				최종정리 HeapSort time-complexity : O(nlog n)

Sort는 상당히 여러종류가 있는데 그 중에도 O(n제곱) 시간복잡도 가지는 sort 도 많은데 
HeapSort는 O(nlog n) 시간 복잡도 가지기에 매우 훌륭하다고 볼 수 있고 ( 둘이 차이가 상당히 크다)

Priority Queue : 들어온 순으로 꺼내는게 아니고 특정 우선순위 순서에 따라 꺼내는 큐

그러한 Priority Queue를 구현하기 위해서 Heap이라는 자료구조를 배운 것
그 Heap 을 Array(배열)로 구현할 수 있기에 상당히 편리했다는 것

그러다가 원래 Sorting 에서 배워야 할 HeapSorting 을 여기서 배웠다 이말씀임 *^^*

*/