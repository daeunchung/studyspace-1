#include <stdio.h>
#include <stdlib.h>
/*   배전위적 전위탐색
재귀방법에서는 왼쪽서브트리의 탐색이 끝났을때 , 오른쪽 서브 트리로 갈 수 있도록 현재 노드를 기억시킬 스택이 필요 없었다.
이를 재현하려면, 먼저 현재 노드를 처리한 뒤 왼쪽 서브 트리로 가기 전에 현재 노드를 스택에 저장한다.
왼쪽 서브 트리 처리가 끝난 뒤 항목을 찹해서 오른쪽 서브 트리로 이동한다. 이 과정을 스택이 비지 않는 동안 계속한다.
*/

// 전위탐색 ( PreOrder ) DLR

// Recursive 재귀 version
void PreOrder(struct BinaryTreeNode* root) {
	if (root) {
		printf("%d", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

// NonRecursive
void PreOrderNonRecursive(struct BinaryTreeNode* root) {
	struct Stack* S = CreateStack();	
	// static array (X), dynamic stack OR List (O)
	// 함수를 재귀하지는 않으나 메모리에 function call 하나하나를 기록해주는 call stack 이 필요하다


	while (1) {
		while (root) {
			// 현재 노드를 처리한다.
			printf("%d", root->data);
			Push(S, root);
			// 왼쪽 서브 트리가 존재하면 스택에 추가한다
			root = root->left;

		}
		if (IsEmptyStack(S))
			break;
		root = Pop(S);
		// 왼쪽 서브 트리와 현재 노드의 처리가 끝났으므로
		// 이제 오른쪽 서브 트리로 이동한다.
		root = root->right;
	}
	DeleteStack(S);
}





// 중위 탐색 ( InOrder ) LDR
void InOrder(struct BinaryTreeNode* root) {
	if (root) {
		InOrder(root->left);
		printf("%d", root->data);
		InOrder(root->right);
	}
}// 시간복잡도 O(n)  공간복잡도 O(n)

 // NonRecursive
void InOrderNonRecursive(struct BinaryTreeNode* root) {
	struct Stack* S = CreateStack();
	while (1) {
		while (root) {
			Push(S, root);	// 왼쪽 서브 트리를 찾았다.  스택에 계속 추가한다
			root = root->left;
		}
		if (IsEmptyStack(S))
			break;
		root = Pop(S);
		printf("%d", root->data);	// 팝한 뒤에 현재 노드를 처리한다.
		// 왼쪽 서브 트리와 현재 노드의 처리가 끝났으므로
		// 이제 오른쪽 서브 트리로 이동한다.
		root = root->right;
	}
	DeleteStack(S);
}






// 후위 탐색 ( PostOrder ) LRD
void PostOrder(struct BinaryTreeNode* root) {
	if (root) {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d", root->data);
	}
}

// NonRecursive
void PostOrderNonRecursive(struct BinaryTreeNode* root) {
	struct Stack* S = CreateStack();
	while (1) {
		if (root) {
			Push(S, root);	// 왼쪽 서브 트리를 찾았다.  스택에 계속 추가한다
			root = root->left;
		}
		else {
			if (IsEmptyStack(S)) {
				printf("Stack is empty");
				return;
			}
			else {
				if (Top(S)->right == NULL) {
					root = Pop(S);
					printf("%d", root->data);
					if (root == Top(S)->right) {
						printf("%d", Top(S)->data);
						Pop(S);
					}
				}
			}
			if (!IsEmptyStack(S)) root = Top(S)->right;
			else root = NULL;
		}
	}
	DeleteStack(S);
}




/*	레벨 순서 탐색	( 트리에 존재하지 않는 라인을 타고 탐색해야함 . 간선 따라 탐색 X )
루트 노드를 방문한다
레벨 l을 방문하는 동안 레벨 l+1 의 모든 항목을 큐에 저장한다
다음 레벨로 가서 그 레벨의 모든 노드를 방문한다

이 과정을 모든 레벨이 끝날때까지 반복한다
*/

void LevelOrder(struct BinaryTreeNode* root) {
	struct BinaryTreeNode* temp;
	struct Queue* Q = CreateQueue();
	if (!root) {
		return;
	}
	EnQueue(Q, root);
	while (!IsEmptyQueue(Q)) {
		temp = DeQueue(Q);
		// 현재 노드를 처리한다
		printf("%d", temp->data);
		if (temp->left) {
			EnQueue(Q, temp->left);
		}
		if (temp->right) {
			EnQueue(Q, temp->right);
		}
	}
	DeleteQueue(Q);
}

//시간복잡도 O(n)  공간복잡도 O(n/2)정도-> O(n)