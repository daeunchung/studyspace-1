#include <stdio.h>
#include <stdlib.h>
/*
BinarySearchTree �� ���� ���� O(logn) ���� �������� ����� ������ n�϶�
�ð� ���⵵ : �������� ġ��ģ ���Ʈ���� ���(linkedlist�� �ٸ��� ����) �־��� ��� O(n) �̴�.
����� ������ n���϶� : Ʈ�� ���� n => O(n),		���� log n => O(log n)
�̷��� ������ ���� �Ŀ� ���� ���Ǵ� Ʈ�� ������ BalancedBinarySearchTree �̴�.

�׷��ٸ� ������ ���ؼ� ���̰� n�� Ʈ���� ����� ���� �ʤ���? => �Ұ���
���� : �����Ͱ� �ԷµǴ� ������ ���� Ʈ���� �� ������� ����°��� �Ұ����ϴ�
		�׻� ������ (30 20 40 10 50 ������) �̷��� �ԷµǴ°͵� �ƴϱ� ���� 
		�ԷµǴ� ������ ���� ũ����̸� ( �������� or �������� ) ���Ʈ���� ���� �� �ۿ� ����

�������->
���̿� ������ ���Ͽ� �־��� ��� ���⵵�� O(logn)���� ���ҽ�Ŵ
�Ϲ������� ���� ���� Ʈ���� ������ ���� Ʈ���� ���� ���� k �� height balanced tree(���� ����Ʈ��) �� HB(k)�� ǥ��
k�� balance factor(���� ����)��� �Ҹ���

**** ���� ���� ���� �˻� Ʈ�� ****
HB(k)���� k == 0(balance factor�� 0�̶��)�̸�, �̷� ���� �˻� Ʈ���� ���� ���� ���� �˻� Ʈ�� ��� �Ѵ�.
��, HB(k) ���� �˻� Ʈ�������� ���� ���� Ʈ�� ���̿� ������ ���� Ʈ�� ������ ���̴� �ִ� 0�̾�� �Ѵٴ� ��.


k �� ������ �������� ������
k�� 0�� Ʈ���� ��尳���� �� �������� ����� ����

HB(k)���� k = 1�� �����˻�Ʈ���� AVL(Adelson-Velskii and Landis)Ʈ����� �Ѵ�.
-	�Ӽ�
	�����˻�Ʈ���̸鼭, � ��� X�� ���ؼ��� X�� ���� ���� Ʈ���� ���̿� ������ ���� Ʈ���� ���̰� �ִ� 1 �̴�
*/

// AVL Ʈ���� BST �̹Ƿ� AVL Ʈ���� ������ BST ����� ����������, ���⼭�� ������ ������������ ���̸� ���� �߰��ߴ�
struct AVLTreeNode {
	struct AVLTreeNode* left;
	int data;
	struct AVLTreeNode* right;
	int height;
};

// AVL Ʈ���� ���� ���ϱ�			�ð����⵵ O(1)
int Height(struct AVLTreeNode* root) {
	if (!root) return -1;
	else return root->height;
}

/*
Ʈ���� ������ ����, ���� ������ ����� �� AVL Ʈ���� �Ӽ��� �����Ϸ��� Ʈ���� �����ؾ� �Ѵ�.
 
�ܼ�ȸ��(single rotation) �̳� ����ȸ��(double rotation) �� ���� ����
����/���� ������ ��� �ϳ��� �߰�/�����ϴ� ���̹Ƿ� � ���� Ʈ���� ���̸� 1��ŭ ����/���� ��Ű�� ���
���� AVL Ʈ���� �Ӽ��� ��� X���� ����Ǿ��ٸ�, �̴� left(X)�� ���̿� right(X)�� ���� ���̰� ��Ȯ�� 2��� ���̴�
ȸ���� AVLƮ���� �Ӽ��� ȸ����Ű�� ���� ����̹Ƿ�, ���X�� ȸ���� �����Ͽ� Ʈ���� ������ ���� �ִ�.


���� ���� ���� ���� �������� ��Ʈ�� �̸��� ����� ������ ���� Ʈ���� ����Ǿ����Ƿ� �� ���鸸 ã���� �ȴ�.
 -	AVL Ʈ�� �Ӽ��� ȸ����Ű���� ���� �������� �����Ͽ� Ʈ���� ��Ʈ���� ��� ����
 -	��Ʈ�� ���� �̵��ϸ鼭 AVL �Ӽ��� ������Ű�� �ʴ� ù ��° ��尡 �������� �ľ�
 -	ù��° ����� ������ �����ϸ�, ��Ʈ �������� ��ο� �ִ� �ٸ� ������ �ڵ����� AVL Ʈ���� �Ӽ��� �����Ѵ�.
 �� �׻� ���� �������� ���� ��Ʈ������ ��� �߿� AVL Ʈ���� �Ӽ��� �������� �ʴ� ù ��° ������ ã�� �����ϸ� �ȴ�.
*/

/*
�ܼ�ȸ�� : LL, RR
����ȸ�� : LR, RL
*/


// LL ����ȸ��														�ð����⵵ O(1) �������⵵ O(1)
struct AVLTreeNode * SingleRotateLeft(struct AVLTreeNode* X) {
	struct AVLTreeNode* W = X->left;
	X->left = W->right; 
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;

	return W;	// �� ��Ʈ ���
}

// RR ����ȸ��														�ð����⵵ O(1) �������⵵ O(1)
struct AVLTreeNode * SingleRotateRight(struct AVLTreeNode* W) {
	struct AVLTreeNode* X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	X->height = max(Height(X->right), W->height) + 1;

	return X;	// �� ��Ʈ ���
}

// LR ����ȸ��
struct AVLTreeNode * DoubleRotatewithLeft(struct AVLTreeNode* Z) {
	Z->left = SingleRotateRight(Z);
	return SingleRotateLeft(Z);
}


// RL ����ȸ��
struct AVLTreeNode * DoubleRotatewithRight(struct AVLTreeNode* X) {
	X->right = SingleRotateLeft(X);
	return SingleRotateRight(X);
}


// AVL Ʈ���� ��� �����ϱ�									�ð����⵵O(log n) �������⵵ O(log n)
// BST�� �����ϴ� �Ͱ� �ſ� �����ϴ�. �׸��� ������ �Ŀ� ���� �ұ����� �߻��ߴ����� �߰��� �˻��ϸ� �ȴ�.
// �ұ����� �߻��ߴٸ� ������ ȸ�� �Լ��� ȣ���Ѵ�.
struct AVLTreeNode* Insert(struct AVLTreeNode * root, struct AVLTreeNode* parent, int data) {
	if (!root) {	// root �� ��������̸� �����ϴ� if��
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
	// �� �ܿ� �����Ͱ� Ʈ�� �ȿ� �̹� �ƹ��͵� ���Ѵ�.
	root->height = max(Height(root->left), Height(root->right)) + 1;
	return root;
}