#include <stdio.h>
#include <stdlib.h>
/* 그래프의 적용사례
전자회로에서 각 구성 요소들의 관계를 표현할 때
수송 네트워크 : 고속도로 네트워크, 항공 네트워크
컴퓨터 네트워크 : 근거리 네트워크, 인터넷, 웹
데이터 베이스 : 데이터베이스의 테이블 간의 의존 관계를 표현하는, 데이터베이스의 ER(개체관계) 다이어그램을 나타낼 때
*/

/*
그래프의 표현 
다른 ADT들과 비슷하게 그래프도 유용한 형태로 표현할 필요가 있다. 
- 인접 행렬 (Adjacency Matrix)
- 인접 리스트 (Adjacency List)
- 인접 집합 (Adjacency Set)

그래프가 조밀하다면 인접 행렬 표현이 유용
행렬은 O(V제곱) 비트의 공간과 O(V제곱)의 시간이 초기화를 위해 필요하다
간선의 개수가 V제곱에 비례하다면 문제가 없다.
왜냐하면 간선을 읽는데 V제곱 단계가 필요하기 때문이다
그래프가 희소하다면 행렬 초기화에 V제곱이 걸리고 , 이는 알고리즘 수행 시간의 대부분을 차지한다.
*/



// 인접 행렬을 위한 그래프 선언 (정점의 수와 간선의 수, 그들의 상호 연결성 필요)
/* 이 기법에서, 크기가 V X V 인 행렬을 사용한다. 행렬의 값은 불린(Boolean) 이다. 행렬이 Adj이라고 하자. 
정점 u로부터 v까지의 간선이 있을 때 Adj[u,v] 의 값은 1이되고 그렇지 않으면 0이된다.

행렬에서 무방향 그래프의 각 간선은 2비트. 즉 u에서 v까지의 간선은 Adj[u,v] 와 Adj[v,u]의 값이 1임으로 표현된다.
시간을 절약하기 위해, 이 대칭 행렬의 절반만 처리할 수 있다.

먼저 vertex를 읽어들이고 edge를 읽어들인다.
*/
struct Graph {
	int V;
	int E;
	int ** Adj	// 이차원 행렬이 필요하므로
};

// 아래 코드는 콘솔에서 입력하는 방식 ( 하나틀리면 처음부터 다시 ^^)
// 일반적으로는 데이터 정보를 파일에다가 넣고 넣고 파일을 읽어오는 방식으로 진행
struct Graph* adjMatrixOfGraph() {
	int i, u, v;
	struct Graph* G = (struct Graph*)malloc(sizeof(struct Graph));
	if (!G) {
		printf("Memory Error");
		return;
	}
	scanf("Number of Vertices : %d, Number of Edges : %d", &G->V, &G->E);
	G->Adj = (int**)malloc(sizeof(G->V * G->V));	// 그림으로 그린 2차원행렬( 1 0 표시할 곳 ) 만들어주기
	// -> 강의 ppt 코드 .. 이게 말이되는 건가?
	for (u = 0; u < G->V; u++) {
		for (v = 0; v < G->V; v++) {
			G->Adj[u][v] = 0;	// 이거 안돌아갈텐데 ppt 코드가 왜 저모양인건지?
		}
	}

	for (i = 0; i < G->E; i++) {	// E의 개수만큼 for문 돌아서 scanf 받아
		//간선을 읽는다
		scanf("Reading Edge : %d, %d", &u, &v);

		//무방향그래프에서는 양쪽비트를 모두 표기한다
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}



/* 그래프가 조밀하다면 인접 행렬 표현이 유용하다
행렬은 O(V제곱)비트의 공간과 O(V제곱)의 시간이 초기화를 위해 필요
간선의 개수가 V제곱에 비례하다면 문제가 없다
왜냐하면 간선을 읽는 데 V제곱단계가 필요하기 때문이다
그래프가 희소하다면 행렬 초기화에 V제곱이 걸리고, 이는 알고리즘 수행 시간의 대부분을 차지한다*/
/*이 표현은 좋을까 나쁠까 ? 고민하다가 나타난 또 다른 상대개념

(Adjacent List)
인접 리스트를 위한 그래프 선언
정점 v에 연결된 모든 정점이 정점 v를 위한 인접 리스트에 저장 : 이를 연결 리스트로 구현
각각의 정점 v에 대해 연결 리스트를 하나 사용하고, 여기에 v에 간선을 가지는 다른 점들의 연결 관계가 저장된다
연결리스트의 총 개수는 그래프의 정점의 개수와 같다
아래는 ADT 형태

인접 리스트는 입력되는 간선의 순서가 중요하다, 그 순서가 인접 리스트에서 정점의 순서도 결정하기 때문
인접 리스트에서는 같은 그래프가 여러가지 다른 방식으로 표현될 수 있다 ( 노드의 순서가 바뀔 수 있기 때문)
	-	단점
	인접 리스트를 사용할 때는 어떤 연산은 효율적으로 수행할 수 없다
	예를 들어 노드를 삭제하는 경우 : 
		인접 리스트 표현에서는 인접 리스트에서 노드삭제로 끝나는 것이 아니고
		다른 노드의 연결 리스트도 다 찾아야한다 (traverse하면서 )


*/
struct Graph {
	int V;
	int E;
	struct ListNode** Adj;  // 연결 리스트를 가리키는  head 포인터
};

struct Graph* adjListOfGraph() { // 이 코드는 인접리스트 표현으로부터 그래프를 생성한다
	int i, x, y;
	struct ListNode* temp;
	struct Graph* G = (struct Graph*)malloc(sizeof(struct Graph));
	if (!G) {
		printf("Memory Error");
		return;
	}
	scanf("Number of Vertices : %d, Number of Edges : %d", &G->V, &G->E);
	G->Adj = (int**)malloc(sizeof(struct ListNode*) * G->V);
	for (i = 0; i < G->V; i++) {
		G->Adj[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
		G->Adj[i]->vertexNumber = i;
		G->Adj[i]->next = G->Adj[i];
	}
	for (i = 0; i <G->E; i++) {	// 간선을읽는다
		scanf("Reading Edge : %d, %d", &x, &y);
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->vertexNumber = y;
		temp->next = G->Adj[x]->next;
		G->Adj[x]->next = temp;
		temp = (struct ListNode*)malloc(struct ListNode);
		temp->vertexNumber = y;
		temp->next = G->Adj[y]->next;
		G->Adj[y]->next = temp;
	}
	return G;
}



// 인접집합 (Adjaccent Set) 은 개념만 정리했고 코드는 다루지 않고 넘어감