/*
10.5 Bubble Sort 버블정렬 : 가장 간단한 정렬 알고리즘
첫번째 항목부터 마지막 항목까지 입력 배열을 반복하면서 각 항목 쌍을 비교하고 필요하면 그들을 교환하며 동작
버블 정렬은 더 이상 교환이 필요 없을 때까지 반복함
이 알고리즘은 작은 항목들이 리스트의 맨 위로 마치 '거품' 이 떠오르듯이 움직이는 모습에서 이름 유래
일반적으로 성능은 삽입정렬(Insertion Sort) >> 버블정렬
좋은점: 입력이 이미 정렬되었는지 여부를 알 수 있다
 => (최선의 경우에도) O(n제곱) 시간 걸린다
 하나의 추가적인 플래스 이용해서 알고리즘 향상 가능
 더 이상 쇼환이 없다 = 정렬 완료
*/
void BubbleSort(int A[], int n) {	// 오름차순 정렬
	for (int pass = n - 1; pass >= 0; pass--) {
		for (int i = 0; i < pass; i++) {
			if (A[i] > A[i + 1]){
				// 항목을 교환
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
			}
		}
	}

}

// 개선된 버전 버블 정렬
void BubbleSort(int A[], int n) {
	int pass, i, temp, swapped = 1;
	for (pass = n - 1; pass >= 0 && swapped; pass--) {
		swapped = 0;
		for (i = 0; i < pass; i++) {
			if (A[i] > A[i + 1]) {
				//
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				swapped = 1;
			}
		}
	}
	// 값교체 for문을 돈 후에 swapped 값이 0이면 정렬완료되었으니 끝 / 값이 1이면 또 for문들어가서 swap
}

/* Selection Sort (선택 정렬) : in-place(제자리) 정렬 알고리즘
( 선택 정렬은 작은 파일들에게 잘 동작한다, 매우 큰 값과 작은 키를 가진 파일들을 정렬하는 데 사용된다, 왜냐하면 선택은 키에 의해 이루어지고 필요할 때만 교환되기 때문이다)
장점		 : 구현이 쉽다, 제자리 정렬이다 (부가적인 저장 공간이 필요없다)
단점		 : 확장성이 좋지 않다 O(n제곱)
알고리즘	 : 1. 리스트에서 최소 값 찾기		2. 이 값을 현재 위치의 값과 교환		
		   3. 전체 배열이 정렬될 때까지 이 과정을 모든 황목에 대해 반복 
		   반복적으로 최소값을 선택하므로 선택 정렬이라고 부른다
=> (최선의 경우, 최악의 경우 모두 ) O(n제곱) 시간 걸린다

*/

void Selection(int A[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (A[j] < A[min])	min = j;
		}
		// 항목 교환 ( i보다 뒤에 인덱스 들인 j중에서 A[i]보다 크기 작은 A[j] 없으면 min == i 이니까 아래 교체가 안일어나는것과 동일)
		temp = A[min];
		A[min] = A[i];
		A[i] = temp;
	}
}
/* 삽입 정렬 (Insertion Sort) : 단순하고 효율적인 비교 정렬
입력 테이터로부터 한 항목을 제거해서 정렬 중인 리스트의 정확한 위치에 삽입 하기를 반복
	-> 제거 해서 라는 말 보다는 한놈을 떼어놓고 그 놈을 insert 받은놈이라고 생각하는거임
(입력부분부터 제거될 항목은 임의로 선택, 일반적으론 순서대로... 모든 입력 항목 처리될때까지 이 과정 반복)
장점 : 간단한 구현, 작은 데이터에 효율적, 최악의 경우는 O(n제곱) 복잡도, but 선택이나 버블보다 실무에 효율적
적응적 입력 리스트가 이미 정렬되었다면 (완전하지않더라고) 삽입 정렬은 d가 반전(Inversion)의 함수일때 O(n+d)의 시간
안정적 키가 같다면 입력의 상대적인 순서 유지
제자리 인정한 크기의 부가 메모리 공간 O(1)만 필요
온라인(online) 삽입 정렬 입력 리스틀르 받으면서 정렬 가능


*/
void InsertionSort(int A[], int n) {
	int i, j, v;
	for (i = 1; i < n - 1; i++) {
		v = A[i];
		j = i;
		while(j >= 1 && A[j - 1] > v ) {
			A[j] = A[j + 1];
			j--;
		}
		A[j] = v;
	}
}

/* Merge Sort 병합 정렬 : 메모리구조가 부가로 더 필요한 알고리즘 , Divide & Conquer 의 한 예이다
Divide & Conquer 방식을 사용 => 그 다음에 Combine
Divide는 보통 그냥 입력데이터를 절반으로 뚝 나눈다 ( 세부적으로 나누고 나누고 또 나누고 .. 가장 작을때 까지 나누고 합친다 )
Divide : the problem into a number of subproblems
Conquer : the subproblems by solving them recursively. If the subproblem sizes are small enough, 
		  just solve the subproblems in a straightward maner.
Combine : the solutions to the subproblems into the solution for the original problem.

Merge : 두 개의 정렬된 파일을 합쳐서 하나의 큰 정렬된 파일을 만드는 과정
Divide : 파일을 두 부분 k개의 항목들과 n-k개의 항목들로 나누는 과정
이 알고리즘은 연결 리스트의 정렬에 주로 사용된다
Merge Sort는 입력의 초기 정렬 상태에 무관 한다

Quick Sort에서는 대부분의 작업이 재귀 호출 이전에 수행된다
	퀵 정렬은 큰 파일에서 시작해서 작은 파일에서 끝난다 => 안정적이지 않다
반면 Merger Sort는 리스트를 두 부분으로 나눈다.
	그 다음에 두 부분이 각각 처리된다. 그리고 합쳐진다.
	Merge Sort는 작은 파일에서 시작해서 큰 파일에서 끝나고, 안정적인 알고리즘이다.
*/

void Mergesort(int A[], int temp[], int left, int right) {	// temp : 연습장
	int mid;
	if (right > left) {
		mid = (right + left) / 2;
		Mergesort(A, temp, left, mid);
		Mergesort(A, temp, mid+1, right);
		Merge(A, temp, left, mid + 1, right);
	}
}


void Merge(int A[], int temp[], int left, int mid, int right) {	// Merge의 시간복잡도 O(n)time
	int i, left_end, size, temp_pos;
	left_end = mid - 1;
	temp_pos = left;
	size = right - left + 1;

	while (left <= left_end && mid <= right) {

		// 왼쪽과 오른쪽을 작은숫자 순으로 temp에 복사하는 일을 수행
		if (A[left] <= A[mid]) {
			temp[temp_pos] = A[left];	// 크기 작은놈을 copy
			temp_pos = temp_pos + 1;	// temp 위치 한칸 오른쪽으로 이동
			left = left + 1;			// 크기 작은놈 copy 로 이미 정렬되었으니 다음 놈으로 옮겨주기
		}
		else if (A[left] > A[mid]) {
			temp[temp_pos] = A[mid];	// 크기 작은놈을 copy
			temp_pos = temp_pos + 1;	// temp 위치 한칸 오른쪽으로 이동
			mid = mid + 1;			// 크기 작은놈 copy 로 이미 정렬되었으니 다음 놈으로 옮겨주기
		}
	}

	while (left <= left_end) {	// left 쪽이 남아있다면
		temp[temp_pos] = A[left];
		left = left + 1;
		temp_pos = temp_pos + 1;
	}
	while (mid <= right) {	// right 쪽이 남아있다면
		temp[temp_pos] = A[mid];
		mid = mid + 1;
		temp_pos = temp_pos + 1;

	}
	for(i = 0; i<= size; i++){	// temp[] 에서 A[]로 다시 copy		
		A[right] = temp[right];
		right--;
	}
}


/* Heap Sort 비교에 기반한 정렬 알고리즘 -> 배열에서 select : selection sort / 힙에서 select : heap sort
1) 정렬되지않은 배열을 힙으로 만들기 = O(n)
2) 그 힙에서 차례로 Max부터 수 꺼내기 = O(nlog n)
	O(n) + O(nlog n) => O(nlog n)
최악최선평균 : O(nlog n)
최악의 경우 공간 복잡도 : 전체O(n) 부가공간O(1)
*/

// 앞에서 했으니 코드는 앞에서 찾아보기



/* Quick Sort : divide-conquer 알고리즘 기법의 한 예
재귀 호출을 사용해서 항목들을 정렬
비교에 기반한 정렬 알고리즘 중에서 유명한 알고리즘
Divide: 
배열 A[low..high]는 빈 배열이 아닌 두 개의 부속 배열 A[low...q-1] 와 A[q+1...high]로 나뉜다.
A[q]는 pivot 값이고  A[low...q-1]에는 피봇값보다 작은 수들 A[q+1...high]에는 피봇값보다 큰 수들 
Conquer : 
두 개의 부속 배열  A[low...q-1] 와 A[q+1...high]가 퀵소트 재귀 호출로 정렬

재귀 알고리즘은 4단계 가진다
1) 배열 안에 정렬할 항목이 1개이거나 없다면 리턴
2) 배열 안의 한 항목을 pivot(기준)으로 선택 (보통은 배열의 제일 왼쪽 항목이용)
3) 배열을 pivot 보다 작은 항목들과 큰 항목인 두 부분으로 정리해서 나눈다
4) 원본 배열의 두 반쪽에 대해 알고리즘을 재귀적으로 반복

최선, 평균의 경우 : O(nlog n), 최악의 경우 : O(n제곱)

*/
void QuickSort(int A[], int low, int high) {
	int pivot;
	if (high > low) {
		pivot = Partition(A, low, high);	// 아래에서 반환한 right ( 피봇의 새로운 위치인덱스를 피봇변수에 넣어주고 그 앞칸들과 그 뒷칸들 로 재귀 퀵소트 실행 )
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot+1, high);
	}
}

int Partition(int A[], int low, int high) {
	int left, right, pivot_item = A[low];
	left = low;
	right = high;

	while (left < right) {
		/*item <= pivot인 동안 왼쪽으로 옮긴다*/
		while (left < right && A[left] <= pivot_item)
			left++;
		/*item > pivot인 동안 오른쪽으로 옮긴다*/
		while (left < right && A [right] > pivot_item)
			right--;
		if (left < right)
			swap(A, left, right);
	}
	/*right 가 마지막 pivot의 위치이다*/
	A[low] = A[right];
	A[right] = pivot_item;
	return right;
}

/* Randomized Quick Sort 
평균 경우에 입력 숫자들 균등되게 분포했다고 가정했으나 항상 그럴수는 없기에, 최악의 경우 만날 확률 낮추려고 Randomized algorhthm에 추가
*	적용 방법
1) 입력 데이터를 배열 안에 무작위로 배치
2) 입력 데이터에서 무작위로 pivot 선택 : 무작위 선택했기에 입력배열의 partitioning 이 평균적으로 균형있게 이루어질 것을 기대하기 어렵다
									   균형 잡히지 않은 partitioning 의 경우, 생기는 최악의 경우 피할 수 있음
 Randomized Quick Sort 이 최악의 경우 복잡도를 개선함에도 , 최악의 경우 복잡도는 여전히 O(n제곱)
 항목을 무작위로 선택하는 것보다 더 주의깊게 pivot 선택하기 방법
 ex) 배열에서 무작위로 선택된 3개의 항목의 중간 값을 pivot으로 삼는 것이다.
*/







// { G R A P H }

/* Shortest Path Algorithms 최단 경로 알고리즘 
그래프 G = (V, E) 와 정점 s가 주어졌을때, s로부터 G안의 모든 정점에 이르는 최단 경로를 찾는 문제

주어진 그래프의 종류에 따라 다음과 같은 다양한 최단 경로 알고리즘 있을 수 있다
	비가중치 그래프의 최단 경로
	가중치 그래프의 최단 경로
	음수 간선이 있는 가중치 그래프의 최단 경로

최단 경로 알고리즘의 적용사례
	한 장소에서 다른 장소로 가장 빨리 가는 길 찾기
	한 도시로부터 다른 도시로 가장 싸게 비행/데이터를 보내는 방법 찾기

Unweighted graph 의 shortest path 
아래에 한줄만 유사코드로 표시한 코드 : 인접 리스트, 인접 행렬 중 무엇을 사용하냐에 따라 시간복잡도가 많이 달라지기 때문
	인접리스트 사용시 : O(|E|+|V|) // E와 V중 무엇이 더 클지 몰라서 둘다 쓴거임 
	for루프에서 주어진 정점으로부터 나가는 간선을 검사하고 
	while루프 안에서 검사된 모든 간선의 합은 간선의 수과 같으므로 O(|E|)가 된다

	인접행렬 사용시 : O(|V|제곱)
	왜냐하면 주어진 정점에 인접한 정점을 찾으려면 길이가 |V|인 행렬의 한 행 전체를 읽어야 하기 때문


Weighted graph 의 shortest path ( Dijkstra Algorithms )
* 유명한 최단 경로 문제 해법은 다익스트라에 의해 소개되었다
	다익스트라의 알고리즘은 BFS알고리즘을 일반화 (weighted graph)한 것이다
	보통의 BFS알고리즘은 큐의 가장 앞에 있는 정점이 시작점 s와 제일 가까운 점이라는 것을
	보장할 수 없기 때문에 최단 경로 문제를 풀 수 없다
* 알고리즘 동작 방법
	Unweighted graph의 shortest path algoritm과 비슷하게 distance table 사용
	이 알고리즘은 시작점으로 부터 정접 v와 최단 거리를 distance table에 저장하면서 동장
	Distance[v]의 값은 s로부터 v까지의 거리이다
	시작점으로부터 자신에 이르는 최단 거리는 0이다
	Distance table의 다른 모든 정점은 -1이 저장되어 이 정점들이 아직 처리되지 않았음을 나타낸다
* 알고리즘 수행이 끝나면 distance table 은 시작점 s로부터 각 정점 v에 이르는 최단 거리들을 보유한다.
	다익스트라 알고리즘의 동작을 살펴보기 전에, 주어진 정점들이 두 집합으로 관리된다고 가정하자
	가장 처음 첫 번째 집합에는 시작 정점만이 있고, 두 번째 집합에는 다른 모든 정점이 있다. 
	k번째 반복 뒤에, 첫번째 집합은 시작점과 제일 가까운 k개의 정점들을 가지고 있게 된다.
	이 집합의 k개의 정점들이 정점으로부터 최단 거리를 이미 계산한 정점들이다.
* 다익스트라 알고리즘 참고 사항
	그리디 기법 (Greedy) 사용 
	항상 시작점으로부터 가까운 정점 선택
	Priority Queue를 사용해서 방문하지 않은 정점들을 s로부터의 거리에 따라 저장
	음수 가중치를 가지고는 사용할 수 없다.


* 비가중치 최단경로 VS 다익스트라 알고리즘	(가중치 최단경로) 	차 이 점 !!! : 아래는 다익스트라 설명
	1) 인접 리스트에서 가중치를 표현하기 위해, 각 정점은 간선의 가중치를 가지고 있다
	2) 일반적인 큐 대신에 (거리를 우선순위로 하여 ) priority queue를 사용하고, 거리가 짧은 정점이 선택되어 처리된다
	3) 정점까지의 거리는 시작점으로부터 그 정점까지의 경로에 있는 간선들의 가중치 합으로 계산된다 (edge에있는 weight들의 합)
	4) 새로 계산된 거리가 이미 계산한 이전 거리보다 짧은 경우에 대비해서 거리들을 업데이트한다.
	( 이전에 계산한 거리값이 현재 계산한 거리값보다 클 수가 있기 때문에 항상 거리 계산 후에 예전 답과 비교해서
		더 작은 값을 채택 해야함 )
*/

void UnweightedShortestPath(struct Graph* G, int s) {
	struct Queue* Q = CreateQueue();
	int v, w;
	EnQueue(Q, s);
	for (int i = 0; i < G->Q; i++)
		Distance[i] = -1;
	Distance[s] = 0;

	while (!IsEmptyQueue(Q))
	{
		v = DeQueue(Q);				// 큐에서 한개 꺼내주기
		for v에 인접한 모든 정점 w에{	// 각 정점은 최대 한 번 검사된다. -------> 한줄만 유사코드로?
			if (Distance[w] == -1) {
				Distance[w] = Distance[v] + 1;
				Path[w] = v;
				EnQueue(Q, W);
			}
		}
	}
	DeleteQueue(Q);
}

/*
Weighted graph 의 shortest path(Dijkstra Algorithms)

* 유명한 최단 경로 문제 해법은 다익스트라에 의해 소개되었다
	다익스트라의 알고리즘은 BFS알고리즘을 일반화(weighted graph)한 것이다
	보통의 BFS알고리즘은 큐의 가장 앞에 있는 정점이 시작점 s와 제일 가까운 점이라는 것을
	보장할 수 없기 때문에 최단 경로 문제를 풀 수 없다
* 알고리즘 동작 방법
	Unweighted graph의 shortest path algoritm과 비슷하게 distance table 사용
	이 알고리즘은 시작점으로 부터 정접 v와 최단 거리를 distance table에 저장하면서 동장
	Distance[v]의 값은 s로부터 v까지의 거리이다
	시작점으로부터 자신에 이르는 최단 거리는 0이다
	Distance table의 다른 모든 정점은 - 1이 저장되어 이 정점들이 아직 처리되지 않았음을 나타낸다
* 알고리즘 수행이 끝나면 distance table 은 시작점 s로부터 각 정점 v에 이르는 최단 거리들을 보유한다.
	다익스트라 알고리즘의 동작을 살펴보기 전에, 주어진 정점들이 두 집합으로 관리된다고 가정하자
	가장 처음 첫 번째 집합에는 시작 정점만이 있고, 두 번째 집합에는 다른 모든 정점이 있다.
	k번째 반복 뒤에, 첫번째 집합은 시작점과 제일 가까운 k개의 정점들을 가지고 있게 된다.
	이 집합의 k개의 정점들이 정점으로부터 최단 거리를 이미 계산한 정점들이다.
* 다익스트라 알고리즘 참고 사항
	그리디 기법(Greedy) 사용
	항상 시작점으로부터 가까운 정점 선택
	Priority Queue를 사용해서 방문하지 않은 정점들을 s로부터의 거리에 따라 저장
	음수 가중치를 가지고는 사용할 수 없다.
* 성능
	다익스트라 알고리즘에서 효율성은 DeleteMin이 수행된 숫자 (V번의 DeleteMin)와
	사용된 우선순위 큐의 업테이트 횟수(최대 E번의 Update)에 달려 있다.
	(아래 코드의 첫 for문, 두번째 while문과 그 안의 for문이 실행되는 과정을 잘 고려해볼 것)

	Priority Queue 이용시 : O(|E| + |E|log|E|) = O(|E|log|E|)
	Binary heap을 집합으로 사용시 : O(VlogV + ElogV)이다. 정확한 값 비교 불가능해서 더 축약 불가능
		ElogV는 Binary heap의 E번의 업데이트(각 업데이트는 logV가 걸림)로부터 나오는 값
	배열을 집합으로 사용시 : O(V제곱 + E) = O(V제곱) 
		E의 최댓값이 V제곱이기에 간략화 가능
* 단점
	음수 간선 처리 불가능 => Bellman-Ford algorithm

* 비가중치 최단경로 VS 다익스트라 알고리즘(가중치 최단경로) 	차 이 점 !!!: 아래는 다익스트라 설명
1) 인접 리스트에서 가중치를 표현하기 위해, 각 정점은 간선의 가중치를 가지고 있다
2) 일반적인 큐 대신에(거리를 우선순위로 하여) priority queue를 사용하고, 거리가 짧은 정점이 선택되어 처리된다
3) 정점까지의 거리는 시작점으로부터 그 정점까지의 경로에 있는 간선들의 가중치 합으로 계산된다(edge에있는 weight들의 합)
4) 새로 계산된 거리가 이미 계산한 이전 거리보다 짧은 경우에 대비해서 거리들을 업데이트한다.
(이전에 계산한 거리값이 현재 계산한 거리값보다 클 수가 있기 때문에 항상 거리 계산 후에 예전 답과 비교해서
더 작은 값을 채택 해야함)
*/
void Dijkstra(struct Graph * G, int s) {
	struct PriorityQueue * PQ = CreateQueue();
	int v, w;
	EnQueue();
	for (int i = 0; i < G->V; i++)
		Distance[i] = -1;
	Distance[s] = 0;
	while (!IsEmptyQueue(PQ)) {
		v = DeleteMin(PQ);
		for (v의 모든 인접한 정점 w에 대해) {
			d = Distance[v] + weight[v][w];		// 새로운 d값 = 출발정점 v의 Distance값 + v->인접노드w 로의 가중치값
			if (Distance[w] == -1) {			// 아무도 건들지 않은 새거니까 이번에 넣어주기
				Distance[w] = d;				// 새로운 거리 넣기
				Insert(PQ, w, d);				// w를 우선순위 d로 우선순위 큐에 넣음
				Path[w] = v;					// w로 오는 경로는 v로부터이다 ( v->w 라는거 알려주기)

			}
			else if (Distance[w] > d) {			// 지난 dis보다 이번 dis가 더 짧으니까
				Distance[w] = d;				// 새로운 거리 넣기
				Update(PQ, w, d);				// w의 우선순위가 d가 되도록 업데이트
				Path[w] = v;					// w로 오는 경로는 v로부터이다 ( v->w 라는거 알려주기)
			}
		}
	}

}


/*	Minimum(Minimal) Spanning Trees 
어떤 그래프의 spanning tree 신장트리 는 모든 정점을 포함하고 있는 sub-graph 이면서 또한 tree이다.
한 그래프에서 여러 spanning tree가 있을 수 있다
	=> 여러 트리들 중에 weight들의 합의 값이 가장 작은 것을 minimum spanning tree

Undirected graph의 MST
주어진 그래프가 weighted graph라고 가정
Undirected graph G의 MST는 최소 비용(가중치)합계를 갖도록 
G의 모든 정점을 연결하는 그래프가 연결되어 구성된 트리이다.
MST는 그래프가 연결되어 있을 때만 존재한다
문제해결시 사용되는 유명 알고리즘 2가지   
1) Kruskal(크루스칼)알고리즘		2) Prim(프림)알고리즘

*/

/*
1) Kruskal(크루스칼)알고리즘		
이 알고리즘은 V의 서로 다른 트리로 시작한다 (V는 그래프의 정점들이다)
 MST를 만드는 동안 매번 최소weight를 가진 edge를 선택해서 그 edge가 사이클을 만들지 않으면 트리에 추가
																사이클을 만들면 탈락 버려
 그러므로, 처음에는 |V|개의 노드가 각각 트리로써, forest안에 있을 것이다
 이때 edge을 하나 추가하면 두 개의 트리가 하나로 합쳐진다
 알고리즘이 종료하면, 오직 하나의 트리만 남는데, 이것이 mst
	구현방법 1) Disjoint set의 UNION과 FIND 연산 사용
			(Forest를 구현하는데) 적절한 데이터 구조는 UNION/FIND 알고리즘이다
			2) Priority queue를 사용해 weight를 priority queue 안에 유지
	가장 처음에 각 정점은 자신만의 집합 안에 있다
	두 정점은 그들이 현재의 forest 안에서 연결되어 있을 때에만 같은 집합에 속한다
	만약 u와 v가 이미 같은 집합 안에 있다면, edge(u,v)는 사이클을 만들기 때문에 spanning tree에 넣을 수 없다
	그렇지 않다면, (최소weight를 갖는) 그 edge가 채택되고, u와 v를 갖고 있는 두 집합에 대해	UNION이 수행된다

// 최악의 경우 수행 시간은 주로 heap연산에 의해 영향을 받는 O(ElogE) 이다
// E간선들을 가지고 heap을 만들기 때문에 O(ElogE)시간이 필요
*/
void kruskal(struct Graph * G) {
	S = 공집합;	//처음에 그냥 뚫어놓는 공집합. 맨 마지막에 S에는 minimum spanning tree의 edge들이 저장된다
	for (int v = 0; v < G->V; v++) {
		MakeSet(v);	// 정점의 수만큼 별도의 집합 만들어주기
	}
	E의 간선들을 가중치 w가 증가하는 순서로 정렬한다
	for E안의 모든 간선(u, v)에 대해 {	// 정렬된 리스트로부터
		if (FIND(u) != FIND(v)) {		// 정점 u와 v가 속하는 집합이 다르면
			S = S 합집합 {(u,v)}			// 기존의 집합에 u-v 간선을 추가
			UNION(u, v);
		}
	}
	return S;
}

/*
2) Prim(프림)알고리즘
프림 알고리즘은 다익스트라 알고리즘과 거의 같다
다익스트라의 알고리즘과 비슷하게 프림 알고리즘에서도 거리의 경로 값을 distance table 에 저장
다른 점 : 거리의 정의가 다르다. 경로가 distance table 업데이트 구문이 조금 다르다
For each vertex v, Distance[v] is the minimum weight of any edge connecting v
to a vertex in the current tree.

// Prim 의 전체 구현은 다익스트라 알고리즘과 동일
// 수행시간은 heap이 없을 때 ( dense한 그래프에 유리한) O(|V|제곱)이고,
// binary heap을 사용할 때 (sparse한 graph에 유리한) O(VlogV + ElogV) 이다.
*/
void Prim(struct Graph * G, int s) {
	struct Priority Queue * PQ = CreatePriorityQueue();
	int v, w;
	EnQueue(PQ, s);
	Distance[s] = 0;				// distance table이 -1로 채워져 있다고 가정
	while (!IsEmptyQueue(PQ)) {
		v = DeleteMin(PQ);

		for v의 모든 인접한 정점 w에 대해{
			//d = Distance[v] + weight[v][w];	// 땡 !!!! Prim에서는 Distance가 뜻하는 것이 다익스트라에서와는 다르다
			d = weight[v][w];					// Prim에서는 합 말고 그냥 간선의 weight값만 !

			if (Distance[w] == -1) {			
				Distance[w] = d;				
				Insert(PQ, w, d);				
				Path[w] = v;					

			}
			else if (Distance[w] > d) {		
				Distance[w] = d;				
				Update(PQ, w, d);			
				Path[w] = v;					 
			}
		}
	}
}



// 왜 어떤 알고리즘들은 자료구조과목에서, 어떤 알고리즘들은 알고리즘 과목에서 배울까?
// 구분 기준이 뭘까?
// 보통은 보편화되어서 상용되는 자료구조의 개념, 성능을 소개하고 그 자료구조들을 사용하기 위한 
// 기본적인 알고리즘들을 자료구조 과목에서 배우고
// 알고리즘 시간에는 문제 해결을 위한 알고리즘을 직접 짜고 이 복잡도가 정말 맞는지 입증하고
// 모든 상황에서도 이 알고리즘이 옳게 작동되는지 입증하고 증명하는 과정에 초점을 두어 배운다고 함