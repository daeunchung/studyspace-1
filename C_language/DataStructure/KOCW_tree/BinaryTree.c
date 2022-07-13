#include <stdio.h>
#include <stdlib.h>
/*   �������� ����Ž��
��͹�������� ���ʼ���Ʈ���� Ž���� �������� , ������ ���� Ʈ���� �� �� �ֵ��� ���� ��带 ����ų ������ �ʿ� ������.
�̸� �����Ϸ���, ���� ���� ��带 ó���� �� ���� ���� Ʈ���� ���� ���� ���� ��带 ���ÿ� �����Ѵ�.
���� ���� Ʈ�� ó���� ���� �� �׸��� ���ؼ� ������ ���� Ʈ���� �̵��Ѵ�. �� ������ ������ ���� �ʴ� ���� ����Ѵ�.
*/

// ����Ž�� ( PreOrder ) DLR

// Recursive ��� version
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
	// �Լ��� ��������� ������ �޸𸮿� function call �ϳ��ϳ��� ������ִ� call stack �� �ʿ��ϴ�


	while (1) {
		while (root) {
			// ���� ��带 ó���Ѵ�.
			printf("%d", root->data);
			Push(S, root);
			// ���� ���� Ʈ���� �����ϸ� ���ÿ� �߰��Ѵ�
			root = root->left;

		}
		if (IsEmptyStack(S))
			break;
		root = Pop(S);
		// ���� ���� Ʈ���� ���� ����� ó���� �������Ƿ�
		// ���� ������ ���� Ʈ���� �̵��Ѵ�.
		root = root->right;
	}
	DeleteStack(S);
}





// ���� Ž�� ( InOrder ) LDR
void InOrder(struct BinaryTreeNode* root) {
	if (root) {
		InOrder(root->left);
		printf("%d", root->data);
		InOrder(root->right);
	}
}// �ð����⵵ O(n)  �������⵵ O(n)

 // NonRecursive
void InOrderNonRecursive(struct BinaryTreeNode* root) {
	struct Stack* S = CreateStack();
	while (1) {
		while (root) {
			Push(S, root);	// ���� ���� Ʈ���� ã�Ҵ�.  ���ÿ� ��� �߰��Ѵ�
			root = root->left;
		}
		if (IsEmptyStack(S))
			break;
		root = Pop(S);
		printf("%d", root->data);	// ���� �ڿ� ���� ��带 ó���Ѵ�.
		// ���� ���� Ʈ���� ���� ����� ó���� �������Ƿ�
		// ���� ������ ���� Ʈ���� �̵��Ѵ�.
		root = root->right;
	}
	DeleteStack(S);
}






// ���� Ž�� ( PostOrder ) LRD
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
			Push(S, root);	// ���� ���� Ʈ���� ã�Ҵ�.  ���ÿ� ��� �߰��Ѵ�
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




/*	���� ���� Ž��	( Ʈ���� �������� �ʴ� ������ Ÿ�� Ž���ؾ��� . ���� ���� Ž�� X )
��Ʈ ��带 �湮�Ѵ�
���� l�� �湮�ϴ� ���� ���� l+1 �� ��� �׸��� ť�� �����Ѵ�
���� ������ ���� �� ������ ��� ��带 �湮�Ѵ�

�� ������ ��� ������ ���������� �ݺ��Ѵ�
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
		// ���� ��带 ó���Ѵ�
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

//�ð����⵵ O(n)  �������⵵ O(n/2)����-> O(n)