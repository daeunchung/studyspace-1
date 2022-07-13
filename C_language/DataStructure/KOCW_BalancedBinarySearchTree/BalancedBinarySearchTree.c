#include <stdio.h>
#include <stdlib.h>
/*
BinarySearchTree 는 얼핏 보면 O(logn) 같아 보이지만 노드의 개수가 n일때
시간 복잡도 : 한쪽으로 치우친 경사트리일 경우(linkedlist랑 다를께 없음) 최악의 경우 O(n) 이다.
노드의 개수가 n개일때 : 트리 높이 n => O(n),		높이 log n => O(log n)
이러한 점들을 개선 후에 가장 상용되는 트리 구조는 BalancedBinarySearchTree 이다.

그렇다면 순서를 잘해서 높이가 n인 트리를 만들면 되지 않ㄴ냐? => 불가능
이유 : 데이터가 입력되는 순서에 따라서 트리를 내 마음대로 만드는것은 불가능하다
		항상 운좋게 (30 20 40 10 50 순으로) 이렇게 입력되는것도 아니기 때문 
		입력되는 데이터 순이 크기순이면 ( 오름차순 or 내림차순 ) 경사트리가 생길 수 밖에 없다

개선방법->
높이에 제한을 가하여 최악의 경우 복잡도를 O(logn)으로 감소시킴
일반적으로 왼쪽 서브 트리와 오른쪽 서브 트리의 높이 차가 k 인 height balanced tree(높이 균형트리) 를 HB(k)로 표현
k는 balance factor(균형 인자)라고 불린다

**** 완전 균형 이진 검색 트리 ****
HB(k)에서 k == 0(balance factor가 0이라면)이면, 이런 이진 검색 트리를 완전 균형 이진 검색 트리 라고 한다.
즉, HB(k) 이진 검색 트리에서는 왼쪽 서브 트리 높이와 오른쪽 서브 트리 높이의 차이는 최대 0이어야 한다는 것.


k 가 작으면 작을수록 좋은것
k가 0인 트리는 노드개수가 딱 떨어져야 만들수 있음

HB(k)에서 k = 1인 이진검색트리를 AVL(Adelson-Velskii and Landis)트리라고 한다.
-	속성
	이진검색트리이면서, 어떤 노드 X에 대해서도 X의 왼쪽 서브 트리의 높이와 오른쪽 서브 트리의 차이가 최대 1 이다
*/

// AVL 트리는 BST 이므로 AVL 트리의 선언은 BST 선언과 유사하지만, 여기서는 연산이 간단해지도록 높이를 선언에 추가했다
struct AVLTreeNode {
	struct AVLTreeNode* left;
	int data;
	struct AVLTreeNode* right;
	int height;
};

// AVL 트리의 높이 구하기			시간복잡도 O(1)
int Height(struct AVLTreeNode* root) {
	if (!root) return -1;
	else return root->height;
}

/*
트리의 구조가 삽입, 삭제 등으로 변경될 때 AVL 트리의 속성을 유지하려면 트리를 수정해야 한다.
 
단순회전(single rotation) 이나 이중회전(double rotation) 에 의해 수행
삽입/삭제 연산이 노드 하나를 추가/삭제하는 것이므로 어떤 서브 트리의 높이를 1만큼 증가/감소 시키는 방식
만일 AVL 트리의 속성이 노드 X에서 위배되었다면, 이는 left(X)의 높이와 right(X)의 높이 차이가 정확히 2라는 뜻이다
회전은 AVL트리의 속성을 회복시키기 위한 기법이므로, 노드X에 회전을 적용하여 트리를 수정할 수ㅌ 있다.


삽입 연산 이후 삽입 지점부터 루트에 이르는 경로의 노드들의 서브 트리만 변경되었으므로 이 노드들만 찾으면 된다.
 -	AVL 트리 속성을 회복시키려면 삽입 지점에서 시작하여 트리의 루트까지 계속 변경
 -	루트를 향해 이동하면서 AVL 속성을 만족시키지 않는 첫 번째 노드가 무엇인지 파악
 -	첫번째 노드의 문제를 수정하면, 루트 노드까지의 경로에 있는 다른 노드들은 자동으로 AVL 트리의 속성을 만족한다.
 작 항상 삽입 지점으로 부터 루트까지의 경로 중에 AVL 트리의 속성을 만족하지 않는 첫 번째 노드부터 찾아 수정하면 된다.
*/

/*
단순회전 : LL, RR
이중회전 : LR, RL
*/


// LL 단일회전														시간복잡도 O(1) 공간복잡도 O(1)
struct AVLTreeNode * SingleRotateLeft(struct AVLTreeNode* X) {
	struct AVLTreeNode* W = X->left;
	X->left = W->right; 
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;

	return W;	// 새 루트 노드
}

// RR 단일회전														시간복잡도 O(1) 공간복잡도 O(1)
struct AVLTreeNode * SingleRotateRight(struct AVLTreeNode* W) {
	struct AVLTreeNode* X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	X->height = max(Height(X->right), W->height) + 1;

	return X;	// 새 루트 노드
}

// LR 이중회전
struct AVLTreeNode * DoubleRotatewithLeft(struct AVLTreeNode* Z) {
	Z->left = SingleRotateRight(Z);
	return SingleRotateLeft(Z);
}


// RL 이중회전
struct AVLTreeNode * DoubleRotatewithRight(struct AVLTreeNode* X) {
	X->right = SingleRotateLeft(X);
	return SingleRotateRight(X);
}


// AVL 트리에 노드 삽입하기									시간복잡도O(log n) 공간복잡도 O(log n)
// BST에 삽입하는 것과 매우 유사하다. 항목을 삽입한 후에 높이 불균형이 발생했는지만 추가로 검사하면 된다.
// 불균형이 발생했다면 적절한 회전 함수를 호출한다.
struct AVLTreeNode* Insert(struct AVLTreeNode * root, struct AVLTreeNode* parent, int data) {
	if (!root) {	// root 가 리프노드이면 수행하는 if문
		root = (struct AVLTreeNode*)malloc(sizeof(struct AVLTreeNode*));
		if (!root) {
			printf("Memory Error");
			return;
		}
		else {
			root->data = data;
			root->height = 0;
			root->left = NULL;
			root->right = NULL;
		}
	}


	else if(data < root->data) {
		root->left = Insert(root->left, root, data);
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (data < root->data)
				root = SingleRotateLeft(root);					// LL
			else
				root = DoubleRotatewithLeft(root);				// LR
		}
	}
	else if (data > root->data) {
		root->right = Insert(root->right, root, data);
		if ((Height(root->right) - Height(root->left)) == 2) {
			if (data > root->right->data)
				root = SingleRotateRight(root);					// RR
			else
				root = DoubleRotatewithRight(root);				// RL
		}
	}
	// 이 외에 데이터가 트리 안에 이미 아무것도 안한다.
	root->height = max(Height(root->left), Height(root->right)) + 1;
	return root;
}