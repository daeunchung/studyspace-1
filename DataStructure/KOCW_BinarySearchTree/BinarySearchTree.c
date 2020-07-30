/*
BinarySearchTree 이진검색트리
앞전에 본 여러가지 트리 구조들에서는 언제나 노드의 데이터에는 어떠한 제한도 가하지 않았다.
그 결과 어떤 항목을 검색하려면, 왼쪽 서브트리와 오른쪽 서브 트리를 모두 검사해야하기 때문에 검색 연산의 최악의 경우애는 복잡도 O(n)인 상태였다.
이번에 배울 트리는 주 용도가 검색인 BST 이고, 어떤 노드가 가질 수 있는 데이터의 종류에 대하여
제한을 둘 것이므로, 검색 연산의 최악의 경우 복잡도가 
O(logn)이 된다. -> 사전에서 단어찾기 ( 이 페이지를 기준으로 /2, /2, /2 ... logn )


좋은 BST 가 되려면 skewed 트리가 되지 않도록 골고루 데이터가 순서대로 들어가도록 코딩해야한다.
( 즉, skew 트리는 BST의 나쁜 버전이 그렇게 표현되는것. skew 트리가 되는것을 피해야함 )

루트 데이터가 항상 왼쪽 서브 트리 데이터와 오른쪽 서브 트리 데이터 사이에 있기 때문에 
중위 탐색 (InOrder) 을 수행하면 정렬된 리스트가 만들어진다.

이진 검색 트리에 대한 문제를 풀 때 대부분의 경우, 왼쪽 서브 트리를 먼저 처리하고 
루트 데이터를 처리한 다음 와른쪽 서브 트리를 처리한다.

어떤 항목을 검색할 때 왼쪽 서브 트리의 데이터가 검색하는 항목보다 작으면 왼쪽 서브 트리 검색은 생략할 수 있다.
	오른쪽 서브트리에서도 비슷하다
	이 때문에 이진 검색 트리는 보통 이진 트리보다 검색에 걸리는 시간이 적다
	다른 말로 하면, 이진 검색 트리는 항목을 검색할 때 왼쪽 서브 트리나 오른쪽 서브트리중 한개만 
*/
#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode* left;
	struct BinarySearchTreeNode* right;

};

// 재귀적 방법
// 시간복잡도 : 최악의 경우(BST가 경사트리일때) O(n)     
// 공간복잡도 : 재귀적에 O(n)
//				함수 한번 call 할때마다 stack에 쌓이고 쌓이고 쌓이고 n번 call 하면 n 번 쌓이고
struct BinarySearchTreeNode* Find(struct BinarySearchTreeNode* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	if (data < root->data) {
		return Find(root->left, data);
	}
	else if (data > root->data) {
		return Find(root->right, data);
	}

	return root;
}


// 비재귀적 방법
// 시간복잡도 O(n)
// 공간복잡도 O(1) : parameter 2개 + while문 도는데 메모리는 따로 필요 X
struct BinarySearchTreeNode* Find(struct BinarySearchTreeNode* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	while (root) {
		if (data == root->data)
			return root;
		else if (data > root->data)
			root = root->right;
		else if (data < root->data)
			root = root->left;
	}

	return NULL;
}



// 이진 검색 트리에서 최소 항목 찾기
// BST 에서 최소 항목은 왼쪽 자식을 갖지 않은 제일 왼쪽 노드이다
// 재귀적 ver
// 시간복잡도 : 최악의 경우(BST가 왼쪽 경사트리일때) O(n)     
// 공간복잡도 : 재귀적 스택을 위해 O(n)
struct BinarySearchTreeNode* FindMin(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else
		return FindMin(root->left);
}


// 비재귀적 Iteration ver
// 시간복잡도 :  O(n)     // 트리의 깊이만큼 while 문 돌꺼임
// 공간복잡도 :  O(1)	 // FindMin 함수 한번 불러 
struct BinarySearchTreeNode* FindMin(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	while (root->left != NULL) {	// 트리의 깊이만큼 while 문 돌꺼임
		root = root->left;
	}
	return root;
}


// 이진 검색 트리에서 최대 항목 찾기
// BST 에서 최소 항목은 오른쪽 자식을 갖지 않은 제일 오른쪽 노드이다
// 재귀적 ver
// 시간복잡도 : 최악의 경우(BST가 오른쪽 경사트리일때) O(n)     
// 공간복잡도 : 재귀적 스택을 위해 O(n)    (스택에 한번뿐)
struct BinarySearchTreeNode* FindMax(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	else if (root->right == NULL)
		return root;
	else
		return FindMax(root->right);
}

// 비재귀적 Iteration ver
// 시간복잡도 :  O(n)     // 트리의 깊이만큼 while 문 돌꺼임
// 공간복잡도 :  O(1)	 // FindMax 함수 한번 불러 (스택에 한번뿐)
struct BinarySearchTreeNode* FindMax(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	while (root->right != NULL) {	// 트리의 깊이만큼 while 문 돌꺼임
		root = root->right;
	}
	return root;
}

/*
이진 검색 트리에 데이터를 삽입하려면 먼저 이 항목의 위치를 찾아야 한다.
	위치를 찾는 동안 데이터가 이미 존재한다면 무시하고 나오면 된다
	존재하지 않는 new데이터이면 탐색한 경로의 마지막 위치에 데이터를 추가한다.
*/

// 이진 검색트리에 항목 삽입하기	
// 시간복잡도 :  O(n)   
// 공간복잡도 :  재귀적 스택을 위해 O(n)	
struct BinarySearchTreeNode* Insert(struct BinarySearchTreeNode* root, int data) {
	if (root == NULL) {
		root = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
		if (root == NULL) {
			printf("Memory Error");
			return;
		}
		else {
			root->data = data;
			root->left = NULL;
			root->right = NULL;
		}
	}
	else {
		if (data < root->data)	root->left = Insert(root->left, data);
		else if (data > root->data)	root->right = Insert(root->right, data);
	}
	return root;
}


/* 이진 검색트리에 항목 삭제하기	( 복잡함 )
	이 연산 역시 먼저 삭제하기 원하는 항목의 위치를 찾아야 한다
	삭제할 노드 찾았으면 
		(1) 삭제할 항목이 리프노드라면 : NULL을 부모노드에게 리턴
		(2) 삭제할 항목이 한 개의 자식 노드를 가진다면 : 현재 노드의 자식을 부모노드에게 보낸다
		(3) 삭제할 항목이 두 개의 자식 노드를 가진다면 : 
		일반적인 전략은 이 노드의 키값을 왼쪽 서브 트리의 최대 항목과 바꾸고 
		재귀적으로 이젠 빈 상태인 기존의 노드를 삭제
		왼쪽 서브 트리의 최대 항목은 오른쪽 자식을 가질 수 없으므로 두번째 삭제는 쉽다
		참고 : 오른쪽 서브 트리의 최소 값과도 교체할 수 있다.

	시간복잡도 O(n)
	공간복잡도 : 재귀적방법에서는 O(n)		반복적방법에서는 O(1)
*/
struct BinarySearchTreeNode* Delete(struct BinarySearchTreeNode* root, int data) {
	struct BinarySearchTreeNode * temp;
	if (root == NULL)			printf("Element not there in tree");
	else if (data < root->data)	root->left = Delete(root->left, data);
	else if (data > root->data)	root->right = Delete(root->right, data);

	else {	// 항목을 찾았다. ( 여기서부터는 찾은항목을 교체하는 방법 : 즉 위에 코드들은 다 아직 못찾았을때임)
		if (root->left && root->right) {	// 둘다 1이면 자식노드 좌우노드 다 존재하면 이라는 소리
			/* 왼쪽 서브 트리의 최대 값과 교체한다 */
			temp = FindMax(root->left);
			root->data = temp->data;
			root->left = Delete(root->left, root->data);	// 지운 포인터를 다시 반환해야함 
		}
		else {
			/* 자식이 하나 또는 없는 경우*/
			temp = root;
			if (root->left == NULL) root = root->right;
			if (root->right == NULL) root = root->left;
			free(temp);
		}
	}
	return root;
}